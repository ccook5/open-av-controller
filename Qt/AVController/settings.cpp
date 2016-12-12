#include "settings.h"
#include "ui_settings.h"

#include "pjlink.h"
#include "MainWindow.h"

#include <QByteArray>
#include <QMessageBox>
#include <QSerialPortInfo>
#include <QSerialPort>

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    serialPortListDlg = new SerialPortList;
    serialPortListDlg->hide();

    QList<QSerialPortInfo> serialPortInfoList = QSerialPortInfo::availablePorts();

    foreach (const QSerialPortInfo &serialPortInfo, serialPortInfoList)
    {
        ui->Proj1ComPort->addItem(serialPortInfo.portName());
        ui->Proj2ComPort->addItem(serialPortInfo.portName());
        ui->Proj3ComPort->addItem(serialPortInfo.portName());
        ui->Proj4ComPort->addItem(serialPortInfo.portName());
    }

    FRComPort  .setPortName( ui -> Proj2ComPort -> currentText() );
    RearComPort.setPortName( ui -> Proj4ComPort -> currentText() );
    SRComPort  .setPortName( ui -> Proj1ComPort -> currentText() );
    SLComPort  .setPortName( ui -> Proj2ComPort -> currentText() );

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
}

Settings::~Settings()
{
    delete ui;
}

QString Settings::Proj1ScreenDownCode() {    return this->ui->Proj1ScreenDownCode->text();   }

QString Settings::Proj2ScreenDownCode() {    return this->ui->Proj2ScreenDownCode->text();   }

QString Settings::Proj3ScreenDownCode() {    return this->ui->Proj3ScreenDownCode->text();   }

QString Settings::Proj4ScreenDownCode() {    return this->ui->Proj4ScreenDownCode->text();   }

QString Settings::Proj1ScreenUpCode()   {    return this->ui->Proj1ScreenUpCode->text();   }

QString Settings::Proj2ScreenUpCode()   {    return this->ui->Proj2ScreenUpCode->text();   }

QString Settings::Proj3ScreenUpCode()   {    return this->ui->Proj3ScreenUpCode->text();   }

QString Settings::Proj4ScreenUpCode()   {    return this->ui->Proj4ScreenUpCode->text();   }

void Settings::on_cmbMode_currentIndexChanged(int index)
{

    if (index == 0) {
        dynamic_cast<MainWindow*>(this->parent())->SimpleMode();
    } else {
        dynamic_cast<MainWindow*>(this->parent())->AdvancedMode();

    }
}

void Settings::on_cbFullscreen_toggled(bool checked)
{
    if (checked) {
        dynamic_cast<QWidget*>(this->parent())->showFullScreen();
    } else  {
        dynamic_cast<QWidget*>(this->parent())->showNormal();

    }
}
