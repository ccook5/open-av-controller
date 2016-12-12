
#include "mainwindow.h"

#include "pjlink_constants.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    init_pjlink_constants();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
