/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QGridLayout *gridLayout;
    QGroupBox *grpMainSettings;
    QGridLayout *gridLayout_5;
    QLineEdit *MatrixAddress;
    QLabel *label_12;
    QLineEdit *lineEdit_10;
    QLabel *label_11;
    QLineEdit *lineEdit_11;
    QLabel *lblMatrixAddr;
    QLabel *label_22;
    QLineEdit *lineEdit_22;
    QGroupBox *grpProj4;
    QGridLayout *gridLayout_6;
    QLineEdit *Proj4ScreenDownCode;
    QLabel *lblProj4Address;
    QLabel *lblProj4ScreenDownCode;
    QLabel *lblProj4ScreenStopCode;
    QLabel *lblProj4ScreenUpCode;
    QLineEdit *Proj4ScreenUpCode;
    QComboBox *Proj4ComPort;
    QLabel *lblProj4ComPort;
    QLabel *lblProj4Input;
    QComboBox *Proj4Input;
    QLineEdit *Proj4Address;
    QLineEdit *Proj4ScreenStopCode;
    QLineEdit *Proj4Name;
    QLabel *lblProj4Name;
    QGroupBox *grpProj1;
    QGridLayout *gridLayout_2;
    QLineEdit *Proj1ScreenDownCode;
    QLabel *lblProj1ProjectorAddr;
    QLineEdit *Proj1Address;
    QLineEdit *Proj1ScreenStopCode;
    QComboBox *Proj1ComPort;
    QLabel *lblProj1ScnStopCode;
    QLineEdit *Proj1ScreenUpCode;
    QLabel *lblProj1ScnDownCode;
    QLabel *lblProj1ScnUpCode;
    QLabel *lblProj1ComPort;
    QLabel *lblProj1Input;
    QComboBox *Proj1Input;
    QLineEdit *Proj1Name;
    QLabel *lblProjName;
    QGroupBox *grpProj2;
    QGridLayout *gridLayout_3;
    QLineEdit *Proj2ScreenUpCode;
    QLabel *lblProj2ScreenDown;
    QLineEdit *Proj2Address;
    QLabel *lblProj2Address;
    QLineEdit *Proj2ScreenDownCode;
    QLabel *lblProj2ScreenUp;
    QLabel *lblProj2ScreenStop;
    QLineEdit *Proj2ScreenStopCode;
    QComboBox *Proj2ComPort;
    QLabel *lblProj2ComPort;
    QLabel *lblProj2Input;
    QComboBox *Proj2Input;
    QLineEdit *Proj2Name;
    QLabel *lblProj2Name;
    QGroupBox *grpProj3;
    QGridLayout *gridLayout_4;
    QLabel *lblProj3ScreenUpCode;
    QLineEdit *Proj3ScreeenStopCode;
    QComboBox *Proj3ComPort;
    QLabel *lblProj3ScreenDownCode;
    QLabel *lblProj3ScreenStopCode;
    QLineEdit *Proj3ScreenUpCode;
    QLineEdit *Proj3ScreenDownCode;
    QLineEdit *Proj3Address;
    QLabel *lblProj3Input;
    QComboBox *Proj3Input;
    QLabel *lblProj3Address;
    QLabel *lblProj3Comport;
    QLineEdit *Proj3Name;
    QLabel *lblProj3Name;
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QPushButton *btnSerialSettings;
    QComboBox *cmbMode;
    QCheckBox *cbFullscreen;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QStringLiteral("Settings"));
        Settings->resize(640, 480);
        gridLayout = new QGridLayout(Settings);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        grpMainSettings = new QGroupBox(Settings);
        grpMainSettings->setObjectName(QStringLiteral("grpMainSettings"));
        gridLayout_5 = new QGridLayout(grpMainSettings);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        MatrixAddress = new QLineEdit(grpMainSettings);
        MatrixAddress->setObjectName(QStringLiteral("MatrixAddress"));

        gridLayout_5->addWidget(MatrixAddress, 0, 1, 1, 1);

        label_12 = new QLabel(grpMainSettings);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_5->addWidget(label_12, 1, 0, 1, 1);

        lineEdit_10 = new QLineEdit(grpMainSettings);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));

        gridLayout_5->addWidget(lineEdit_10, 1, 1, 1, 1);

        label_11 = new QLabel(grpMainSettings);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_5->addWidget(label_11, 2, 0, 1, 1);

        lineEdit_11 = new QLineEdit(grpMainSettings);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));

        gridLayout_5->addWidget(lineEdit_11, 2, 1, 1, 1);

        lblMatrixAddr = new QLabel(grpMainSettings);
        lblMatrixAddr->setObjectName(QStringLiteral("lblMatrixAddr"));

        gridLayout_5->addWidget(lblMatrixAddr, 0, 0, 1, 1);

        label_22 = new QLabel(grpMainSettings);
        label_22->setObjectName(QStringLiteral("label_22"));

        gridLayout_5->addWidget(label_22, 3, 0, 1, 1);

        lineEdit_22 = new QLineEdit(grpMainSettings);
        lineEdit_22->setObjectName(QStringLiteral("lineEdit_22"));

        gridLayout_5->addWidget(lineEdit_22, 3, 1, 1, 1);


        gridLayout->addWidget(grpMainSettings, 3, 0, 1, 1);

        grpProj4 = new QGroupBox(Settings);
        grpProj4->setObjectName(QStringLiteral("grpProj4"));
        gridLayout_6 = new QGridLayout(grpProj4);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        Proj4ScreenDownCode = new QLineEdit(grpProj4);
        Proj4ScreenDownCode->setObjectName(QStringLiteral("Proj4ScreenDownCode"));

        gridLayout_6->addWidget(Proj4ScreenDownCode, 2, 1, 1, 1);

        lblProj4Address = new QLabel(grpProj4);
        lblProj4Address->setObjectName(QStringLiteral("lblProj4Address"));

        gridLayout_6->addWidget(lblProj4Address, 5, 0, 1, 1);

        lblProj4ScreenDownCode = new QLabel(grpProj4);
        lblProj4ScreenDownCode->setObjectName(QStringLiteral("lblProj4ScreenDownCode"));

        gridLayout_6->addWidget(lblProj4ScreenDownCode, 2, 0, 1, 1);

        lblProj4ScreenStopCode = new QLabel(grpProj4);
        lblProj4ScreenStopCode->setObjectName(QStringLiteral("lblProj4ScreenStopCode"));

        gridLayout_6->addWidget(lblProj4ScreenStopCode, 3, 0, 1, 1);

        lblProj4ScreenUpCode = new QLabel(grpProj4);
        lblProj4ScreenUpCode->setObjectName(QStringLiteral("lblProj4ScreenUpCode"));

        gridLayout_6->addWidget(lblProj4ScreenUpCode, 1, 0, 1, 1);

        Proj4ScreenUpCode = new QLineEdit(grpProj4);
        Proj4ScreenUpCode->setObjectName(QStringLiteral("Proj4ScreenUpCode"));

        gridLayout_6->addWidget(Proj4ScreenUpCode, 1, 1, 1, 1);

        Proj4ComPort = new QComboBox(grpProj4);
        Proj4ComPort->setObjectName(QStringLiteral("Proj4ComPort"));

        gridLayout_6->addWidget(Proj4ComPort, 4, 1, 1, 1);

        lblProj4ComPort = new QLabel(grpProj4);
        lblProj4ComPort->setObjectName(QStringLiteral("lblProj4ComPort"));

        gridLayout_6->addWidget(lblProj4ComPort, 4, 0, 1, 1);

        lblProj4Input = new QLabel(grpProj4);
        lblProj4Input->setObjectName(QStringLiteral("lblProj4Input"));

        gridLayout_6->addWidget(lblProj4Input, 6, 0, 1, 1);

        Proj4Input = new QComboBox(grpProj4);
        Proj4Input->setObjectName(QStringLiteral("Proj4Input"));

        gridLayout_6->addWidget(Proj4Input, 6, 1, 1, 1);

        Proj4Address = new QLineEdit(grpProj4);
        Proj4Address->setObjectName(QStringLiteral("Proj4Address"));

        gridLayout_6->addWidget(Proj4Address, 5, 1, 1, 1);

        Proj4ScreenStopCode = new QLineEdit(grpProj4);
        Proj4ScreenStopCode->setObjectName(QStringLiteral("Proj4ScreenStopCode"));

        gridLayout_6->addWidget(Proj4ScreenStopCode, 3, 1, 1, 1);

        Proj4Name = new QLineEdit(grpProj4);
        Proj4Name->setObjectName(QStringLiteral("Proj4Name"));

        gridLayout_6->addWidget(Proj4Name, 0, 1, 1, 1);

        lblProj4Name = new QLabel(grpProj4);
        lblProj4Name->setObjectName(QStringLiteral("lblProj4Name"));

        gridLayout_6->addWidget(lblProj4Name, 0, 0, 1, 1);


        gridLayout->addWidget(grpProj4, 3, 1, 1, 1);

        grpProj1 = new QGroupBox(Settings);
        grpProj1->setObjectName(QStringLiteral("grpProj1"));
        gridLayout_2 = new QGridLayout(grpProj1);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        Proj1ScreenDownCode = new QLineEdit(grpProj1);
        Proj1ScreenDownCode->setObjectName(QStringLiteral("Proj1ScreenDownCode"));

        gridLayout_2->addWidget(Proj1ScreenDownCode, 2, 2, 1, 1);

        lblProj1ProjectorAddr = new QLabel(grpProj1);
        lblProj1ProjectorAddr->setObjectName(QStringLiteral("lblProj1ProjectorAddr"));

        gridLayout_2->addWidget(lblProj1ProjectorAddr, 5, 0, 1, 1);

        Proj1Address = new QLineEdit(grpProj1);
        Proj1Address->setObjectName(QStringLiteral("Proj1Address"));

        gridLayout_2->addWidget(Proj1Address, 5, 2, 1, 1);

        Proj1ScreenStopCode = new QLineEdit(grpProj1);
        Proj1ScreenStopCode->setObjectName(QStringLiteral("Proj1ScreenStopCode"));

        gridLayout_2->addWidget(Proj1ScreenStopCode, 3, 2, 1, 1);

        Proj1ComPort = new QComboBox(grpProj1);
        Proj1ComPort->setObjectName(QStringLiteral("Proj1ComPort"));

        gridLayout_2->addWidget(Proj1ComPort, 4, 2, 1, 1);

        lblProj1ScnStopCode = new QLabel(grpProj1);
        lblProj1ScnStopCode->setObjectName(QStringLiteral("lblProj1ScnStopCode"));

        gridLayout_2->addWidget(lblProj1ScnStopCode, 3, 0, 1, 1);

        Proj1ScreenUpCode = new QLineEdit(grpProj1);
        Proj1ScreenUpCode->setObjectName(QStringLiteral("Proj1ScreenUpCode"));

        gridLayout_2->addWidget(Proj1ScreenUpCode, 1, 2, 1, 1);

        lblProj1ScnDownCode = new QLabel(grpProj1);
        lblProj1ScnDownCode->setObjectName(QStringLiteral("lblProj1ScnDownCode"));

        gridLayout_2->addWidget(lblProj1ScnDownCode, 2, 0, 1, 1);

        lblProj1ScnUpCode = new QLabel(grpProj1);
        lblProj1ScnUpCode->setObjectName(QStringLiteral("lblProj1ScnUpCode"));

        gridLayout_2->addWidget(lblProj1ScnUpCode, 1, 0, 1, 1);

        lblProj1ComPort = new QLabel(grpProj1);
        lblProj1ComPort->setObjectName(QStringLiteral("lblProj1ComPort"));

        gridLayout_2->addWidget(lblProj1ComPort, 4, 0, 1, 1);

        lblProj1Input = new QLabel(grpProj1);
        lblProj1Input->setObjectName(QStringLiteral("lblProj1Input"));

        gridLayout_2->addWidget(lblProj1Input, 6, 0, 1, 1);

        Proj1Input = new QComboBox(grpProj1);
        Proj1Input->setObjectName(QStringLiteral("Proj1Input"));

        gridLayout_2->addWidget(Proj1Input, 6, 2, 1, 1);

        Proj1Name = new QLineEdit(grpProj1);
        Proj1Name->setObjectName(QStringLiteral("Proj1Name"));

        gridLayout_2->addWidget(Proj1Name, 0, 2, 1, 1);

        lblProjName = new QLabel(grpProj1);
        lblProjName->setObjectName(QStringLiteral("lblProjName"));

        gridLayout_2->addWidget(lblProjName, 0, 0, 1, 1);


        gridLayout->addWidget(grpProj1, 0, 0, 1, 1);

        grpProj2 = new QGroupBox(Settings);
        grpProj2->setObjectName(QStringLiteral("grpProj2"));
        gridLayout_3 = new QGridLayout(grpProj2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        Proj2ScreenUpCode = new QLineEdit(grpProj2);
        Proj2ScreenUpCode->setObjectName(QStringLiteral("Proj2ScreenUpCode"));

        gridLayout_3->addWidget(Proj2ScreenUpCode, 1, 1, 1, 1);

        lblProj2ScreenDown = new QLabel(grpProj2);
        lblProj2ScreenDown->setObjectName(QStringLiteral("lblProj2ScreenDown"));

        gridLayout_3->addWidget(lblProj2ScreenDown, 2, 0, 1, 1);

        Proj2Address = new QLineEdit(grpProj2);
        Proj2Address->setObjectName(QStringLiteral("Proj2Address"));

        gridLayout_3->addWidget(Proj2Address, 5, 1, 1, 1);

        lblProj2Address = new QLabel(grpProj2);
        lblProj2Address->setObjectName(QStringLiteral("lblProj2Address"));

        gridLayout_3->addWidget(lblProj2Address, 5, 0, 1, 1);

        Proj2ScreenDownCode = new QLineEdit(grpProj2);
        Proj2ScreenDownCode->setObjectName(QStringLiteral("Proj2ScreenDownCode"));

        gridLayout_3->addWidget(Proj2ScreenDownCode, 2, 1, 1, 1);

        lblProj2ScreenUp = new QLabel(grpProj2);
        lblProj2ScreenUp->setObjectName(QStringLiteral("lblProj2ScreenUp"));

        gridLayout_3->addWidget(lblProj2ScreenUp, 1, 0, 1, 1);

        lblProj2ScreenStop = new QLabel(grpProj2);
        lblProj2ScreenStop->setObjectName(QStringLiteral("lblProj2ScreenStop"));

        gridLayout_3->addWidget(lblProj2ScreenStop, 3, 0, 1, 1);

        Proj2ScreenStopCode = new QLineEdit(grpProj2);
        Proj2ScreenStopCode->setObjectName(QStringLiteral("Proj2ScreenStopCode"));

        gridLayout_3->addWidget(Proj2ScreenStopCode, 3, 1, 1, 1);

        Proj2ComPort = new QComboBox(grpProj2);
        Proj2ComPort->setObjectName(QStringLiteral("Proj2ComPort"));

        gridLayout_3->addWidget(Proj2ComPort, 4, 1, 1, 1);

        lblProj2ComPort = new QLabel(grpProj2);
        lblProj2ComPort->setObjectName(QStringLiteral("lblProj2ComPort"));

        gridLayout_3->addWidget(lblProj2ComPort, 4, 0, 1, 1);

        lblProj2Input = new QLabel(grpProj2);
        lblProj2Input->setObjectName(QStringLiteral("lblProj2Input"));

        gridLayout_3->addWidget(lblProj2Input, 6, 0, 1, 1);

        Proj2Input = new QComboBox(grpProj2);
        Proj2Input->setObjectName(QStringLiteral("Proj2Input"));

        gridLayout_3->addWidget(Proj2Input, 6, 1, 1, 1);

        Proj2Name = new QLineEdit(grpProj2);
        Proj2Name->setObjectName(QStringLiteral("Proj2Name"));

        gridLayout_3->addWidget(Proj2Name, 0, 1, 1, 1);

        lblProj2Name = new QLabel(grpProj2);
        lblProj2Name->setObjectName(QStringLiteral("lblProj2Name"));

        gridLayout_3->addWidget(lblProj2Name, 0, 0, 1, 1);

        lblProj2ScreenUp->raise();
        Proj2ScreenDownCode->raise();
        lblProj2ScreenStop->raise();
        Proj2ScreenStopCode->raise();
        lblProj2ScreenDown->raise();
        Proj2ScreenUpCode->raise();
        lblProj2Address->raise();
        Proj2Address->raise();
        Proj2ComPort->raise();
        lblProj2ComPort->raise();
        lblProj2Input->raise();
        Proj2Input->raise();
        Proj2Name->raise();
        lblProj2Name->raise();

        gridLayout->addWidget(grpProj2, 0, 1, 1, 1);

        grpProj3 = new QGroupBox(Settings);
        grpProj3->setObjectName(QStringLiteral("grpProj3"));
        gridLayout_4 = new QGridLayout(grpProj3);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        lblProj3ScreenUpCode = new QLabel(grpProj3);
        lblProj3ScreenUpCode->setObjectName(QStringLiteral("lblProj3ScreenUpCode"));

        gridLayout_4->addWidget(lblProj3ScreenUpCode, 1, 0, 1, 1);

        Proj3ScreeenStopCode = new QLineEdit(grpProj3);
        Proj3ScreeenStopCode->setObjectName(QStringLiteral("Proj3ScreeenStopCode"));

        gridLayout_4->addWidget(Proj3ScreeenStopCode, 3, 1, 1, 1);

        Proj3ComPort = new QComboBox(grpProj3);
        Proj3ComPort->setObjectName(QStringLiteral("Proj3ComPort"));

        gridLayout_4->addWidget(Proj3ComPort, 4, 1, 1, 1);

        lblProj3ScreenDownCode = new QLabel(grpProj3);
        lblProj3ScreenDownCode->setObjectName(QStringLiteral("lblProj3ScreenDownCode"));

        gridLayout_4->addWidget(lblProj3ScreenDownCode, 2, 0, 1, 1);

        lblProj3ScreenStopCode = new QLabel(grpProj3);
        lblProj3ScreenStopCode->setObjectName(QStringLiteral("lblProj3ScreenStopCode"));

        gridLayout_4->addWidget(lblProj3ScreenStopCode, 3, 0, 1, 1);

        Proj3ScreenUpCode = new QLineEdit(grpProj3);
        Proj3ScreenUpCode->setObjectName(QStringLiteral("Proj3ScreenUpCode"));

        gridLayout_4->addWidget(Proj3ScreenUpCode, 1, 1, 1, 1);

        Proj3ScreenDownCode = new QLineEdit(grpProj3);
        Proj3ScreenDownCode->setObjectName(QStringLiteral("Proj3ScreenDownCode"));

        gridLayout_4->addWidget(Proj3ScreenDownCode, 2, 1, 1, 1);

        Proj3Address = new QLineEdit(grpProj3);
        Proj3Address->setObjectName(QStringLiteral("Proj3Address"));

        gridLayout_4->addWidget(Proj3Address, 5, 1, 1, 1);

        lblProj3Input = new QLabel(grpProj3);
        lblProj3Input->setObjectName(QStringLiteral("lblProj3Input"));

        gridLayout_4->addWidget(lblProj3Input, 6, 0, 1, 1);

        Proj3Input = new QComboBox(grpProj3);
        Proj3Input->setObjectName(QStringLiteral("Proj3Input"));

        gridLayout_4->addWidget(Proj3Input, 6, 1, 1, 1);

        lblProj3Address = new QLabel(grpProj3);
        lblProj3Address->setObjectName(QStringLiteral("lblProj3Address"));

        gridLayout_4->addWidget(lblProj3Address, 5, 0, 1, 1);

        lblProj3Comport = new QLabel(grpProj3);
        lblProj3Comport->setObjectName(QStringLiteral("lblProj3Comport"));

        gridLayout_4->addWidget(lblProj3Comport, 4, 0, 1, 1);

        Proj3Name = new QLineEdit(grpProj3);
        Proj3Name->setObjectName(QStringLiteral("Proj3Name"));

        gridLayout_4->addWidget(Proj3Name, 0, 1, 1, 1);

        lblProj3Name = new QLabel(grpProj3);
        lblProj3Name->setObjectName(QStringLiteral("lblProj3Name"));

        gridLayout_4->addWidget(lblProj3Name, 0, 0, 1, 1);


        gridLayout->addWidget(grpProj3, 0, 2, 1, 1);

        buttonBox = new QDialogButtonBox(Settings);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 5, 0, 1, 3);

        groupBox = new QGroupBox(Settings);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        btnSerialSettings = new QPushButton(groupBox);
        btnSerialSettings->setObjectName(QStringLiteral("btnSerialSettings"));

        verticalLayout->addWidget(btnSerialSettings);

        cmbMode = new QComboBox(groupBox);
        cmbMode->setObjectName(QStringLiteral("cmbMode"));

        verticalLayout->addWidget(cmbMode);

        cbFullscreen = new QCheckBox(groupBox);
        cbFullscreen->setObjectName(QStringLiteral("cbFullscreen"));

        verticalLayout->addWidget(cbFullscreen);

        verticalSpacer = new QSpacerItem(20, 143, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        gridLayout->addWidget(groupBox, 3, 2, 1, 1);


        retranslateUi(Settings);
        QObject::connect(buttonBox, SIGNAL(rejected()), Settings, SLOT(reject()));
        QObject::connect(buttonBox, SIGNAL(accepted()), Settings, SLOT(accept()));

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "Dialog", 0));
        grpMainSettings->setTitle(QApplication::translate("Settings", "Other Settings", 0));
        MatrixAddress->setText(QApplication::translate("Settings", "cgdmatrix", 0));
        label_12->setText(QApplication::translate("Settings", "TextLabel", 0));
        label_11->setText(QApplication::translate("Settings", "TextLabel", 0));
        lblMatrixAddr->setText(QApplication::translate("Settings", "Matrix Address", 0));
        label_22->setText(QApplication::translate("Settings", "TextLabel", 0));
        grpProj4->setTitle(QApplication::translate("Settings", "Projector 4", 0));
        Proj4ScreenDownCode->setText(QApplication::translate("Settings", "FF 10 11 00 EE", 0));
        lblProj4Address->setText(QApplication::translate("Settings", "Projector address", 0));
        lblProj4ScreenDownCode->setText(QApplication::translate("Settings", "Screen down code", 0));
        lblProj4ScreenStopCode->setText(QApplication::translate("Settings", "Screen stop code", 0));
        lblProj4ScreenUpCode->setText(QApplication::translate("Settings", "Screen up code", 0));
        Proj4ScreenUpCode->setText(QApplication::translate("Settings", "FF 10 11 00 DD", 0));
        lblProj4ComPort->setText(QApplication::translate("Settings", "Com Port", 0));
        lblProj4Input->setText(QApplication::translate("Settings", "Projector input", 0));
        Proj4Address->setText(QApplication::translate("Settings", "cgdmainhallrear", 0));
        Proj4ScreenStopCode->setText(QApplication::translate("Settings", "FF 10 11 00 CC", 0));
        lblProj4Name->setText(QApplication::translate("Settings", "Name", 0));
        grpProj1->setTitle(QApplication::translate("Settings", "Projector 1", 0));
        Proj1ScreenDownCode->setText(QApplication::translate("Settings", "FF 10 11 00 EE", 0));
        lblProj1ProjectorAddr->setText(QApplication::translate("Settings", "Projector Address", 0));
        Proj1Address->setText(QApplication::translate("Settings", "cgdmainhallSR", 0));
        Proj1ScreenStopCode->setText(QApplication::translate("Settings", "FF 10 11 00 CC", 0));
        lblProj1ScnStopCode->setText(QApplication::translate("Settings", "Screen stop code", 0));
        Proj1ScreenUpCode->setText(QApplication::translate("Settings", "FF 10 11 00 DD", 0));
        lblProj1ScnDownCode->setText(QApplication::translate("Settings", "Screen down code", 0));
        lblProj1ScnUpCode->setText(QApplication::translate("Settings", "Screen up code", 0));
        lblProj1ComPort->setText(QApplication::translate("Settings", "Com Port", 0));
        lblProj1Input->setText(QApplication::translate("Settings", "Projector input", 0));
        lblProjName->setText(QApplication::translate("Settings", "Name", 0));
        grpProj2->setTitle(QApplication::translate("Settings", "Projector 2", 0));
        Proj2ScreenUpCode->setText(QApplication::translate("Settings", "FF 10 11 00 DD", 0));
        lblProj2ScreenDown->setText(QApplication::translate("Settings", "Screen down code", 0));
        Proj2Address->setText(QApplication::translate("Settings", "10.160.100.214", 0));
        lblProj2Address->setText(QApplication::translate("Settings", "Projector address", 0));
        Proj2ScreenDownCode->setText(QApplication::translate("Settings", "FF 10 11 00 EE", 0));
        lblProj2ScreenUp->setText(QApplication::translate("Settings", "Screen up code", 0));
        lblProj2ScreenStop->setText(QApplication::translate("Settings", "Screen stop code", 0));
        Proj2ScreenStopCode->setText(QApplication::translate("Settings", "FF 10 11 00 CC", 0));
        lblProj2ComPort->setText(QApplication::translate("Settings", "Com Port", 0));
        lblProj2Input->setText(QApplication::translate("Settings", "Projector input", 0));
        lblProj2Name->setText(QApplication::translate("Settings", "Name", 0));
        grpProj3->setTitle(QApplication::translate("Settings", "Projector 3", 0));
        lblProj3ScreenUpCode->setText(QApplication::translate("Settings", "Screen up code", 0));
        Proj3ScreeenStopCode->setText(QApplication::translate("Settings", "FF 10 11 00 CC", 0));
        lblProj3ScreenDownCode->setText(QApplication::translate("Settings", "Screen down code", 0));
        lblProj3ScreenStopCode->setText(QApplication::translate("Settings", "Screen stop code", 0));
        Proj3ScreenUpCode->setText(QApplication::translate("Settings", "FF 10 11 00 DD", 0));
        Proj3ScreenDownCode->setText(QApplication::translate("Settings", "FF 10 11 00 EE", 0));
        Proj3Address->setText(QApplication::translate("Settings", "cgdmainhallSL", 0));
        lblProj3Input->setText(QApplication::translate("Settings", "Projector input", 0));
        lblProj3Address->setText(QApplication::translate("Settings", "Projector address", 0));
        lblProj3Comport->setText(QApplication::translate("Settings", "Com Port", 0));
        lblProj3Name->setText(QApplication::translate("Settings", "Name", 0));
        groupBox->setTitle(QString());
        btnSerialSettings->setText(QApplication::translate("Settings", "Serial Port Settings", 0));
        cmbMode->clear();
        cmbMode->insertItems(0, QStringList()
         << QApplication::translate("Settings", "Simple Mode", 0)
         << QApplication::translate("Settings", "Advanced Mode", 0)
        );
        cbFullscreen->setText(QApplication::translate("Settings", "Fullscreen", 0));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
