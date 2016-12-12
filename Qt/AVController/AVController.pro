#-------------------------------------------------
#
# Project created by QtCreator 2016-02-17T17:08:57
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4) {
    QT       += widgets serialport
} else {
    include($$QTSERIALPORT_PROJECT_ROOT/src/serialport/qt4support/serialport.prf)
}


TARGET = AVController
TEMPLATE = app


SOURCES += main.cpp \
    serialportlist.cpp \
    mainwindow.cpp \
    pjlink_constants.cpp \
    log.cpp \
    projector.cpp

HEADERS  += \
    serialportlist.h \
    mainwindow.h \
    pjlink_constants.h \
    log.h \
    projector.h

FORMS    += \
    serialportlist.ui \
    mainwindow.ui
