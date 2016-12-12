#include "mainwindow.h"
#include "settings.h"
#include "ui_mainwindow.h"


#include <QByteArray>
#include <QMessageBox>
#include <QSerialPortInfo>
#include <QSerialPort>
#include <QMessageBox>

#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QAbstractSocket>
#include <QStack>
#include <QThread>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);    

    this->SerialPortInfo.hide();

    QList<QSerialPortInfo> serialPortInfoList = QSerialPortInfo::availablePorts();

    foreach (const QSerialPortInfo &serialPortInfo, serialPortInfoList)
    {
        ui->cbScrComPortFR->addItem(serialPortInfo.portName());
        ui->cbScrComPortRR->addItem(serialPortInfo.portName());
        ui->cbScrComPortSL->addItem(serialPortInfo.portName());
        ui->cbScrComPortSR->addItem(serialPortInfo.portName());
    }

    FRComPort  .setPortName( ui -> cbScrComPortFR -> currentText() );
    RearComPort.setPortName( ui -> cbScrComPortRR -> currentText() );
    SRComPort  .setPortName( ui -> cbScrComPortSL -> currentText() );
    SLComPort  .setPortName( ui -> cbScrComPortSR -> currentText() );

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

    this->projectors["front"] = new projector(this, this->ui->editProjAddrFR->text());
    this->projectors["rear"]  = new projector(this, this->ui->editProjAddrRR->text());
    this->projectors["sr"]    = new projector(this, this->ui->editProjAddrSR->text());
    this->projectors["sl"]    = new projector(this, this->ui->editProjAddrSL->text());

    this->projectors["sl"]   ->setPassword(this->ui->editProjPasswordSL->text());
    this->projectors["sr"]   ->setPassword(this->ui->editProjPasswordSR->text());
    this->projectors["front"]->setPassword(this->ui->editProjPasswordFR->text());
    this->projectors["rear"] ->setPassword(this->ui->editProjPasswordRR->text());

    this->ui->btnSettings->click();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnSettings_clicked()
{
    if (this->ui->btnSettings->text() == "Settings" || this->ui->btnSettings->text() == "Hide Settings")
    {
        this->ui->btnSettings->setText("Show Settings");

        this->ui->lblScrUpCodeFR    ->hide(); this->ui->lblScrUpCodeRR    ->hide(); this->ui->lblScrUpCodeSR    ->hide(); this->ui->lblScrUpCodeSL   ->hide();
        this->ui->lblScrDownCodeFR  ->hide(); this->ui->lblScrDownCodeRR  ->hide(); this->ui->lblScrDownCodeSR  ->hide(); this->ui->lblScrDownCodeSL ->hide();
        this->ui->lblScrStopCodeFR  ->hide(); this->ui->lblScrStopCodeRR  ->hide(); this->ui->lblScrStopCodeSR  ->hide(); this->ui->lblScrStopCodeSL ->hide();
        this->ui->lblScrComPortFR   ->hide(); this->ui->lblScrComPortRR   ->hide(); this->ui->lblScrComPortSR   ->hide(); this->ui->lblScrComPortSL  ->hide();
        this->ui->lblProjAddrFR     ->hide(); this->ui->lblProjAddrRR     ->hide(); this->ui->lblProjAddrSR     ->hide(); this->ui->lblProjAddrSL    ->hide();

        this->ui->editScrUpCodeFR   ->hide(); this->ui->editScrUpCodeRR   ->hide(); this->ui->editScrUpCodeSR   ->hide(); this->ui->editScrUpCodeSL  ->hide();
        this->ui->editScrDownCodeFR ->hide(); this->ui->editScrDownCodeRR ->hide(); this->ui->editScrDownCodeSR ->hide(); this->ui->editScrDownCodeSL->hide();
        this->ui->editScrStopCodeFR ->hide(); this->ui->editScrStopCodeRR ->hide(); this->ui->editScrStopCodeSR ->hide(); this->ui->editScrStopCodeSL->hide();
        this->ui->cbScrComPortFR    ->hide(); this->ui->cbScrComPortRR    ->hide(); this->ui->cbScrComPortSR    ->hide(); this->ui->cbScrComPortSL   ->hide();
        this->ui->editProjAddrFR    ->hide(); this->ui->editProjAddrRR    ->hide(); this->ui->editProjAddrSR    ->hide(); this->ui->editProjAddrSL   ->hide();

        this->ui->lblProjPasswordFr ->hide(); this->ui->lblProjPasswordRR ->hide(); this->ui->lblProjPasswordSR ->hide();  this->ui->lblProjPasswordSL->hide();
        this->ui->editProjPasswordFR->hide(); this->ui->editProjPasswordRR->hide(); this->ui->editProjPasswordSR->hide(); this->ui->editProjPasswordSL->hide();

    } else {
        this->ui->btnSettings->setText("Hide Settings");

        this->ui->lblScrUpCodeFR    ->show(); this->ui->lblScrUpCodeRR    ->show(); this->ui->lblScrUpCodeSR    ->show(); this->ui->lblScrUpCodeSL    ->show();
        this->ui->lblScrDownCodeFR  ->show(); this->ui->lblScrDownCodeRR  ->show(); this->ui->lblScrDownCodeSR  ->show(); this->ui->lblScrDownCodeSL  ->show();
        this->ui->lblScrStopCodeFR  ->show(); this->ui->lblScrStopCodeRR  ->show(); this->ui->lblScrStopCodeSR  ->show(); this->ui->lblScrStopCodeSL  ->show();
        this->ui->lblScrComPortFR   ->show(); this->ui->lblScrComPortRR   ->show(); this->ui->lblScrComPortSR   ->show(); this->ui->lblScrComPortSL   ->show();
        this->ui->lblProjAddrFR     ->show(); this->ui->lblProjAddrRR     ->show(); this->ui->lblProjAddrSR     ->show(); this->ui->lblProjAddrSL     ->show();

        this->ui->editScrUpCodeFR   ->show(); this->ui->editScrUpCodeRR   ->show(); this->ui->editScrUpCodeSR   ->show(); this->ui->editScrUpCodeSL   ->show();
        this->ui->editScrDownCodeFR ->show(); this->ui->editScrDownCodeRR ->show(); this->ui->editScrDownCodeSR ->show(); this->ui->editScrDownCodeSL ->show();
        this->ui->editScrStopCodeFR ->show(); this->ui->editScrStopCodeRR ->show(); this->ui->editScrStopCodeSR ->show(); this->ui->editScrStopCodeSL ->show();
        this->ui->cbScrComPortFR    ->show(); this->ui->cbScrComPortRR    ->show(); this->ui->cbScrComPortSR    ->show(); this->ui->cbScrComPortSL    ->show();
        this->ui->editProjAddrFR    ->show(); this->ui->editProjAddrRR    ->show(); this->ui->editProjAddrSR    ->show(); this->ui->editProjAddrSL    ->show();

        this->ui->lblProjPasswordFr ->show(); this->ui->lblProjPasswordRR ->show(); this->ui->lblProjPasswordSR ->show(); this->ui->lblProjPasswordSL ->show();
        this->ui->editProjPasswordFR->show(); this->ui->editProjPasswordRR->show(); this->ui->editProjPasswordSR->show(); this->ui->editProjPasswordSL->show();
    }
}

void MainWindow::on_btnMinimize_clicked()
{
    this->showMinimized();
}

void MainWindow::on_btnFrontProj_clicked()
{
    if (this->ui->btnFrontProj->text() == "Power Off") {
        ui->btnFrontProj->setText("Power On");
        this->projectors["front"]->set_power_off();
        this->screen_cmd(this->ui->editScrUpCodeFR->text(), this->FRComPort);
    } else {
        ui->btnFrontProj->setText("Power Off");
        this->projectors["front"]->set_power_on();
        this->screen_cmd(this->ui->editScrDownCodeFR->text(), this->FRComPort);
    }
}

void MainWindow::on_btnSRProj_clicked()
{
    if (this->ui->btnSRProj->text() == "Power Off") {
        ui->btnSRProj->setText("Power On");
        this->projectors["sr"]->set_power_off();
        this->screen_cmd(this->ui->editScrUpCodeFR->text(), this->SRComPort);
    } else {
        ui->btnSRProj->setText("Power Off");
        this->projectors["sr"]->set_power_on();
        this->screen_cmd(this->ui->editScrDownCodeFR->text(), this->SRComPort);
    }
}

void MainWindow::on_btnSLProj_clicked()
{
    if (this->ui->btnSLProj->text() == "Power Off") {
        ui->btnSLProj->setText("Power On");
        this->projectors["sl"]->set_power_off();
        this->screen_cmd(this->ui->editScrUpCodeFR->text(), this->SLComPort);
    } else {
        ui->btnSLProj->setText("Power Off");
        this->projectors["sl"]->set_power_on();
        this->screen_cmd(this->ui->editScrDownCodeFR->text(), this->SLComPort);
    }
}

void MainWindow::on_btnRearProj_clicked()
{
    if (this->ui->btnRearProj->text() == "Power Off")
    {
        ui->btnRearProj->setText("Power On");
        this->projectors["rear"]->set_power_off();
        this->screen_cmd(this->ui->editScrUpCodeFR->text(), this->RearComPort);
    } else {
        ui->btnRearProj->setText("Power Off");
        this->projectors["rear"]->set_power_on();
        this->screen_cmd(this->ui->editScrDownCodeFR->text(), this->FRComPort);
    }
}

void MainWindow::screen_cmd(QString code, QSerialPort& port)
{
    // screen
    QByteArray ba;

    QList<QString> l = code.split(" ");

    foreach (QString n, l) {
        ba.append(n.toInt(0, 16));
    }

    port.write(ba);
}


void MainWindow::update_P1_status_label()
{
    QString ps = this->projectors["front"]->power_status;

    if (ps == "On") {
        this->ui->btnFrontProj->setText("Power Off");
        this->ui->btnFrontProj->setEnabled(true);
    } else if (ps == "Cooling Down") {
        this->ui->btnFrontProj->setText("Cooling Down  \nPlease wait...");
        this->ui->btnFrontProj->setEnabled(false);
    } else if (ps == "Warming Up") {
        this->ui->btnFrontProj->setText("Warming up  \nPlease wait...");
        this->ui->btnFrontProj->setEnabled(false);
    } else if (ps == "Standby") {
        this->ui->btnFrontProj->setText("Power On");
        this->ui->btnFrontProj->setEnabled(true);
    }
    QString current_status = this->ui->lblStatusFR->text();

    if (current_status.startsWith("waiting...") || current_status.startsWith("Errors")) {
        QString name  = this->projectors["front"]->name;
        QString manuf = this->projectors["front"]->manufacturer;
        QString model = this->projectors["front"]->model;

        this->ui->lblStatusFR->setText(QString("1: ") + name + " (" + manuf + " : " + model + ")");
    } else if (current_status.startsWith("Type:")) {
        this->ui->lblStatusFR->setText(QString("Lamp Hours: ")+ this->projectors["front"]->lamp_status );
    } else if (current_status.startsWith("Lamp Hours")) {
        this->ui->lblStatusFR->setText(QString("Errors: ") + this->projectors["front"]->error_status);
    }
}

void MainWindow::update_P2_status_label()
{

    QString ps = this->projectors["rear"]->power_status;

    QPushButton* btn = this->ui->btnRearProj;
    if (ps == "On") {
        btn->setText("Power Off");
        btn->setEnabled(true);
    } else if (ps == "Cooling Down") {
        btn->setText("Cooling Down\nPlease wait...");
        btn->setEnabled(false);
    } else if (ps == "Warming Up") {
        btn->setText("Warming up\nPlease wait...");
        btn->setEnabled(false);
    } else if (ps == "Standby") {
        btn->setText("Power On");
        btn->setEnabled(true);
    }

    QString current_status = this->ui->lblStatusRR->text();

    if (current_status.startsWith("waiting...") || current_status.startsWith("Errors")) {
        QString name  = this->projectors["rear"]->name;
        QString manuf = this->projectors["rear"]->manufacturer;
        QString model = this->projectors["rear"]->model;

        this->ui->lblStatusRR->setText(QString("Type: ")+ manuf + " : " + model);
    } else if (current_status.startsWith("Type:")) {
        this->ui->lblStatusRR->setText(QString("Lamp Hours: ")+ this->projectors["rear"]->lamp_status );
    } else if (current_status.startsWith("Lamp Hours")) {
        this->ui->lblStatusRR->setText(QString("Errors: ") + this->projectors["rear"]->error_status);
    }
}

void MainWindow::update_P3_status_label()
{
    QString ps = this->projectors["sr"]->power_status;
    QPushButton* btn = this->ui->btnSRProj;
    if (ps == "On") {
        btn->setText("Power Off");
        btn->setEnabled(true);
    } else if (ps == "Cooling Down") {
        btn->setText("Cooling Down\nPlease wait...");
        btn->setEnabled(false);
    } else if (ps == "Warming Up") {
        btn->setText("Warming up\nPlease wait...");
        btn->setEnabled(false);
    } else if (ps == "Standby") {
        btn->setText("Power On");
        btn->setEnabled(true);
    }

    QString current_status = this->ui->lblStatusSR->text();

    if (current_status.startsWith("waiting...") || current_status.startsWith("Errors")) {
        QString name  = this->projectors["sr"]->name;
        QString manuf = this->projectors["sr"]->manufacturer;
        QString model = this->projectors["sr"]->model;

        this->ui->lblStatusSR->setText(QString("Type: ")+ manuf + " : " + model);
    } else if (current_status.startsWith("Type:")) {
        this->ui->lblStatusSR->setText(QString("Lamp Hours: ")+ this->projectors["sr"]->lamp_status );
    } else if (current_status.startsWith("Lamp Hours")) {
        this->ui->lblStatusSR->setText(QString("Errors: ") + this->projectors["sr"]->error_status);
    }
}

void MainWindow::update_P4_status_label()
{
    QString ps = this->projectors["sl"]->power_status;
    QPushButton* btn = this->ui->btnSLProj;
    if (ps == "On") {
        btn->setText("Power Off");
        btn->setEnabled(true);
    } else if (ps == "Cooling Down") {
        btn->setText("Cooling Down\nPlease wait...");
        btn->setEnabled(false);
    } else if (ps == "Warming Up") {
        btn->setText("Warming up\nPlease wait...");
        btn->setEnabled(false);
    } else if (ps == "Standby") {
        btn->setText("Power On");
        btn->setEnabled(true);
    }

    QString current_status = this->ui->lblStatusSL->text();

    if (current_status.startsWith("waiting...") || current_status.startsWith("Errors")) {
        QString name  = this->projectors["sl"]->name;
        QString manuf = this->projectors["sl"]->manufacturer;
        QString model = this->projectors["sl"]->model;

        this->ui->lblStatusSL->setText(QString("1: ") + name + "(" + manuf + " : " + model + ")");
    } else if (current_status.startsWith("1:")) {
        this->ui->lblStatusSL->setText(QString("Lamp Hours: ")+ this->projectors["sl"]->lamp_status );
    } else if (current_status.startsWith("Lamp Hours")) {
        this->ui->lblStatusSL->setText(QString("Errors: ") + this->projectors["sl"]->error_status );
    }
}

void MainWindow::on_pushButton_clicked()
{
    this->SerialPortInfo.show();
}

void MainWindow::on_buttonBox_clicked(QAbstractButton *button)
{
    if (button && button->text() == "Cancel") {
        this->close();
    } else if (button && button->text() == "Ok") {
        this->hide();
    }
}
