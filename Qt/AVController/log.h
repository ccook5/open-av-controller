#ifndef LOG_H
#define LOG_H

#include <QString>
#include <QMessageBox>

class log
{
public:
    log();
    ~log();

    static void warn(QString msg)
    {
        QMessageBox::warning(0, "AV Controller", msg);
    }

    static void debug(QString msg)
    {
        QMessageBox::information(0, "AV Controller", msg);
    }

    static void error(QString msg)
    {
        QMessageBox::critical(0, "AV Controller", msg);
    }
};

#endif // LOG_H
