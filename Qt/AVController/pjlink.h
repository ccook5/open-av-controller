#ifndef PJLINK_H
#define PJLINK_H

#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QAbstractSocket>
#include <QTimer>
#include <QStack>

#include "pjlink_constants.h"



/// Socket service for connecting to a PJLink-capable projector.

class PjLink : QTcpSocket
{
    Q_OBJECT

public:
    PjLink(QString name       = "", QString ip             = "", int     port     = PJLINK_PORT,
           int     pin        =  0, QString location       = "", QString notes    = "",
           int     poll_time  = 20, int     socket_timeout =  5, bool    no_poll  = false);

    ~PjLink();

    void reset_information();

    void thread_started   ();
    void thread_stopped   ();

    void socket_abort     ();

    /** Retrieve information from projector that changes.
     *
     * Normally called by timer().
     */
    void    poll_loop         ();

    QString get_status        (int status);

    void change_status(int status, QString msg = "");

    void get_available_inputs();
    void get_error_status    ();
    void get_input_source    ();
    void get_lamp_status     ();
    void get_manufacturer    ();
    void get_model           ();
    void get_name            ();
    void get_other_info      ();
    void get_power_status    ();
    void get_shutter_status  ();

    void set_input_source    (QString src = "");
    void set_power_on        ();
    void set_power_off       ();
    void set_shutter_closed  ();
    void set_shutter_open    ();

    void send_command   (QString cmd, QString opts="?", QString salt = "", bool queue=false);

    void _send_command  (QString data = "");

    void process_command(QString cmd, QString data);
    void process_lamp   (QString data);
    void process_powr   (QString data);
    void process_avmt   (QString data);

    void process_inpt   (QString data);
    void process_clss   (QString data);
    void process_name   (QString data);
    void process_inf1   (QString data);
    void process_inf2   (QString data);
    void process_info   (QString data);
    void process_inst   (QString data);
    void process_erst   (QString data);

    void connect_to_host();

    /** Close socket and cleanup.
     *
     * Slot
     */
    void disconnect_from_host(bool abort = false);


//Slots
    void check_login              (QByteArray data = "");

    void get_data();
    void get_error(int err);

signals:
    void changeStatus             (QString, int, QString);
    void projectorNetwork         (int);                   // Projector network activity
    void projectorStatus          (int);                   // Status update
    void projectorAuthentication  (QString);               // Authentication error
    void projectorNoAuthentication(QString);               // PIN set and no authentication needed
    void projectorReceivedData    ();                      // Notify when received data finished processing
    void projectorUpdateIcons     ();                      // Update the status icons on toolbar

private:
    QString         name;
    QString         ip;
    int             port;
    int             pin;

    QString         dbid;
    QString         location;
    QString         notes;

    int             poll_time;
    int             socket_timeout;
    bool            no_poll;
    bool            i_am_running;

    int                            status_connect;
    QString                        last_command;
    int                            projector_status;
    int                            error_status;
    int                            maxSize;
    QString                        pjlink_class;
    int                            widget;
    QTimer                         timer;
    QStack<QString>                send_queue;
    bool                           send_busy;
// Socket timer for some possible brain-dead projectors or network cable pulled.
    QTimer                         socket_timer;
    int                            power;
    QString                        pjlink_name;
    QString                        manufacturer;
    QString                        model;

    QStringList                    source_available;
    QString                        other_info;

    bool                           shutter;
    bool                           mute;
    QString                        source;

    QMap<QString, QString>         projector_errors;
    //QString                      lamp;

    QList<QMap<QString, QString> > lamps;

public:
    static bool isValidCmd(QString cmd_class, QString cmd)
    {
        if (PjLink::PJLINK_VALID_CMD().contains(cmd_class))
        {
            if (PJLINK_VALID_CMD()[cmd_class].contains(cmd))
                return true;
            else
                return false;
        } else {
            return false; // invalid command class;
        }
    }

    static QMap<QString, QStringList> PJLINK_VALID_CMD()
    {
        QMap<QString, QStringList> PJLINK_VALID_CMD;

        PJLINK_VALID_CMD[QString('1')] = QString("PJLINK,POWR,INPT,AVMT,ERST,LAMP,INST,NAME,INF1,INF2,INFO,CLSS").split(',');

        return PJLINK_VALID_CMD;
    }
};

#endif // PJLINK_H
