#include "mainwindow.h"
#include "settings.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QInputDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    settingsDlg = new Settings(this);
    settingsDlg->hide();

    this->sl_projector    = new PjLink("192.168.0.213", 4352, "panasonic");
    this->front_projector = new PjLink("192.168.0.212", 4352, "panasonic");
    this->sr_projector    = new PjLink("192.168.0.215", 4352, "panasonic");
    this->rear_projector  = new PjLink("192.168.0.214", 4352, "panasonic");

    this->SimpleMode();

    connect( &tmr_get_P1_status, SIGNAL(timeout()), this, SLOT(update_P1_status_label()) );
    connect( &tmr_get_P2_status, SIGNAL(timeout()), this, SLOT(update_P2_status_label()) );
    connect( &tmr_get_P3_status, SIGNAL(timeout()), this, SLOT(update_P3_status_label()) );
    connect( &tmr_get_P4_status, SIGNAL(timeout()), this, SLOT(update_P4_status_label()) );

    this->tmr_get_P1_status.start(10000);
    this->tmr_get_P2_status.start(10000);
    this->tmr_get_P3_status.start(10000);
    this->tmr_get_P4_status.start(10000);

    connect(this->settingsDlg, SIGNAL(proj1_addr_changed(QString)), this->sr_projector,    SLOT(update_address(QString)));
    connect(this->settingsDlg, SIGNAL(proj2_addr_changed(QString)), this->front_projector, SLOT(update_address(QString)));
    connect(this->settingsDlg, SIGNAL(proj3_addr_changed(QString)), this->sl_projector,    SLOT(update_address(QString)));
    connect(this->settingsDlg, SIGNAL(proj4_addr_changed(QString)), this->rear_projector,  SLOT(update_address(QString)));

    connect(this->sr_projector,    SIGNAL(friendly_status_update(QString)), this->ui->lblStatus1, SLOT(setText(QString)));
    connect(this->front_projector, SIGNAL(friendly_status_update(QString)), this->ui->lblStatus2, SLOT(setText(QString)));
    connect(this->sl_projector,    SIGNAL(friendly_status_update(QString)), this->ui->lblStatus3, SLOT(setText(QString)));
    connect(this->rear_projector,  SIGNAL(friendly_status_update(QString)), this->ui->lblStatus4, SLOT(setText(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
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
    bool ok;
    QString text = QInputDialog::getText(this, "Password",
                                         "Please enter password", QLineEdit::Password,
                                         "", &ok);
    if (ok && !text.isEmpty()) {
        if (text == "1941") {
            this->settingsDlg->show();
            return;
        }
        QMessageBox::information(this, "incorrect password", "Please try again");
    }
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



void Settings::on_btnSerialSettings_clicked()
{
    this->serialPortListDlg->show();
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

    QList<QString> l = this->settingsDlg->Proj1ScreenDownCode().split(" ");

    foreach (QString n, l) {        ba.append(n.toInt(0, 16));    }

    this->settingsDlg->FRComPort.write(ba);

    // Projector
    this->sr_projector->power_on();
}

void MainWindow::on_btnProj2On_clicked()
{
// Screen
    QByteArray ba;

    QList<QString> l = this->settingsDlg->Proj2ScreenDownCode().split(" ");

    foreach (QString n, l) {      ba.append(n.toInt(0, 16));    }

    this->settingsDlg->FRComPort.write(ba);
// Projector

    // Projector
    this->front_projector->power_on();
}

void MainWindow::on_btnProj3On_clicked()
{
// Screen
    QByteArray ba;

    QList<QString> l = this->settingsDlg->Proj2ScreenDownCode().split(" ");

    foreach (QString n, l) {      ba.append(n.toInt(0, 16));    }

    this->settingsDlg->FRComPort.write(ba);
// Projector
    // Projector
    this->sl_projector->power_on();
}

void MainWindow::on_btnProj4On_clicked()
{
// Screen
    QByteArray ba;

    QList<QString> l = this->settingsDlg->Proj2ScreenDownCode().split(" ");

    foreach (QString n, l) {        ba.append(n.toInt(0, 16));    }

    this->settingsDlg->FRComPort.write(ba);
// Projector
    // Projector
    this->rear_projector->power_on();
}

void MainWindow::on_btnProj1Off_clicked()
{
    QByteArray ba;

    QList<QString> l = this->settingsDlg->Proj2ScreenUpCode().split(" ");

    foreach (QString n, l) {        ba.append(n.toInt(0, 16));    }

    this->settingsDlg->FRComPort.write(ba);
    // Projector
    this->sr_projector->power_off();
}

void MainWindow::on_btnProj2Off_clicked()
{
    QByteArray ba;

    QList<QString> l = this->settingsDlg->Proj2ScreenUpCode().split(" ");

    foreach (QString n, l) {        ba.append(n.toInt(0, 16));    }

    this->settingsDlg->FRComPort.write(ba);
}

void MainWindow::on_btnProj3Off_clicked()
{
    QByteArray ba;

    QList<QString> l = this->settingsDlg->Proj2ScreenUpCode().split(" ");

    foreach (QString n, l) {        ba.append(n.toInt(0, 16));    }

    this->settingsDlg->FRComPort.write(ba);
}

void MainWindow::on_btnProj4Off_clicked()
{
    QByteArray ba;

    QList<QString> l = this->settingsDlg->Proj2ScreenUpCode().split(" ");

    foreach (QString n, l) {        ba.append(n.toInt(0, 16));    }

    this->settingsDlg->FRComPort.write(ba);
}
