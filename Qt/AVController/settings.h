#ifndef SETTINGS_H
#define SETTINGS_H

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



    Ui::Settings *ui;

};

#endif // SETTINGS_H