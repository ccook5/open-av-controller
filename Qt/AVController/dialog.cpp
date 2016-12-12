#include "serialportlist.h"
#include "ui_dialog.h"


#include <QVBoxLayout>
#include <QTreeWidget>
#include <QScrollArea>
#include <QString>
#include <QtSerialPort/QSerialPortInfo>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->treeWidget
            QTreeWidget     * treeWidget = new QTreeWidget();

            treeWidget->setColumnCount(7);

            QStringList headers;

            headers  << "Port" << "Location" << "Description" << "Manufacturer" << "Serial No." << "Vendor ID" << "Product ID" << "Busy status";

            treeWidget->setHeaderLabels(headers);

            QList<QTreeWidgetItem *> items;

            foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
            {
                QStringList sl;

                sl << info.portName()
                   << info.systemLocation()
                   << info.description()
                   << info.manufacturer()
                   << info.serialNumber()
                   << ( info.hasVendorIdentifier()  ? QString::number(info.vendorIdentifier(),  16) : QString()         )
                   << ( info.hasProductIdentifier() ? QString::number(info.productIdentifier(), 16) : QString()         )
                   << ( info.isBusy()               ? QObject::tr("Yes")                            : QObject::tr("No") );

                items.append( new QTreeWidgetItem( (QTreeWidget*)0, sl ) );
            }


            QVBoxLayout     * layout     = new QVBoxLayout;
            layout->addWidget(treeWidget);

            treeWidget->insertTopLevelItems(0, items);

            QWidget *workPage = new QWidget;
            workPage->setLayout(layout);

            QScrollArea area;

            area.setWindowTitle(QObject::tr("Info about all available serial ports."));
            area.setWidget(workPage);
            area.setWidgetResizable(true);
            area.show();
}

Dialog::~Dialog()
{
    delete ui;
}
