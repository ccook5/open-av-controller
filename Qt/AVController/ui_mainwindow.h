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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *gbxTake;
    QGridLayout *gridLayout_6;
    QPushButton *btnSrcPC;
    QPushButton *btnSrcLaptop;
    QGroupBox *gbxProj4;
    QGridLayout *gridLayout_5;
    QPushButton *btnProj4On;
    QPushButton *btnProj4Off;
    QComboBox *cmbProj4;
    QLabel *lblStatus4;
    QGroupBox *gbxProj3;
    QGridLayout *gridLayout_4;
    QPushButton *btnProj3On;
    QPushButton *btnProj3Off;
    QComboBox *cmbProj3;
    QLabel *lblStatus3;
    QGroupBox *gbxProj2;
    QGridLayout *gridLayout_3;
    QPushButton *btnProj2On;
    QPushButton *btnProj2Off;
    QComboBox *cmbProj2;
    QLabel *lblStatus2;
    QGroupBox *gbxProj1;
    QGridLayout *gridLayout_2;
    QPushButton *btnProj1On;
    QPushButton *btnProj1Off;
    QComboBox *cmbProj1;
    QLabel *lblStatus1;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_6;
    QPushButton *btnSettings;
    QPushButton *btnMinimize;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(673, 390);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        MainWindow->setMouseTracking(true);
        MainWindow->setWindowOpacity(1);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gbxTake = new QGroupBox(centralwidget);
        gbxTake->setObjectName(QStringLiteral("gbxTake"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(gbxTake->sizePolicy().hasHeightForWidth());
        gbxTake->setSizePolicy(sizePolicy1);
        gridLayout_6 = new QGridLayout(gbxTake);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        btnSrcPC = new QPushButton(gbxTake);
        btnSrcPC->setObjectName(QStringLiteral("btnSrcPC"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnSrcPC->sizePolicy().hasHeightForWidth());
        btnSrcPC->setSizePolicy(sizePolicy2);
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        btnSrcPC->setFont(font);

        gridLayout_6->addWidget(btnSrcPC, 0, 0, 1, 1);

        btnSrcLaptop = new QPushButton(gbxTake);
        btnSrcLaptop->setObjectName(QStringLiteral("btnSrcLaptop"));
        sizePolicy2.setHeightForWidth(btnSrcLaptop->sizePolicy().hasHeightForWidth());
        btnSrcLaptop->setSizePolicy(sizePolicy2);
        btnSrcLaptop->setFont(font);

        gridLayout_6->addWidget(btnSrcLaptop, 1, 0, 1, 1);


        gridLayout->addWidget(gbxTake, 1, 0, 1, 1);

        gbxProj4 = new QGroupBox(centralwidget);
        gbxProj4->setObjectName(QStringLiteral("gbxProj4"));
        sizePolicy1.setHeightForWidth(gbxProj4->sizePolicy().hasHeightForWidth());
        gbxProj4->setSizePolicy(sizePolicy1);
        gridLayout_5 = new QGridLayout(gbxProj4);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        btnProj4On = new QPushButton(gbxProj4);
        btnProj4On->setObjectName(QStringLiteral("btnProj4On"));
        sizePolicy2.setHeightForWidth(btnProj4On->sizePolicy().hasHeightForWidth());
        btnProj4On->setSizePolicy(sizePolicy2);
        btnProj4On->setMinimumSize(QSize(0, 50));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 170, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(0, 255, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(0, 212, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(0, 85, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(0, 113, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(127, 212, 127, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        btnProj4On->setPalette(palette);
        btnProj4On->setFont(font);
        btnProj4On->setAutoFillBackground(true);

        gridLayout_5->addWidget(btnProj4On, 0, 0, 1, 1);

        btnProj4Off = new QPushButton(gbxProj4);
        btnProj4Off->setObjectName(QStringLiteral("btnProj4Off"));
        sizePolicy2.setHeightForWidth(btnProj4Off->sizePolicy().hasHeightForWidth());
        btnProj4Off->setSizePolicy(sizePolicy2);
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush9(QColor(170, 0, 0, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush9);
        QBrush brush10(QColor(255, 0, 0, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush10);
        QBrush brush11(QColor(212, 0, 0, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush11);
        QBrush brush12(QColor(85, 0, 0, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush12);
        QBrush brush13(QColor(113, 0, 0, 255));
        brush13.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Mid, brush13);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush14(QColor(212, 127, 127, 255));
        brush14.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::AlternateBase, brush14);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush10);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush11);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette1.setBrush(QPalette::Inactive, QPalette::Mid, brush13);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush14);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush10);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush11);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Mid, brush13);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        btnProj4Off->setPalette(palette1);
        btnProj4Off->setFont(font);
        btnProj4Off->setAutoFillBackground(true);

        gridLayout_5->addWidget(btnProj4Off, 0, 1, 1, 1);

        cmbProj4 = new QComboBox(gbxProj4);
        cmbProj4->setObjectName(QStringLiteral("cmbProj4"));
        cmbProj4->setFont(font);

        gridLayout_5->addWidget(cmbProj4, 1, 0, 1, 2);

        lblStatus4 = new QLabel(gbxProj4);
        lblStatus4->setObjectName(QStringLiteral("lblStatus4"));

        gridLayout_5->addWidget(lblStatus4, 2, 0, 1, 2);


        gridLayout->addWidget(gbxProj4, 1, 1, 1, 1);

        gbxProj3 = new QGroupBox(centralwidget);
        gbxProj3->setObjectName(QStringLiteral("gbxProj3"));
        sizePolicy1.setHeightForWidth(gbxProj3->sizePolicy().hasHeightForWidth());
        gbxProj3->setSizePolicy(sizePolicy1);
        gbxProj3->setFlat(false);
        gridLayout_4 = new QGridLayout(gbxProj3);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setSizeConstraint(QLayout::SetMaximumSize);
        btnProj3On = new QPushButton(gbxProj3);
        btnProj3On->setObjectName(QStringLiteral("btnProj3On"));
        sizePolicy2.setHeightForWidth(btnProj3On->sizePolicy().hasHeightForWidth());
        btnProj3On->setSizePolicy(sizePolicy2);
        btnProj3On->setMinimumSize(QSize(0, 50));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette2.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        btnProj3On->setPalette(palette2);
        btnProj3On->setFont(font);
        btnProj3On->setAutoFillBackground(true);

        gridLayout_4->addWidget(btnProj3On, 0, 0, 1, 1);

        btnProj3Off = new QPushButton(gbxProj3);
        btnProj3Off->setObjectName(QStringLiteral("btnProj3Off"));
        sizePolicy2.setHeightForWidth(btnProj3Off->sizePolicy().hasHeightForWidth());
        btnProj3Off->setSizePolicy(sizePolicy2);
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush10);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush11);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush12);
        palette3.setBrush(QPalette::Active, QPalette::Mid, brush13);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette3.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush14);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush10);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush11);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette3.setBrush(QPalette::Inactive, QPalette::Mid, brush13);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush14);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush10);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush11);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette3.setBrush(QPalette::Disabled, QPalette::Mid, brush13);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        btnProj3Off->setPalette(palette3);
        btnProj3Off->setFont(font);
        btnProj3Off->setAutoFillBackground(true);

        gridLayout_4->addWidget(btnProj3Off, 0, 1, 1, 1);

        cmbProj3 = new QComboBox(gbxProj3);
        cmbProj3->setObjectName(QStringLiteral("cmbProj3"));
        cmbProj3->setFont(font);

        gridLayout_4->addWidget(cmbProj3, 1, 0, 1, 2);

        lblStatus3 = new QLabel(gbxProj3);
        lblStatus3->setObjectName(QStringLiteral("lblStatus3"));

        gridLayout_4->addWidget(lblStatus3, 2, 0, 1, 2);


        gridLayout->addWidget(gbxProj3, 0, 2, 1, 1);

        gbxProj2 = new QGroupBox(centralwidget);
        gbxProj2->setObjectName(QStringLiteral("gbxProj2"));
        sizePolicy1.setHeightForWidth(gbxProj2->sizePolicy().hasHeightForWidth());
        gbxProj2->setSizePolicy(sizePolicy1);
        gridLayout_3 = new QGridLayout(gbxProj2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        btnProj2On = new QPushButton(gbxProj2);
        btnProj2On->setObjectName(QStringLiteral("btnProj2On"));
        sizePolicy2.setHeightForWidth(btnProj2On->sizePolicy().hasHeightForWidth());
        btnProj2On->setSizePolicy(sizePolicy2);
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette4.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette4.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette4.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette4.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette4.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette4.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette4.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        btnProj2On->setPalette(palette4);
        btnProj2On->setFont(font);
        btnProj2On->setAutoFillBackground(true);
        btnProj2On->setFlat(false);

        gridLayout_3->addWidget(btnProj2On, 0, 0, 1, 1);

        btnProj2Off = new QPushButton(gbxProj2);
        btnProj2Off->setObjectName(QStringLiteral("btnProj2Off"));
        sizePolicy2.setHeightForWidth(btnProj2Off->sizePolicy().hasHeightForWidth());
        btnProj2Off->setSizePolicy(sizePolicy2);
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette5.setBrush(QPalette::Active, QPalette::Light, brush10);
        palette5.setBrush(QPalette::Active, QPalette::Midlight, brush11);
        palette5.setBrush(QPalette::Active, QPalette::Dark, brush12);
        palette5.setBrush(QPalette::Active, QPalette::Mid, brush13);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush);
        palette5.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette5.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette5.setBrush(QPalette::Active, QPalette::AlternateBase, brush14);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette5.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette5.setBrush(QPalette::Inactive, QPalette::Light, brush10);
        palette5.setBrush(QPalette::Inactive, QPalette::Midlight, brush11);
        palette5.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette5.setBrush(QPalette::Inactive, QPalette::Mid, brush13);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette5.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush14);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette5.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette5.setBrush(QPalette::Disabled, QPalette::Light, brush10);
        palette5.setBrush(QPalette::Disabled, QPalette::Midlight, brush11);
        palette5.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette5.setBrush(QPalette::Disabled, QPalette::Mid, brush13);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette5.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette5.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette5.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        btnProj2Off->setPalette(palette5);
        btnProj2Off->setFont(font);
        btnProj2Off->setAutoFillBackground(true);
        btnProj2Off->setFlat(false);

        gridLayout_3->addWidget(btnProj2Off, 0, 1, 1, 1);

        cmbProj2 = new QComboBox(gbxProj2);
        cmbProj2->setObjectName(QStringLiteral("cmbProj2"));
        cmbProj2->setFont(font);

        gridLayout_3->addWidget(cmbProj2, 1, 0, 1, 2);

        lblStatus2 = new QLabel(gbxProj2);
        lblStatus2->setObjectName(QStringLiteral("lblStatus2"));

        gridLayout_3->addWidget(lblStatus2, 2, 0, 1, 2);


        gridLayout->addWidget(gbxProj2, 0, 1, 1, 1);

        gbxProj1 = new QGroupBox(centralwidget);
        gbxProj1->setObjectName(QStringLiteral("gbxProj1"));
        gbxProj1->setEnabled(true);
        sizePolicy1.setHeightForWidth(gbxProj1->sizePolicy().hasHeightForWidth());
        gbxProj1->setSizePolicy(sizePolicy1);
        gridLayout_2 = new QGridLayout(gbxProj1);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        btnProj1On = new QPushButton(gbxProj1);
        btnProj1On->setObjectName(QStringLiteral("btnProj1On"));
        sizePolicy2.setHeightForWidth(btnProj1On->sizePolicy().hasHeightForWidth());
        btnProj1On->setSizePolicy(sizePolicy2);
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Light, brush2);
        palette6.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        palette6.setBrush(QPalette::Active, QPalette::Dark, brush4);
        palette6.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush);
        palette6.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette6.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette6.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette6.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette6.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette6.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette6.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette6.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        btnProj1On->setPalette(palette6);
        btnProj1On->setFont(font);
        btnProj1On->setAutoFillBackground(true);
        btnProj1On->setFlat(false);

        gridLayout_2->addWidget(btnProj1On, 0, 0, 1, 1);

        btnProj1Off = new QPushButton(gbxProj1);
        btnProj1Off->setObjectName(QStringLiteral("btnProj1Off"));
        sizePolicy2.setHeightForWidth(btnProj1Off->sizePolicy().hasHeightForWidth());
        btnProj1Off->setSizePolicy(sizePolicy2);
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush9);
        palette7.setBrush(QPalette::Active, QPalette::Light, brush10);
        palette7.setBrush(QPalette::Active, QPalette::Midlight, brush11);
        palette7.setBrush(QPalette::Active, QPalette::Dark, brush12);
        palette7.setBrush(QPalette::Active, QPalette::Mid, brush13);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush);
        palette7.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush9);
        palette7.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette7.setBrush(QPalette::Active, QPalette::AlternateBase, brush14);
        palette7.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette7.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush9);
        palette7.setBrush(QPalette::Inactive, QPalette::Light, brush10);
        palette7.setBrush(QPalette::Inactive, QPalette::Midlight, brush11);
        palette7.setBrush(QPalette::Inactive, QPalette::Dark, brush12);
        palette7.setBrush(QPalette::Inactive, QPalette::Mid, brush13);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush9);
        palette7.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush14);
        palette7.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette7.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush12);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush9);
        palette7.setBrush(QPalette::Disabled, QPalette::Light, brush10);
        palette7.setBrush(QPalette::Disabled, QPalette::Midlight, brush11);
        palette7.setBrush(QPalette::Disabled, QPalette::Dark, brush12);
        palette7.setBrush(QPalette::Disabled, QPalette::Mid, brush13);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush12);
        palette7.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush12);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush9);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush9);
        palette7.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush9);
        palette7.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette7.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        btnProj1Off->setPalette(palette7);
        btnProj1Off->setFont(font);
        btnProj1Off->setAutoFillBackground(true);
        btnProj1Off->setFlat(false);

        gridLayout_2->addWidget(btnProj1Off, 0, 1, 1, 1);

        cmbProj1 = new QComboBox(gbxProj1);
        cmbProj1->setObjectName(QStringLiteral("cmbProj1"));
        cmbProj1->setFont(font);

        gridLayout_2->addWidget(cmbProj1, 1, 0, 1, 2);

        lblStatus1 = new QLabel(gbxProj1);
        lblStatus1->setObjectName(QStringLiteral("lblStatus1"));

        gridLayout_2->addWidget(lblStatus1, 2, 0, 1, 2);


        gridLayout->addWidget(gbxProj1, 0, 0, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(6);
        font1.setStrikeOut(false);
        groupBox->setFont(font1);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        verticalLayout_6 = new QVBoxLayout(groupBox);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        btnSettings = new QPushButton(groupBox);
        btnSettings->setObjectName(QStringLiteral("btnSettings"));
        sizePolicy2.setHeightForWidth(btnSettings->sizePolicy().hasHeightForWidth());
        btnSettings->setSizePolicy(sizePolicy2);
        btnSettings->setFont(font);

        verticalLayout_6->addWidget(btnSettings);

        btnMinimize = new QPushButton(groupBox);
        btnMinimize->setObjectName(QStringLiteral("btnMinimize"));
        sizePolicy2.setHeightForWidth(btnMinimize->sizePolicy().hasHeightForWidth());
        btnMinimize->setSizePolicy(sizePolicy2);
        btnMinimize->setFont(font);

        verticalLayout_6->addWidget(btnMinimize);


        gridLayout->addWidget(groupBox, 1, 2, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 673, 21));
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
        gbxTake->setTitle(QApplication::translate("MainWindow", "Source", 0));
        btnSrcPC->setText(QApplication::translate("MainWindow", "PC", 0));
        btnSrcLaptop->setText(QApplication::translate("MainWindow", "Laptop", 0));
        gbxProj4->setTitle(QApplication::translate("MainWindow", "Rear Projector", 0));
        btnProj4On->setText(QApplication::translate("MainWindow", "On", 0));
        btnProj4Off->setText(QApplication::translate("MainWindow", "Off", 0));
        cmbProj4->clear();
        cmbProj4->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1. PC", 0)
         << QApplication::translate("MainWindow", "2. Laptop", 0)
         << QApplication::translate("MainWindow", "3. Xibo", 0)
        );
        lblStatus4->setText(QApplication::translate("MainWindow", "waiting...", 0));
        gbxProj3->setTitle(QApplication::translate("MainWindow", "Stage Left Projector", 0));
        btnProj3On->setText(QApplication::translate("MainWindow", "On", 0));
        btnProj3Off->setText(QApplication::translate("MainWindow", "Off", 0));
        cmbProj3->clear();
        cmbProj3->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1. PC", 0)
         << QApplication::translate("MainWindow", "2. Laptop", 0)
         << QApplication::translate("MainWindow", "3. Xibo", 0)
         << QString()
        );
        lblStatus3->setText(QApplication::translate("MainWindow", "waiting...", 0));
        gbxProj2->setTitle(QApplication::translate("MainWindow", "Front Projector", 0));
        btnProj2On->setText(QApplication::translate("MainWindow", "On", 0));
        btnProj2Off->setText(QApplication::translate("MainWindow", "Off", 0));
        cmbProj2->clear();
        cmbProj2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1. PC", 0)
         << QApplication::translate("MainWindow", "2. Laptop", 0)
         << QApplication::translate("MainWindow", "3. Xibo", 0)
        );
        lblStatus2->setText(QApplication::translate("MainWindow", "waiting...", 0));
        gbxProj1->setTitle(QApplication::translate("MainWindow", "Stage Right Projector", 0));
        btnProj1On->setText(QApplication::translate("MainWindow", "On", 0));
        btnProj1Off->setText(QApplication::translate("MainWindow", "Off", 0));
        cmbProj1->clear();
        cmbProj1->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1. PC", 0)
         << QApplication::translate("MainWindow", "2. Laptop", 0)
         << QApplication::translate("MainWindow", "3. Xibo", 0)
        );
        lblStatus1->setText(QApplication::translate("MainWindow", "waiting...", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", ".", 0));
        btnSettings->setText(QApplication::translate("MainWindow", "Settings", 0));
        btnMinimize->setText(QApplication::translate("MainWindow", "Minimize", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
