#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QInputDialog>
#include <QSerialPortInfo>
#include <QSerialPort>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    settings_enabled(false)
{
    ui->setupUi(this);

    this->serialPortListDlg = new SerialPortList;
    this->serialPortListDlg->hide();

    this->sl_projector    = new PjLink(this->ui->txtProj1Addr->text(), 4352, "panasonic");
    this->front_projector = new PjLink(this->ui->txtProj2Addr->text(), 4352, "panasonic");
    this->sr_projector    = new PjLink(this->ui->txtProj3Addr->text(), 4352, "panasonic");
    this->rear_projector  = new PjLink(this->ui->txtProj4Addr->text(), 4352, "panasonic");

    this->SimpleMode();
    this->showHideSettings(false);

    QList<QSerialPortInfo> serialPortInfoList = QSerialPortInfo::availablePorts();

    foreach (const QSerialPortInfo &serialPortInfo, serialPortInfoList)
    {
        ui->cmbScrn1ComPort->addItem(serialPortInfo.portName());
        ui->cmbScrn2ComPort->addItem(serialPortInfo.portName());
        ui->cmbScrn3ComPort->addItem(serialPortInfo.portName());
        ui->cmbScrn4ComPort->addItem(serialPortInfo.portName());
    }

    FRComPort  .setPortName( ui -> cmbScrn2ComPort -> currentText() );
    RearComPort.setPortName( ui -> cmbScrn4ComPort -> currentText() );
    SRComPort  .setPortName( ui -> cmbScrn1ComPort -> currentText() );
    SLComPort  .setPortName( ui -> cmbScrn2ComPort -> currentText() );

    FRComPort  .setBaudRate(QSerialPort::Baud2400);
    RearComPort.setBaudRate(QSerialPort::Baud2400);
    SRComPort  .setBaudRate(QSerialPort::Baud2400);
    SLComPort  .setBaudRate(QSerialPort::Baud2400);


    FRComPort  .setStopBits(QSerialPort::StopBits::OneStop);
    RearComPort.setStopBits(QSerialPort::StopBits::OneStop);
    SRComPort  .setStopBits(QSerialPort::StopBits::OneStop);
    SLComPort  .setStopBits(QSerialPort::StopBits::OneStop);

    FRComPort  .setDataBits(QSerialPort::DataBits::Data8);
    RearComPort.setDataBits(QSerialPort::DataBits::Data8);
    SRComPort  .setDataBits(QSerialPort::DataBits::Data8);
    SLComPort  .setDataBits(QSerialPort::DataBits::Data8);

    FRComPort  .open(QSerialPort::WriteOnly);
    RearComPort.open(QSerialPort::WriteOnly);
    SRComPort  .open(QSerialPort::WriteOnly);
    SLComPort  .open(QSerialPort::WriteOnly);

    connect( &tmr_get_P1_status, SIGNAL(timeout()), this, SLOT(update_P1_status_label()) );
    connect( &tmr_get_P2_status, SIGNAL(timeout()), this, SLOT(update_P2_status_label()) );
    connect( &tmr_get_P3_status, SIGNAL(timeout()), this, SLOT(update_P3_status_label()) );
    connect( &tmr_get_P4_status, SIGNAL(timeout()), this, SLOT(update_P4_status_label()) );

    this->tmr_get_P1_status.start(10000);
    this->tmr_get_P2_status.start(10000);
    this->tmr_get_P3_status.start(10000);
    this->tmr_get_P4_status.start(10000);

    connect(this->ui->txtProj1Addr, SIGNAL(editingFinished()), this->sr_projector,    SLOT(update_address()));
    connect(this->ui->txtProj2Addr, SIGNAL(editingFinished()), this->front_projector, SLOT(update_address()));
    connect(this->ui->txtProj3Addr, SIGNAL(editingFinished()), this->sl_projector,    SLOT(update_address()));
    connect(this->ui->txtProj4Addr, SIGNAL(editingFinished()), this->rear_projector,  SLOT(update_address()));

    connect(this->sr_projector,    SIGNAL(friendly_status_update(QString)), this->ui->lblStatus1, SLOT(setText(QString)));
    connect(this->front_projector, SIGNAL(friendly_status_update(QString)), this->ui->lblStatus2, SLOT(setText(QString)));
    connect(this->sl_projector,    SIGNAL(friendly_status_update(QString)), this->ui->lblStatus3, SLOT(setText(QString)));
    connect(this->rear_projector,  SIGNAL(friendly_status_update(QString)), this->ui->lblStatus4, SLOT(setText(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_cmbMode_currentIndexChanged(const QString &arg1)
{
    if (arg1 == "Simple Mode") {
        this->SimpleMode();
    } else {
        this->AdvancedMode();
    }
}

void MainWindow::SimpleMode()
{
    this->ui->cmbProj1->hide();
    this->ui->cmbProj2->hide();
    this->ui->cmbProj3->hide();
    this->ui->cmbProj4->hide();
    this->ui->btnMinimize->hide();

}

void MainWindow::AdvancedMode()
{
    this->ui->cmbProj1->show();
    this->ui->cmbProj2->show();
    this->ui->cmbProj3->show();
    this->ui->cmbProj4->show();
    this->ui->btnMinimize->show();
}

void MainWindow::on_btnSettings_clicked()
{
    bool ok = false;

    if (! this->settings_enabled)
    {
        QString text = QInputDialog::getText(this, "Password", "Please enter password", QLineEdit::Password, "", &ok);

        if (ok && !text.isEmpty())
        {
            if (text == "1941")
            {
                this->settings_enabled = true;

                this->showHideSettings(true);
                return;
            }
            QMessageBox::information(this, "incorrect password", "Please try again");
        }
    } else {
        this->settings_enabled = false;
        this->showHideSettings(false);
    }
}

void MainWindow::showHideSettings(bool show)
{
    this->ui->lblProj1Addr    ->setVisible(show); this->ui->txtProj1Addr    ->setVisible(show);
    this->ui->lblProj2Addr    ->setVisible(show); this->ui->txtProj2Addr    ->setVisible(show);
    this->ui->lblProj3Addr    ->setVisible(show); this->ui->txtProj3Addr    ->setVisible(show);
    this->ui->lblProj4Addr    ->setVisible(show); this->ui->txtProj4Addr    ->setVisible(show);

    this->ui->lblProj1Port    ->setVisible(show); this->ui->txtProj1Port    ->setVisible(show);
    this->ui->lblProj2Port    ->setVisible(show); this->ui->txtProj2Port    ->setVisible(show);
    this->ui->lblProj3Port    ->setVisible(show); this->ui->txtProj3Port    ->setVisible(show);
    this->ui->lblProj4Port    ->setVisible(show); this->ui->txtProj4Port    ->setVisible(show);

    this->ui->lblScrn1CodeUp  ->setVisible(show); this->ui->txtScrn1CodeUp  ->setVisible(show);
    this->ui->lblScrn2CodeUp  ->setVisible(show); this->ui->txtScrn2CodeUp  ->setVisible(show);
    this->ui->lblScrn3CodeUp  ->setVisible(show); this->ui->txtScrn3CodeUp  ->setVisible(show);
    this->ui->lblScrn4CodeUp  ->setVisible(show); this->ui->txtScrn4CodeUp  ->setVisible(show);

    this->ui->lblScrn1CodeDown->setVisible(show); this->ui->txtScrn1CodeDown->setVisible(show);
    this->ui->lblScrn2CodeDown->setVisible(show); this->ui->txtScrn2CodeDown->setVisible(show);
    this->ui->lblScrn3CodeDown->setVisible(show); this->ui->txtScrn3CodeDown->setVisible(show);
    this->ui->lblScrn4CodeDown->setVisible(show); this->ui->txtScrn4CodeDown->setVisible(show);

    this->ui->lblScrn1CodeStop->setVisible(show); this->ui->txtScrn1CodeStop->setVisible(show);
    this->ui->lblScrn2CodeStop->setVisible(show); this->ui->txtScrn2CodeStop->setVisible(show);
    this->ui->lblScrn3CodeStop->setVisible(show); this->ui->txtScrn3CodeStop->setVisible(show);
    this->ui->lblScrn4CodeStop->setVisible(show); this->ui->txtScrn4CodeStop->setVisible(show);

    this->ui->lblScrn1Time    ->setVisible(show); this->ui->sbScrn1Time     ->setVisible(show);
    this->ui->lblScrn2Time    ->setVisible(show); this->ui->sbScrn2Time     ->setVisible(show);
    this->ui->lblScrn3Time    ->setVisible(show); this->ui->sbScrn3Time     ->setVisible(show);
    this->ui->lblScrn4Time    ->setVisible(show); this->ui->sbScrn4Time     ->setVisible(show);

    this->ui->lblScrn1ComPort ->setVisible(show); this->ui->cmbScrn1ComPort ->setVisible(show);
    this->ui->lblScrn2ComPort ->setVisible(show); this->ui->cmbScrn2ComPort ->setVisible(show);
    this->ui->lblScrn3ComPort ->setVisible(show); this->ui->cmbScrn3ComPort ->setVisible(show);
    this->ui->lblScrn4ComPort ->setVisible(show); this->ui->cmbScrn4ComPort ->setVisible(show);
}

void MainWindow::on_btnMinimize_clicked()
{
    this->showMinimized();
}


void MainWindow::update_P1_status_label()
{
}

void MainWindow::update_P2_status_label()
{
}

void MainWindow::update_P3_status_label()
{
}

void MainWindow::update_P4_status_label()
{
}



void MainWindow::on_btnSrcPC_clicked()
{
    ui->cmbProj1->setCurrentIndex(0);
    ui->cmbProj2->setCurrentIndex(0);
    ui->cmbProj3->setCurrentIndex(0);
    ui->cmbProj4->setCurrentIndex(0);
}

void MainWindow::on_btnSrcLaptop_clicked()
{
    ui->cmbProj1->setCurrentIndex(1);
    ui->cmbProj2->setCurrentIndex(1);
    ui->cmbProj3->setCurrentIndex(1);
    ui->cmbProj4->setCurrentIndex(1);
}


void MainWindow::on_btnProj1On_clicked()
{
// Screen
    QByteArray ba;

    QList<QString> l = this->ui->txtScrn1CodeDown->text().split(" ");

    foreach (QString n, l) {        ba.append(n.toInt(0, 16));    }

    this->FRComPort.write(ba);

// Projector
    this->sr_projector->power_on();
}

void MainWindow::on_btnProj2On_clicked()
{
// Screen
    QByteArray ba;

    QList<QString> l = this->ui->txtScrn2CodeDown->text().split(" ");

    foreach (QString n, l) {      ba.append(n.toInt(0, 16));    }

    this->FRComPort.write(ba);

// Projector
    this->front_projector->power_on();
}

void MainWindow::on_btnProj3On_clicked()
{
// Screen
    QByteArray ba;

    QList<QString> l = this->ui->txtScrn3CodeDown->text().split(" ");

    foreach (QString n, l) {      ba.append(n.toInt(0, 16));    }

    this->FRComPort.write(ba);

// Projector
    this->sl_projector->power_on();
}

void MainWindow::on_btnProj4On_clicked()
{
// Screen
    QByteArray ba;

    QList<QString> l = this->ui->txtScrn4CodeDown->text().split(" ");

    foreach (QString n, l) {        ba.append(n.toInt(0, 16));    }

    this->FRComPort.write(ba);

// Projector
    this->rear_projector->power_on();
}

void MainWindow::on_btnProj1Off_clicked()
{
// Screen
    QByteArray ba;

    QList<QString> l = this->ui->txtScrn1CodeUp->text().split(" ");

    foreach (QString n, l) {        ba.append(n.toInt(0, 16));    }

    this->FRComPort.write(ba);

// Projector
    this->sr_projector->power_off();
}

void MainWindow::on_btnProj2Off_clicked()
{
    QByteArray ba;

    QList<QString> l = this->ui->txtScrn2CodeUp->text().split(" ");

    foreach (QString n, l) {        ba.append(n.toInt(0, 16));    }

    this->FRComPort.write(ba);
}

void MainWindow::on_btnProj3Off_clicked()
{
    QByteArray ba;

    QList<QString> l = this->ui->txtScrn3CodeUp->text().split(" ");

    foreach (QString n, l) {        ba.append(n.toInt(0, 16));    }

    this->FRComPort.write(ba);
}

void MainWindow::on_btnProj4Off_clicked()
{
    QByteArray ba;

    QList<QString> l = this->ui->txtScrn4CodeUp->text().split(" ");

    foreach (QString n, l) {        ba.append(n.toInt(0, 16));    }

    this->FRComPort.write(ba);
}

void MainWindow::on_cbFullscreen_toggled(bool checked)
{
    if (checked) {
        this->showFullScreen();
    } else  {
        this->showNormal();
    }
}

void MainWindow::on_btnSerialSettings_clicked()
{
    this->serialPortListDlg->show();
}
