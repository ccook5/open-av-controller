#include "pjlink.h"

#include "log.h"

#include <QCryptographicHash>
#include <QLineEdit>


PjLink::PjLink(QString address, int port, QByteArray password)
    : tcpSocket(new QTcpSocket(this))
{
    this->address   = address;
    this->port      = port;
    this->password  = password;
    this->poll_time = 3; // seconds

    this->cmd_queue.empty();

    this->waiting_for_reply          = false;
    this->waiting_for_authentication = false;
    this->authenticated              = false;

    connect(this->tcpSocket, SIGNAL(disconnected()), this, SLOT(disconnect_from_host()));
    connect(this->tcpSocket, SIGNAL(   readyRead()), this, SLOT(           readyRead()));

    this->poll_timer = new QTimer();
    this->poll_timer->setInterval(this->poll_time * 1000);
    connect(this->poll_timer, SIGNAL(timeout()), this, SLOT(poll_loop()));
    this->poll_timer->start();

    this->process_timer = new QTimer();
    this->process_timer->setInterval(250); // 0.25 seconds
    connect(this->process_timer, SIGNAL(timeout()), this, SLOT(process_loop()));
    this->process_timer->start();

    this->poll_loop();
}


PjLink::~PjLink()
{
    if (this->poll_timer) {
        disconnect(this->poll_timer, 0, 0, 0);

        delete this->poll_timer;
        this->poll_timer = 0;
    }
}


void PjLink::update_address()
{
    this->address = dynamic_cast<QLineEdit*>(sender())->text();
    this->reset_connection();
}

void PjLink::poll_loop()
{
    this->cmd_queue.enqueue("POWR ?");
}

void PjLink::process_loop()
{
    if (! this->cmd_queue.isEmpty())
    {
        if (tcpSocket->state() == QAbstractSocket::UnconnectedState) {

            tcpSocket->connectToHost(this->address, this->port);
            this->session_timer->singleShot(30000, this, SLOT(reset_connection()));
        } else if (tcpSocket->state() != QAbstractSocket::ConnectedState) {
            this->cmd_queue.clear();
            return;
        }

        if (this->tcpSocket->state() == QAbstractSocket::ConnectedState) {
            send_command(this->cmd_queue.dequeue());
        }
    } else {
//        tcpSocket->disconnectFromHost();
    }
}


void PjLink::readyRead()
{
    QString data = this->tcpSocket->readAll();

    if (data.startsWith("PJLINK")) { // authentication

        if (data.split(' ')[1] == "1") {
            this->authenticated = false;
            this->random_no = data.split(' ')[2].toLocal8Bit();

        } else if (data.split(' ')[1] == "0") {
            this->authenticated = true;
            return;
        } else {
            this->reset_connection();
            log::error(QString("Error authenticating : ") + data);
        }
        return;
    }

    if (data.startsWith("%1")) { // valid response
        if (this->authenticated == false) {
            this->authenticated = true;
        }

        this->process_response(data.mid(2));

        return;
    }

    log::error(QString("Invalid response: ") + data);
}


void PjLink::send_command   (QString cmd)
{
    QByteArray cmd_string;

    if (this->authenticated == false) {
        QByteArray msg = this->random_no.simplified()+this->password.simplified();

        cmd_string += QCryptographicHash::hash(msg, QCryptographicHash::Md5).toHex();
    }

    cmd_string += "%1";
    cmd_string += cmd.toLocal8Bit();
    cmd_string += '\r';

    tcpSocket->write(cmd_string);
}

void PjLink::reset_connection()
{
    tcpSocket->disconnectFromHost();
    this->random_no = "";
    this->authenticated = false;
}


void PjLink::disconnect_from_host()
{
    this->random_no = "";
    this->authenticated = false;
}


void PjLink::process_response(QString data)
{
    QStringList cmd_split = data.split('=');
    QString cmd = cmd_split[0].toUpper();
    QString data1 = cmd_split[1].simplified();
    bool ok = false;


    if (data1 == "OK") {
        qDebug() << "Projector Response: OK";
        emit friendly_status_update("Ok");
    } else if (data1 == "ERR1") {
        qDebug() << "Projector Response: ERROR - Undefined Command / Command not supported";
        emit friendly_status_update("Error - Command not supported");
    } else if (data1 == "ERR2") {
        qDebug() << "Projector Response: ERROR - Out of Parameter";
        emit friendly_status_update("Error - Out of Parameter");
    } else if (data1 == "ERR3") {
        qDebug() << "Projector Response: ERROR - Projector Busy (PJLink - Unavailable time)";
        emit friendly_status_update("Error - Projojector Busy");
    } else if (data1 == "ERR4") {
        qDebug() << "Projector Response: ERROR - Projector/Display failure";
        emit friendly_status_update("Projector failure");
    } else if (data1 == "ERRA") {
        qDebug() << "Projector Response: OK";
        emit friendly_status_update("Ok");
    }

    if (cmd.startsWith("POWR")) {
        qDebug() << data1;
        this->power = data1.toInt(&ok);

        if (ok) {
            switch (this->power) {
            case 0:
                emit friendly_status_update("Standby");
                break;
            case 1:
                emit friendly_status_update("Power On");
                break;
            case 2:
                emit friendly_status_update("Cooling down...");
                break;
            case 3:
                emit friendly_status_update("Warming Up...");
                break;
            default:
                emit friendly_status_update(QString("Unknown response: ") + this->power);
                break;
            }
        }
    }
}

void PjLink::power_on()
{
    this->cmd_queue.enqueue("POWR 1");
}

void PjLink::power_off()
{
    this->cmd_queue.enqueue("POWR 0");
}
