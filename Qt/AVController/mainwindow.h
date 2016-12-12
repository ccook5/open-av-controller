#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QSerialPort>
#include <QAbstractButton>
#include <QTcpSocket>

#include "serialportlist.h"
#include "projector.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void screen_cmd(QString code, QSerialPort& port);

private slots:
    void on_btnSettings_clicked();
    void on_btnMinimize_clicked();
    void on_btnFrontProj_clicked();
    void on_btnSRProj_clicked();
    void on_btnSLProj_clicked();
    void on_btnRearProj_clicked();

private:
    Ui::MainWindow *ui;

private slots:
    void update_P1_status_label();
    void update_P2_status_label();
    void update_P3_status_label();
    void update_P4_status_label();

    void on_pushButton_clicked();

    void on_buttonBox_clicked(QAbstractButton *button);

private:
    QSerialPort FRComPort;
    QSerialPort RearComPort;
    QSerialPort SRComPort;
    QSerialPort SLComPort;

    SerialPortList SerialPortInfo;

    QMap<QString, projector*> projectors;

};

#endif // MAINWINDOW_H
