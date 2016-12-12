#ifndef SETTINGS_H
#define SETTINGS_H

#include "serialportlist.h"
#include <QDialog>

#include <QSerialPort>

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();

    Ui::Settings* ui;
    SerialPortList* serialPortListDlg;

    QString Proj1ScreenDownCode();
    QString Proj2ScreenDownCode();
    QString Proj3ScreenDownCode();
    QString Proj4ScreenDownCode();

    QString Proj1ScreenUpCode();
    QString Proj2ScreenUpCode();
    QString Proj3ScreenUpCode();
    QString Proj4ScreenUpCode();

private slots:
    void on_btnSerialSettings_clicked();
    void on_cmbMode_currentIndexChanged(int index);

    void on_cbFullscreen_toggled(bool checked);

public:
    QSerialPort FRComPort;
    QSerialPort RearComPort;
    QSerialPort SRComPort;
    QSerialPort SLComPort;
};

#endif // SETTINGS_H
