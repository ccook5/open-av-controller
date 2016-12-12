/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGroupBox *grpSLProj;
    QGridLayout *gridLayout_4;
    QLabel *lblStatusSL;
    QComboBox *cmbSLProj;
    QPushButton *btnSLProj;
    QLabel *lblScrDownCodeSL;
    QLabel *lblScrStopCodeSL;
    QLineEdit *editScrStopCodeSL;
    QLabel *lblScrUpCodeSL;
    QLabel *lblScrComPortSL;
    QLineEdit *editProjAddrSL;
    QLabel *lblProjAddrSL;
    QLineEdit *editScrUpCodeSL;
    QComboBox *cbScrComPortSL;
    QLineEdit *editScrDownCodeSL;
    QLineEdit *editProjPasswordSL;
    QLabel *lblProjPasswordSL;
    QGroupBox *grpRearProj;
    QGridLayout *gridLayout_6;
    QLabel *lblScrStopCodeRR;
    QLineEdit *editScrDownCodeRR;
    QLabel *lblScrUpCodeRR;
    QLabel *lblScrDownCodeRR;
    QLineEdit *editProjAddrRR;
    QLineEdit *editScrUpCodeRR;
    QComboBox *cbScrComPortRR;
    QLabel *lblProjAddrRR;
    QLineEdit *editScrStopCodeRR;
    QLabel *lblScrComPortRR;
    QPushButton *btnRearProj;
    QComboBox *cmbRearProj;
    QLabel *lblStatusRR;
    QLineEdit *editProjPasswordRR;
    QLabel *lblProjPasswordRR;
    QGroupBox *gbSettings;
    QVBoxLayout *verticalLayout_6;
    QPushButton *btnSettings;
    QPushButton *btnMinimize;
    QPushButton *pushButton;
    QSpacerItem *verticalSpacer;
    QLabel *lblStatusSettings;
    QLabel *lblStatus;
    QDialogButtonBox *buttonBox;
    QGroupBox *grpMainSettings;
    QGridLayout *gridLayout_5;
    QLabel *label_10;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *lineEdit_12;
    QGroupBox *gbxSRProj;
    QGridLayout *gridLayout;
    QLabel *lblScrUpCodeSR;
    QLineEdit *editScrStopCodeSR;
    QComboBox *cbScrComPortSR;
    QLabel *lblScrComPortSR;
    QPushButton *btnSRProj;
    QLineEdit *editScrUpCodeSR;
    QComboBox *cmbSRProj;
    QLabel *lblScrStopCodeSR;
    QLabel *lblProjAddrSR;
    QLineEdit *editProjAddrSR;
    QLineEdit *editScrDownCodeSR;
    QLabel *lblScrDownCodeSR;
    QLineEdit *editProjPasswordSR;
    QLabel *lblProjPasswordSR;
    QLabel *lblStatusSR;
    QGroupBox *grpFrontProj;
    QGridLayout *gridLayout_3;
    QLabel *lblScrUpCodeFR;
    QComboBox *cbScrComPortFR;
    QPushButton *btnFrontProj;
    QComboBox *cmbFrontProj;
    QLineEdit *editScrDownCodeFR;
    QLabel *lblScrDownCodeFR;
    QLabel *lblScrStopCodeFR;
    QLineEdit *editProjAddrFR;
    QLineEdit *editScrUpCodeFR;
    QLabel *lblScrComPortFR;
    QLabel *lblProjAddrFR;
    QLineEdit *editScrStopCodeFR;
    QLineEdit *editProjPasswordFR;
    QLabel *lblProjPasswordFr;
    QLabel *lblStatusFR;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(875, 630);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        grpSLProj = new QGroupBox(centralwidget);
        grpSLProj->setObjectName(QStringLiteral("grpSLProj"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(grpSLProj->sizePolicy().hasHeightForWidth());
        grpSLProj->setSizePolicy(sizePolicy);
        gridLayout_4 = new QGridLayout(grpSLProj);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        lblStatusSL = new QLabel(grpSLProj);
        lblStatusSL->setObjectName(QStringLiteral("lblStatusSL"));

        gridLayout_4->addWidget(lblStatusSL, 2, 0, 1, 3);

        cmbSLProj = new QComboBox(grpSLProj);
        cmbSLProj->setObjectName(QStringLiteral("cmbSLProj"));

        gridLayout_4->addWidget(cmbSLProj, 1, 0, 1, 3);

        btnSLProj = new QPushButton(grpSLProj);
        btnSLProj->setObjectName(QStringLiteral("btnSLProj"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnSLProj->sizePolicy().hasHeightForWidth());
        btnSLProj->setSizePolicy(sizePolicy1);
        btnSLProj->setMinimumSize(QSize(0, 0));

        gridLayout_4->addWidget(btnSLProj, 0, 0, 1, 3);

        lblScrDownCodeSL = new QLabel(grpSLProj);
        lblScrDownCodeSL->setObjectName(QStringLiteral("lblScrDownCodeSL"));

        gridLayout_4->addWidget(lblScrDownCodeSL, 4, 0, 1, 1);

        lblScrStopCodeSL = new QLabel(grpSLProj);
        lblScrStopCodeSL->setObjectName(QStringLiteral("lblScrStopCodeSL"));

        gridLayout_4->addWidget(lblScrStopCodeSL, 5, 0, 1, 1);

        editScrStopCodeSL = new QLineEdit(grpSLProj);
        editScrStopCodeSL->setObjectName(QStringLiteral("editScrStopCodeSL"));

        gridLayout_4->addWidget(editScrStopCodeSL, 5, 2, 1, 1);

        lblScrUpCodeSL = new QLabel(grpSLProj);
        lblScrUpCodeSL->setObjectName(QStringLiteral("lblScrUpCodeSL"));

        gridLayout_4->addWidget(lblScrUpCodeSL, 3, 0, 1, 1);

        lblScrComPortSL = new QLabel(grpSLProj);
        lblScrComPortSL->setObjectName(QStringLiteral("lblScrComPortSL"));

        gridLayout_4->addWidget(lblScrComPortSL, 6, 0, 1, 1);

        editProjAddrSL = new QLineEdit(grpSLProj);
        editProjAddrSL->setObjectName(QStringLiteral("editProjAddrSL"));

        gridLayout_4->addWidget(editProjAddrSL, 7, 2, 1, 1);

        lblProjAddrSL = new QLabel(grpSLProj);
        lblProjAddrSL->setObjectName(QStringLiteral("lblProjAddrSL"));

        gridLayout_4->addWidget(lblProjAddrSL, 7, 0, 1, 1);

        editScrUpCodeSL = new QLineEdit(grpSLProj);
        editScrUpCodeSL->setObjectName(QStringLiteral("editScrUpCodeSL"));

        gridLayout_4->addWidget(editScrUpCodeSL, 3, 2, 1, 1);

        cbScrComPortSL = new QComboBox(grpSLProj);
        cbScrComPortSL->setObjectName(QStringLiteral("cbScrComPortSL"));

        gridLayout_4->addWidget(cbScrComPortSL, 6, 2, 1, 1);

        editScrDownCodeSL = new QLineEdit(grpSLProj);
        editScrDownCodeSL->setObjectName(QStringLiteral("editScrDownCodeSL"));

        gridLayout_4->addWidget(editScrDownCodeSL, 4, 2, 1, 1);

        editProjPasswordSL = new QLineEdit(grpSLProj);
        editProjPasswordSL->setObjectName(QStringLiteral("editProjPasswordSL"));

        gridLayout_4->addWidget(editProjPasswordSL, 8, 2, 1, 1);

        lblProjPasswordSL = new QLabel(grpSLProj);
        lblProjPasswordSL->setObjectName(QStringLiteral("lblProjPasswordSL"));

        gridLayout_4->addWidget(lblProjPasswordSL, 8, 0, 1, 1);


        gridLayout_2->addWidget(grpSLProj, 0, 4, 2, 1);

        grpRearProj = new QGroupBox(centralwidget);
        grpRearProj->setObjectName(QStringLiteral("grpRearProj"));
        gridLayout_6 = new QGridLayout(grpRearProj);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        lblScrStopCodeRR = new QLabel(grpRearProj);
        lblScrStopCodeRR->setObjectName(QStringLiteral("lblScrStopCodeRR"));

        gridLayout_6->addWidget(lblScrStopCodeRR, 5, 0, 1, 1);

        editScrDownCodeRR = new QLineEdit(grpRearProj);
        editScrDownCodeRR->setObjectName(QStringLiteral("editScrDownCodeRR"));

        gridLayout_6->addWidget(editScrDownCodeRR, 4, 1, 1, 1);

        lblScrUpCodeRR = new QLabel(grpRearProj);
        lblScrUpCodeRR->setObjectName(QStringLiteral("lblScrUpCodeRR"));

        gridLayout_6->addWidget(lblScrUpCodeRR, 3, 0, 1, 1);

        lblScrDownCodeRR = new QLabel(grpRearProj);
        lblScrDownCodeRR->setObjectName(QStringLiteral("lblScrDownCodeRR"));

        gridLayout_6->addWidget(lblScrDownCodeRR, 4, 0, 1, 1);

        editProjAddrRR = new QLineEdit(grpRearProj);
        editProjAddrRR->setObjectName(QStringLiteral("editProjAddrRR"));

        gridLayout_6->addWidget(editProjAddrRR, 7, 1, 1, 1);

        editScrUpCodeRR = new QLineEdit(grpRearProj);
        editScrUpCodeRR->setObjectName(QStringLiteral("editScrUpCodeRR"));

        gridLayout_6->addWidget(editScrUpCodeRR, 3, 1, 1, 1);

        cbScrComPortRR = new QComboBox(grpRearProj);
        cbScrComPortRR->setObjectName(QStringLiteral("cbScrComPortRR"));

        gridLayout_6->addWidget(cbScrComPortRR, 6, 1, 1, 1);

        lblProjAddrRR = new QLabel(grpRearProj);
        lblProjAddrRR->setObjectName(QStringLiteral("lblProjAddrRR"));

        gridLayout_6->addWidget(lblProjAddrRR, 7, 0, 1, 1);

        editScrStopCodeRR = new QLineEdit(grpRearProj);
        editScrStopCodeRR->setObjectName(QStringLiteral("editScrStopCodeRR"));

        gridLayout_6->addWidget(editScrStopCodeRR, 5, 1, 1, 1);

        lblScrComPortRR = new QLabel(grpRearProj);
        lblScrComPortRR->setObjectName(QStringLiteral("lblScrComPortRR"));

        gridLayout_6->addWidget(lblScrComPortRR, 6, 0, 1, 1);

        btnRearProj = new QPushButton(grpRearProj);
        btnRearProj->setObjectName(QStringLiteral("btnRearProj"));
        sizePolicy1.setHeightForWidth(btnRearProj->sizePolicy().hasHeightForWidth());
        btnRearProj->setSizePolicy(sizePolicy1);
        btnRearProj->setMinimumSize(QSize(0, 20));

        gridLayout_6->addWidget(btnRearProj, 0, 0, 1, 2);

        cmbRearProj = new QComboBox(grpRearProj);
        cmbRearProj->setObjectName(QStringLiteral("cmbRearProj"));

        gridLayout_6->addWidget(cmbRearProj, 1, 0, 1, 2);

        lblStatusRR = new QLabel(grpRearProj);
        lblStatusRR->setObjectName(QStringLiteral("lblStatusRR"));

        gridLayout_6->addWidget(lblStatusRR, 2, 0, 1, 2);

        editProjPasswordRR = new QLineEdit(grpRearProj);
        editProjPasswordRR->setObjectName(QStringLiteral("editProjPasswordRR"));

        gridLayout_6->addWidget(editProjPasswordRR, 8, 1, 1, 1);

        lblProjPasswordRR = new QLabel(grpRearProj);
        lblProjPasswordRR->setObjectName(QStringLiteral("lblProjPasswordRR"));

        gridLayout_6->addWidget(lblProjPasswordRR, 8, 0, 1, 1);


        gridLayout_2->addWidget(grpRearProj, 2, 2, 2, 1);

        gbSettings = new QGroupBox(centralwidget);
        gbSettings->setObjectName(QStringLiteral("gbSettings"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(gbSettings->sizePolicy().hasHeightForWidth());
        gbSettings->setSizePolicy(sizePolicy2);
        verticalLayout_6 = new QVBoxLayout(gbSettings);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        btnSettings = new QPushButton(gbSettings);
        btnSettings->setObjectName(QStringLiteral("btnSettings"));
        sizePolicy1.setHeightForWidth(btnSettings->sizePolicy().hasHeightForWidth());
        btnSettings->setSizePolicy(sizePolicy1);

        verticalLayout_6->addWidget(btnSettings);

        btnMinimize = new QPushButton(gbSettings);
        btnMinimize->setObjectName(QStringLiteral("btnMinimize"));

        verticalLayout_6->addWidget(btnMinimize);

        pushButton = new QPushButton(gbSettings);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_6->addWidget(pushButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);

        lblStatusSettings = new QLabel(gbSettings);
        lblStatusSettings->setObjectName(QStringLiteral("lblStatusSettings"));

        verticalLayout_6->addWidget(lblStatusSettings);


        gridLayout_2->addWidget(gbSettings, 2, 4, 2, 1);

        lblStatus = new QLabel(centralwidget);
        lblStatus->setObjectName(QStringLiteral("lblStatus"));

        gridLayout_2->addWidget(lblStatus, 4, 0, 1, 1);

        buttonBox = new QDialogButtonBox(centralwidget);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 5, 3, 1, 2);

        grpMainSettings = new QGroupBox(centralwidget);
        grpMainSettings->setObjectName(QStringLiteral("grpMainSettings"));
        sizePolicy2.setHeightForWidth(grpMainSettings->sizePolicy().hasHeightForWidth());
        grpMainSettings->setSizePolicy(sizePolicy2);
        gridLayout_5 = new QGridLayout(grpMainSettings);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        label_10 = new QLabel(grpMainSettings);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_5->addWidget(label_10, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_2, 1, 1, 1, 1);

        lineEdit_12 = new QLineEdit(grpMainSettings);
        lineEdit_12->setObjectName(QStringLiteral("lineEdit_12"));

        gridLayout_5->addWidget(lineEdit_12, 0, 1, 1, 1);


        gridLayout_2->addWidget(grpMainSettings, 2, 0, 2, 1);

        gbxSRProj = new QGroupBox(centralwidget);
        gbxSRProj->setObjectName(QStringLiteral("gbxSRProj"));
        gbxSRProj->setEnabled(true);
        sizePolicy.setHeightForWidth(gbxSRProj->sizePolicy().hasHeightForWidth());
        gbxSRProj->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(gbxSRProj);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lblScrUpCodeSR = new QLabel(gbxSRProj);
        lblScrUpCodeSR->setObjectName(QStringLiteral("lblScrUpCodeSR"));

        gridLayout->addWidget(lblScrUpCodeSR, 3, 0, 1, 1);

        editScrStopCodeSR = new QLineEdit(gbxSRProj);
        editScrStopCodeSR->setObjectName(QStringLiteral("editScrStopCodeSR"));

        gridLayout->addWidget(editScrStopCodeSR, 5, 1, 1, 1);

        cbScrComPortSR = new QComboBox(gbxSRProj);
        cbScrComPortSR->setObjectName(QStringLiteral("cbScrComPortSR"));

        gridLayout->addWidget(cbScrComPortSR, 6, 1, 1, 1);

        lblScrComPortSR = new QLabel(gbxSRProj);
        lblScrComPortSR->setObjectName(QStringLiteral("lblScrComPortSR"));

        gridLayout->addWidget(lblScrComPortSR, 6, 0, 1, 1);

        btnSRProj = new QPushButton(gbxSRProj);
        btnSRProj->setObjectName(QStringLiteral("btnSRProj"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(20);
        sizePolicy3.setHeightForWidth(btnSRProj->sizePolicy().hasHeightForWidth());
        btnSRProj->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(btnSRProj, 0, 0, 1, 2);

        editScrUpCodeSR = new QLineEdit(gbxSRProj);
        editScrUpCodeSR->setObjectName(QStringLiteral("editScrUpCodeSR"));

        gridLayout->addWidget(editScrUpCodeSR, 3, 1, 1, 1);

        cmbSRProj = new QComboBox(gbxSRProj);
        cmbSRProj->setObjectName(QStringLiteral("cmbSRProj"));

        gridLayout->addWidget(cmbSRProj, 1, 0, 1, 2);

        lblScrStopCodeSR = new QLabel(gbxSRProj);
        lblScrStopCodeSR->setObjectName(QStringLiteral("lblScrStopCodeSR"));

        gridLayout->addWidget(lblScrStopCodeSR, 5, 0, 1, 1);

        lblProjAddrSR = new QLabel(gbxSRProj);
        lblProjAddrSR->setObjectName(QStringLiteral("lblProjAddrSR"));

        gridLayout->addWidget(lblProjAddrSR, 7, 0, 1, 1);

        editProjAddrSR = new QLineEdit(gbxSRProj);
        editProjAddrSR->setObjectName(QStringLiteral("editProjAddrSR"));

        gridLayout->addWidget(editProjAddrSR, 7, 1, 1, 1);

        editScrDownCodeSR = new QLineEdit(gbxSRProj);
        editScrDownCodeSR->setObjectName(QStringLiteral("editScrDownCodeSR"));

        gridLayout->addWidget(editScrDownCodeSR, 4, 1, 1, 1);

        lblScrDownCodeSR = new QLabel(gbxSRProj);
        lblScrDownCodeSR->setObjectName(QStringLiteral("lblScrDownCodeSR"));

        gridLayout->addWidget(lblScrDownCodeSR, 4, 0, 1, 1);

        editProjPasswordSR = new QLineEdit(gbxSRProj);
        editProjPasswordSR->setObjectName(QStringLiteral("editProjPasswordSR"));

        gridLayout->addWidget(editProjPasswordSR, 8, 1, 1, 1);

        lblProjPasswordSR = new QLabel(gbxSRProj);
        lblProjPasswordSR->setObjectName(QStringLiteral("lblProjPasswordSR"));

        gridLayout->addWidget(lblProjPasswordSR, 8, 0, 1, 1);

        lblStatusSR = new QLabel(gbxSRProj);
        lblStatusSR->setObjectName(QStringLiteral("lblStatusSR"));

        gridLayout->addWidget(lblStatusSR, 2, 0, 1, 2);


        gridLayout_2->addWidget(gbxSRProj, 0, 0, 2, 1);

        grpFrontProj = new QGroupBox(centralwidget);
        grpFrontProj->setObjectName(QStringLiteral("grpFrontProj"));
        sizePolicy.setHeightForWidth(grpFrontProj->sizePolicy().hasHeightForWidth());
        grpFrontProj->setSizePolicy(sizePolicy);
        gridLayout_3 = new QGridLayout(grpFrontProj);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        lblScrUpCodeFR = new QLabel(grpFrontProj);
        lblScrUpCodeFR->setObjectName(QStringLiteral("lblScrUpCodeFR"));

        gridLayout_3->addWidget(lblScrUpCodeFR, 3, 0, 1, 1);

        cbScrComPortFR = new QComboBox(grpFrontProj);
        cbScrComPortFR->setObjectName(QStringLiteral("cbScrComPortFR"));

        gridLayout_3->addWidget(cbScrComPortFR, 6, 1, 1, 1);

        btnFrontProj = new QPushButton(grpFrontProj);
        btnFrontProj->setObjectName(QStringLiteral("btnFrontProj"));
        sizePolicy3.setHeightForWidth(btnFrontProj->sizePolicy().hasHeightForWidth());
        btnFrontProj->setSizePolicy(sizePolicy3);

        gridLayout_3->addWidget(btnFrontProj, 0, 0, 1, 2);

        cmbFrontProj = new QComboBox(grpFrontProj);
        cmbFrontProj->setObjectName(QStringLiteral("cmbFrontProj"));

        gridLayout_3->addWidget(cmbFrontProj, 1, 0, 1, 2);

        editScrDownCodeFR = new QLineEdit(grpFrontProj);
        editScrDownCodeFR->setObjectName(QStringLiteral("editScrDownCodeFR"));

        gridLayout_3->addWidget(editScrDownCodeFR, 4, 1, 1, 1);

        lblScrDownCodeFR = new QLabel(grpFrontProj);
        lblScrDownCodeFR->setObjectName(QStringLiteral("lblScrDownCodeFR"));

        gridLayout_3->addWidget(lblScrDownCodeFR, 4, 0, 1, 1);

        lblScrStopCodeFR = new QLabel(grpFrontProj);
        lblScrStopCodeFR->setObjectName(QStringLiteral("lblScrStopCodeFR"));

        gridLayout_3->addWidget(lblScrStopCodeFR, 5, 0, 1, 1);

        editProjAddrFR = new QLineEdit(grpFrontProj);
        editProjAddrFR->setObjectName(QStringLiteral("editProjAddrFR"));

        gridLayout_3->addWidget(editProjAddrFR, 7, 1, 1, 1);

        editScrUpCodeFR = new QLineEdit(grpFrontProj);
        editScrUpCodeFR->setObjectName(QStringLiteral("editScrUpCodeFR"));

        gridLayout_3->addWidget(editScrUpCodeFR, 3, 1, 1, 1);

        lblScrComPortFR = new QLabel(grpFrontProj);
        lblScrComPortFR->setObjectName(QStringLiteral("lblScrComPortFR"));

        gridLayout_3->addWidget(lblScrComPortFR, 6, 0, 1, 1);

        lblProjAddrFR = new QLabel(grpFrontProj);
        lblProjAddrFR->setObjectName(QStringLiteral("lblProjAddrFR"));

        gridLayout_3->addWidget(lblProjAddrFR, 7, 0, 1, 1);

        editScrStopCodeFR = new QLineEdit(grpFrontProj);
        editScrStopCodeFR->setObjectName(QStringLiteral("editScrStopCodeFR"));

        gridLayout_3->addWidget(editScrStopCodeFR, 5, 1, 1, 1);

        editProjPasswordFR = new QLineEdit(grpFrontProj);
        editProjPasswordFR->setObjectName(QStringLiteral("editProjPasswordFR"));

        gridLayout_3->addWidget(editProjPasswordFR, 8, 1, 1, 1);

        lblProjPasswordFr = new QLabel(grpFrontProj);
        lblProjPasswordFr->setObjectName(QStringLiteral("lblProjPasswordFr"));

        gridLayout_3->addWidget(lblProjPasswordFr, 8, 0, 1, 1);

        lblStatusFR = new QLabel(grpFrontProj);
        lblStatusFR->setObjectName(QStringLiteral("lblStatusFR"));

        gridLayout_3->addWidget(lblStatusFR, 2, 0, 1, 2);

        lblScrComPortFR->raise();
        lblScrUpCodeFR->raise();
        editScrDownCodeFR->raise();
        lblScrStopCodeFR->raise();
        editScrStopCodeFR->raise();
        lblScrDownCodeFR->raise();
        editScrUpCodeFR->raise();
        lblProjAddrFR->raise();
        editProjAddrFR->raise();
        cbScrComPortFR->raise();
        btnFrontProj->raise();
        cmbFrontProj->raise();
        lblStatusFR->raise();
        editProjPasswordFR->raise();
        lblProjPasswordFr->raise();

        gridLayout_2->addWidget(grpFrontProj, 0, 2, 2, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 875, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Projector Controller", 0));
        grpSLProj->setTitle(QApplication::translate("MainWindow", "Stage Left Projector", 0));
        lblStatusSL->setText(QApplication::translate("MainWindow", "waiting...", 0));
        cmbSLProj->clear();
        cmbSLProj->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1. PC", 0)
         << QApplication::translate("MainWindow", "2. Blu Ray", 0)
         << QApplication::translate("MainWindow", "3. Xibo", 0)
         << QString()
        );
        btnSLProj->setText(QApplication::translate("MainWindow", "Power On", 0));
        lblScrDownCodeSL->setText(QApplication::translate("MainWindow", "Screen down code", 0));
        lblScrStopCodeSL->setText(QApplication::translate("MainWindow", "Screen stop code", 0));
        editScrStopCodeSL->setText(QApplication::translate("MainWindow", "FF 10 11 00 CC", 0));
        lblScrUpCodeSL->setText(QApplication::translate("MainWindow", "Screen up code", 0));
        lblScrComPortSL->setText(QApplication::translate("MainWindow", "Com Port", 0));
        editProjAddrSL->setText(QApplication::translate("MainWindow", "10.160.100.213", 0));
        lblProjAddrSL->setText(QApplication::translate("MainWindow", "Projector address", 0));
        editScrUpCodeSL->setText(QApplication::translate("MainWindow", "FF 10 11 00 DD", 0));
        editScrDownCodeSL->setText(QApplication::translate("MainWindow", "FF 10 11 00 EE", 0));
        editProjPasswordSL->setText(QApplication::translate("MainWindow", "panasonic", 0));
        lblProjPasswordSL->setText(QApplication::translate("MainWindow", "Projector Password", 0));
        grpRearProj->setTitle(QApplication::translate("MainWindow", "Rear Projector", 0));
        lblScrStopCodeRR->setText(QApplication::translate("MainWindow", "Screen stop code", 0));
        editScrDownCodeRR->setText(QApplication::translate("MainWindow", "FF 10 11 00 EE", 0));
        lblScrUpCodeRR->setText(QApplication::translate("MainWindow", "Screen up code", 0));
        lblScrDownCodeRR->setText(QApplication::translate("MainWindow", "Screen down code", 0));
        editProjAddrRR->setText(QApplication::translate("MainWindow", "10.160.100.214", 0));
        editScrUpCodeRR->setText(QApplication::translate("MainWindow", "FF 10 11 00 DD", 0));
        lblProjAddrRR->setText(QApplication::translate("MainWindow", "Projector address", 0));
        editScrStopCodeRR->setText(QApplication::translate("MainWindow", "FF 10 11 00 CC", 0));
        lblScrComPortRR->setText(QApplication::translate("MainWindow", "Com Port", 0));
        btnRearProj->setText(QApplication::translate("MainWindow", "Power On", 0));
        cmbRearProj->clear();
        cmbRearProj->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1. PC", 0)
         << QApplication::translate("MainWindow", "2. Blu Ray", 0)
         << QApplication::translate("MainWindow", "3. Xibo", 0)
        );
        lblStatusRR->setText(QApplication::translate("MainWindow", "waiting...", 0));
        editProjPasswordRR->setText(QApplication::translate("MainWindow", "panasonic", 0));
        lblProjPasswordRR->setText(QApplication::translate("MainWindow", "Projector Password", 0));
        gbSettings->setTitle(QApplication::translate("MainWindow", "-", 0));
        btnSettings->setText(QApplication::translate("MainWindow", "Settings", 0));
        btnMinimize->setText(QApplication::translate("MainWindow", "Minimuze", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Serial Port Info", 0));
        lblStatusSettings->setText(QApplication::translate("MainWindow", "waiting...", 0));
        lblStatus->setText(QApplication::translate("MainWindow", "Status", 0));
        grpMainSettings->setTitle(QApplication::translate("MainWindow", "Other Settings", 0));
        label_10->setText(QApplication::translate("MainWindow", "Matrix Address", 0));
        lineEdit_12->setText(QApplication::translate("MainWindow", "cgdmatrix", 0));
        gbxSRProj->setTitle(QApplication::translate("MainWindow", "Stage Right Projector", 0));
        lblScrUpCodeSR->setText(QApplication::translate("MainWindow", "Screen up code", 0));
        editScrStopCodeSR->setText(QApplication::translate("MainWindow", "FF 10 11 00 CC", 0));
        lblScrComPortSR->setText(QApplication::translate("MainWindow", "Com Port", 0));
        btnSRProj->setText(QApplication::translate("MainWindow", "Power On", 0));
        editScrUpCodeSR->setText(QApplication::translate("MainWindow", "FF 10 11 00 DD", 0));
        cmbSRProj->clear();
        cmbSRProj->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1. PC", 0)
         << QApplication::translate("MainWindow", "2. Blu Ray", 0)
         << QApplication::translate("MainWindow", "3. Xibo", 0)
        );
        lblScrStopCodeSR->setText(QApplication::translate("MainWindow", "Screen stop code", 0));
        lblProjAddrSR->setText(QApplication::translate("MainWindow", "Projector Address", 0));
        editProjAddrSR->setText(QApplication::translate("MainWindow", "169.254.112.241", 0));
        editScrDownCodeSR->setText(QApplication::translate("MainWindow", "FF 10 11 00 EE", 0));
        lblScrDownCodeSR->setText(QApplication::translate("MainWindow", "Screen down code", 0));
        editProjPasswordSR->setText(QApplication::translate("MainWindow", "panasonic", 0));
        lblProjPasswordSR->setText(QApplication::translate("MainWindow", "Projector Password", 0));
        lblStatusSR->setText(QApplication::translate("MainWindow", "waiting...", 0));
        grpFrontProj->setTitle(QApplication::translate("MainWindow", "Front Projector", 0));
        lblScrUpCodeFR->setText(QApplication::translate("MainWindow", "Screen up code", 0));
        btnFrontProj->setText(QApplication::translate("MainWindow", "Power On", 0));
        cmbFrontProj->clear();
        cmbFrontProj->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1. PC", 0)
         << QApplication::translate("MainWindow", "2. Blu Ray", 0)
         << QApplication::translate("MainWindow", "3. Xibo", 0)
        );
        editScrDownCodeFR->setText(QApplication::translate("MainWindow", "FF 10 11 00 EE", 0));
        lblScrDownCodeFR->setText(QApplication::translate("MainWindow", "Screen down code", 0));
        lblScrStopCodeFR->setText(QApplication::translate("MainWindow", "Screen stop code", 0));
        editProjAddrFR->setText(QApplication::translate("MainWindow", "10.160.100.212", 0));
        editScrUpCodeFR->setText(QApplication::translate("MainWindow", "FF 10 11 00 DD", 0));
        lblScrComPortFR->setText(QApplication::translate("MainWindow", "Com Port", 0));
        lblProjAddrFR->setText(QApplication::translate("MainWindow", "Projector address", 0));
        editScrStopCodeFR->setText(QApplication::translate("MainWindow", "FF 10 11 00 CC", 0));
        editProjPasswordFR->setText(QApplication::translate("MainWindow", "panasonic", 0));
        lblProjPasswordFr->setText(QApplication::translate("MainWindow", "Projector Password", 0));
        lblStatusFR->setText(QApplication::translate("MainWindow", "waiting...", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
