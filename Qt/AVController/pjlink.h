#ifndef PJLINK_H
#define PJLINK_H

#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QAbstractSocket>
#include <QTimer>
#include <QQueue>

#include "pjlink_constants.h"



/// Socket service for connecting to a PJLink-capable projector.

class PjLink : public QObject
{
    Q_OBJECT

public:
    PjLink(QString ip = "", int     port     = PJLINK_PORT,  QByteArray  password   =  0);

    ~PjLink();

    void reset_information();

    void socket_abort     ();

    /** Retrieve information from projector that changes.
     *
     * Normally called by timer().
     */
private slots:
    void update_address();

    void process_loop();
    void poll_loop         ();

    void readyRead();

    void reset_connection();
    void disconnect_from_host();

public slots:
    void power_on();
    void power_off();

signals:
    void friendly_status_update(QString status);

private:
    void send_command   (QString cmd);

    void connect_to_host();

    void process_response(QString data);


private:
    QString         address;
    int             port;
    QTcpSocket*     tcpSocket;

    QByteArray      password;
    QByteArray      random_no;
    QByteArray encrypted_msg;

    int             poll_time;
    int             socket_timeout;
    bool            no_poll;
    bool            waiting_for_reply;
    bool waiting_for_authentication;
    bool authenticated;

    QQueue <QByteArray> cmd_queue;

// Socket timer for some possible brain-dead projectors or network cable pulled.
    QTimer*                        socket_timer;

// send any pending data
    QTimer*                        process_timer;

// regularly poll the projector for info.
    QTimer*                        poll_timer;

// Session Timer - restart session after 30 seconds
    QTimer*                        session_timer;


    int                            power;
    QString                        pjlink_name;
    QString                        manufacturer;
    QString                        model;

    QString                        other_info;

    bool                           shutter;
    bool                           mute;
    QString                        source;

    QMap<QString, QString>         projector_errors;

};

#endif // PJLINK_H
