#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QSerialPort>

#include "pjlink.h"
#include "serialportlist.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    virtual void SimpleMode();
    virtual void AdvancedMode();
    void showHideSettings(bool show);

    void FRProjOn();
    void FRProjOff();

    void SRProjOn();
    void SRProjOff();

    void SLProjOn();
    void SLProjOff();

    void RearProjOn();
    void RearProjOff();

private slots:
    void on_btnSettings_clicked();

    void on_btnMinimize_clicked();


private:
    Ui::MainWindow *ui;

    SerialPortList* serialPortListDlg;


    QTimer tmr_get_P1_status;
    QTimer tmr_get_P2_status;
    QTimer tmr_get_P3_status;
    QTimer tmr_get_P4_status;

    PjLink* sr_projector;
    PjLink* sl_projector;
    PjLink* front_projector;
    PjLink* rear_projector;

    QSerialPort FRComPort;
    QSerialPort RearComPort;
    QSerialPort SRComPort;
    QSerialPort SLComPort;

    bool settings_enabled;


private slots:
    void update_P1_status_label();
    void update_P2_status_label();
    void update_P3_status_label();
    void update_P4_status_label();

    void on_btnSrcPC_clicked();
    void on_btnSrcLaptop_clicked();
    void on_btnProj1On_clicked();
    void on_btnProj2On_clicked();
    void on_btnProj3On_clicked();
    void on_btnProj4On_clicked();
    void on_btnProj1Off_clicked();
    void on_btnProj2Off_clicked();
    void on_btnProj3Off_clicked();
    void on_btnProj4Off_clicked();
    void on_cbFullscreen_toggled(bool checked);
    void on_btnSerialSettings_clicked();
    void on_cmbMode_currentIndexChanged(const QString &arg1);
};

#endif // MAINWINDOW_H
