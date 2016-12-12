#include "mainwindow.h"
#include "settings.h"
#include "ui_mainwindow.h"

#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    settingsDlg = new Settings(this);
    settingsDlg->hide();

    this->SimpleMode();

    connect( &tmr_get_P1_status, SIGNAL(timeout()), this, SLOT(update_P1_status_label()) );
    connect( &tmr_get_P2_status, SIGNAL(timeout()), this, SLOT(update_P2_status_label()) );
    connect( &tmr_get_P3_status, SIGNAL(timeout()), this, SLOT(update_P3_status_label()) );
    connect( &tmr_get_P4_status, SIGNAL(timeout()), this, SLOT(update_P4_status_label()) );

    this->tmr_get_P1_status.start(10000);
    this->tmr_get_P2_status.start(10000);
    this->tmr_get_P3_status.start(10000);
    this->tmr_get_P4_status.start(10000);

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
    this->settingsDlg->show();
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
}

void MainWindow::on_btnProj2On_clicked()
{
// Screen
    QByteArray ba;

    QList<QString> l = this->settingsDlg->Proj2ScreenDownCode().split(" ");

    foreach (QString n, l) {      ba.append(n.toInt(0, 16));    }

    this->settingsDlg->FRComPort.write(ba);
// Projector
}

void MainWindow::on_btnProj3On_clicked()
{
// Screen
    QByteArray ba;

    QList<QString> l = this->settingsDlg->Proj2ScreenDownCode().split(" ");

    foreach (QString n, l) {      ba.append(n.toInt(0, 16));    }

    this->settingsDlg->FRComPort.write(ba);
// Projector
}

void MainWindow::on_btnProj4On_clicked()
{
// Screen
    QByteArray ba;

    QList<QString> l = this->settingsDlg->Proj2ScreenDownCode().split(" ");

    foreach (QString n, l) {        ba.append(n.toInt(0, 16));    }

    this->settingsDlg->FRComPort.write(ba);
// Projector
}

void MainWindow::on_btnProj1Off_clicked()
{
    QByteArray ba;

    QList<QString> l = this->settingsDlg->Proj2ScreenUpCode().split(" ");

    foreach (QString n, l) {        ba.append(n.toInt(0, 16));    }

    this->settingsDlg->FRComPort.write(ba);
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
