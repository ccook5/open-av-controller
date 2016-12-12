#ifndef SERIALPORTLIST_H
#define SERIALPORTLIST_H

#include <QDialog>

namespace Ui {
class SerialPortList;
}

class SerialPortList : public QDialog
{
    Q_OBJECT

public:
    explicit SerialPortList(QWidget *parent = 0);
    ~SerialPortList();

private:
    Ui::SerialPortList *ui;
};

#endif // SERIALPORTLIST_H
