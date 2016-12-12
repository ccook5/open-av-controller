#include "projector.h"

#include <QByteArray>
#include <QCryptographicHash>
#include <QMessageBox>

projector::projector(QObject* parent, QString address, int port)
    : QObject(parent), address( address), port (port)
{
    connect(&socket, SIGNAL(readyRead()), this, SLOT( data_back() ) );

    this->update = new QTimer();

    connect( this->update, SIGNAL(timeout()), this, SLOT(update_status()) );

    this->update->start(1200);
}


projector::~projector()
{
}


void projector::ExecuteCmd(QByteArray cmd)
{
    qDebug() << "projector::ExecuteCmd() : " << cmd;

    qDebug() << this->address << this->port;

    if (this->socket.state() == QAbstractSocket::UnconnectedState)
    {
        this->socket.connectToHost(this->address, this->port);
    }


    if (this->socket.state() == QAbstractSocket::ConnectedState)
    {
        qDebug() << "p::EC() : writing - " << cmd;
        this->socket.write(this->digest + cmd);
    }
}


QString statusFromInt(char i)
{
    switch (i) {
    case '0': return QString("Ok");      break;
    case '1': return QString("Warning"); break;
    case '2': return QString("Error");   break;
    default:  return QString("Unknown"); break;
    }
}

QString projector::data_back()
{
    qDebug() << "projector::data_back()";
    if (! this->socket.bytesAvailable()) {
        return QString();
    }

    QByteArray data = this->socket.readAll();

    if (data.startsWith("PJLINK"))
    {
        qDebug() << "do authentication...";

        if (data.split(' ')[1] == QString('1'))
        {
            QByteArray rndNum = data.split(' ')[2].left(8); // lose the \r on the end.
            this->digest = QCryptographicHash::hash(rndNum.append(this->password), QCryptographicHash::Md5).toHex();

            qDebug() << data.split(' ')[2].left(8);
            qDebug() << this->password;
            qDebug() << this->digest;

            return QString(); // We should be authenticated if the password was correct.

        } else if (data.split(' ')[1] == QString('0')) {
            // no authentication
            qDebug() << "no authentication";
            return QString();
        } else if (data.split(' ')[1] == QString("ERRA")) {
            qDebug() << "Error Authenticating";
        }
    }

    if (data[0] != '%')
    {
        qDebug() << "Invalid packet";
    }

    QByteArray cmd = data.mid(2, 4);
    QByteArray var_data = data.mid(7, data.indexOf('\r'));

    if (data == "projector ERRA\r") {
        return "Invalid password";
    }
    if (data[6] == '=') {

        if ((data.length() > 12) && (data.mid(7, 3) == "ERR") )
        {
            switch (data[10]) {
                case '1': return "Undefined cmd";             break;
                case '2': return "Out of Parameter";          break;
                case '3': return "Unavailable Time";          break;
                case '4': return "Projector/Display Failure"; break;
                case 'A': return ""; break;
            }
        }

        if (cmd == "POWR")
        {
            switch (var_data[0]) {
                case '0': return QString("Standby");       break;
                case '1': return QString("On");            break;
                case '2': return QString("Cooling Down");  break;
                case '3': return QString("Warming Up");    break;
                case 'O': return QString("Ok");            break;
            }
        } else if (cmd == "ERST") {
            QString response;

            response += QString("Fan ")    + statusFromInt(var_data[0]) + QString(", ");
            response += QString("Lamp ")   + statusFromInt(var_data[1]) + QString(", ");
            response += QString("Temp ")   + statusFromInt(var_data[2]) + QString(", ");
            response += QString("Cover ")  + statusFromInt(var_data[3]) + QString(", ");
            response += QString("Filter ") + statusFromInt(var_data[4]) + QString(", ");
            response += QString("Other ")  + statusFromInt(var_data[5]) + QString(".");

            return response;
        } else if (cmd == "LAMP") {
            QString response;
            int count = 1;

            QList<QByteArray> lamp_data = var_data.split(' ');

            while (! lamp_data.empty()) {
                response = response.append("Lamp %1 : ").arg(count);

                response = response.append(lamp_data[0]).append(" hours, ");

                     if (lamp_data[1].toInt() == 1)        response = response.append("On : ");
                else if (lamp_data[1].toInt() == 0)        response = response.append("Off : ");
                else                                       response = response.append(lamp_data[1]);

                count = count + 1;
                lamp_data.removeFirst();
                lamp_data.removeFirst();
            }

            return response;
        } else if (cmd == "INF1") {            return var_data;
        } else if (cmd == "INF2") {            return var_data;
        } else if (cmd == "NAME") {            return var_data;
        } else {
            qDebug() << "Unknown response:" << data;
        }
        return data;

    } else {
        return "Unknown response";
    }
}



void projector::setPassword(QString password)
{
    this->password = password.toLocal8Bit();
}

void projector::update_status() {}



QString        projector::get_status() {    return "";    }

void        projector::change_status(QString msg) {  }

// projector commands

void projector::get_power_status    () {    this->ExecuteCmd("%1POWR ?\r");    }

void projector::get_input_source    () {    this->ExecuteCmd("%1INPT ?\r");    }

void projector::get_available_inputs() {    this->ExecuteCmd("%1INST ?\r");    }


/** true = shutter closed - no output
 * false = shutter open   */
void projector::get_shutter_status  () {    this->ExecuteCmd("%1 ?\r");     }


bool projector::get_audio_mute_status() {    return false;     }


void projector::get_error_status     () {    this->ExecuteCmd("%1ERST ?\r");   }
void projector::get_lamp_status      () {    this->ExecuteCmd("%1LAMP ?\r");   }

void projector::get_manufacturer     () {    this->ExecuteCmd("%1INF1 ?\r");   }
void projector::get_model            () {    this->ExecuteCmd("%1INF2 ?\r");   }
void projector::get_name             () {    this->ExecuteCmd("%1NAME ?\r");   }
void projector::get_other_info       () {    this->ExecuteCmd("%1INFO ?\r");   }
void projector::get_class            () {    this->ExecuteCmd("%1CLSS ?\r");   }


/////////////////////////////////////////////////////////////////////////////
//projector info requests
void projector::set_power_on         () {    this->ExecuteCmd("%1POWR 1\r");     }
void projector::set_power_off        () {    this->ExecuteCmd("%1POWR 0\r");     }

void projector::set_input_source    (QString src) { }

void projector::set_shutter_closed  () { }
void projector::set_shutter_open    () { }

void projector::set_audio_muted     () { }
void projector::set_audio_unmuted   () { }

