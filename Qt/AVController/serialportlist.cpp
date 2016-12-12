#include "serialportlist.h"
#include "ui_serialportlist.h"

#include <QtSerialPort/QSerialPortInfo>

SerialPortList::SerialPortList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SerialPortList)
{
    ui->setupUi(this);

    QList <QTreeWidgetItem *> items;

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        QStringList sl;

        sl << info.portName()
           << info.systemLocation()
           << info.description()
           << info.manufacturer()
           << info.serialNumber()
           << (info.hasVendorIdentifier()  ? QString::number(info.vendorIdentifier(),  16) : QString())
           << (info.hasProductIdentifier() ? QString::number(info.productIdentifier(), 16) : QString())
           << (info.isBusy() ? QObject::tr("Yes") : QObject::tr("No")) + "\n";
        items.append(new QTreeWidgetItem((QTreeWidget*)0, sl));

    }

    ui->treeWidget->insertTopLevelItems(0, items);

}

SerialPortList::~SerialPortList()
{
    delete ui;
}
