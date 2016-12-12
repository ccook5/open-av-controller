/********************************************************************************
** Form generated from reading UI file 'serialportlist.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALPORTLIST_H
#define UI_SERIALPORTLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTreeWidget>

QT_BEGIN_NAMESPACE

class Ui_SerialPortList
{
public:
    QGridLayout *gridLayout;
    QTreeWidget *treeWidget;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SerialPortList)
    {
        if (SerialPortList->objectName().isEmpty())
            SerialPortList->setObjectName(QStringLiteral("SerialPortList"));
        SerialPortList->resize(863, 195);
        SerialPortList->setSizeGripEnabled(true);
        gridLayout = new QGridLayout(SerialPortList);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        treeWidget = new QTreeWidget(SerialPortList);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));

        gridLayout->addWidget(treeWidget, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(SerialPortList);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 1, 0, 1, 1);


        retranslateUi(SerialPortList);
        QObject::connect(buttonBox, SIGNAL(accepted()), SerialPortList, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SerialPortList, SLOT(reject()));

        QMetaObject::connectSlotsByName(SerialPortList);
    } // setupUi

    void retranslateUi(QDialog *SerialPortList)
    {
        SerialPortList->setWindowTitle(QApplication::translate("SerialPortList", "Dialog", 0));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(7, QApplication::translate("SerialPortList", "Busy", 0));
        ___qtreewidgetitem->setText(6, QApplication::translate("SerialPortList", "Product Id.", 0));
        ___qtreewidgetitem->setText(5, QApplication::translate("SerialPortList", "Vendor Id.", 0));
        ___qtreewidgetitem->setText(4, QApplication::translate("SerialPortList", "Serial No.", 0));
        ___qtreewidgetitem->setText(3, QApplication::translate("SerialPortList", "Manufacturer", 0));
        ___qtreewidgetitem->setText(2, QApplication::translate("SerialPortList", "Description", 0));
        ___qtreewidgetitem->setText(1, QApplication::translate("SerialPortList", "Location", 0));
        ___qtreewidgetitem->setText(0, QApplication::translate("SerialPortList", "Port", 0));
    } // retranslateUi

};

namespace Ui {
    class SerialPortList: public Ui_SerialPortList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALPORTLIST_H
