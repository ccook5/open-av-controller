#ifndef PROJECTOR_H
#define PROJECTOR_H

#include <QObject>
#include <QTimer>
#include <QMap>
#include <QTcpSocket>

class projector : public QObject
{
    Q_OBJECT
public:
    explicit projector(QObject *parent = 0, QString address = "", int port = 4352);
    ~projector();


public slots:
    void     ExecuteCmd(QByteArray cmd);

    QString         data_back();

    void update_status();

    void setPassword(QString password);

public:
    QString        get_status();

    void        change_status(QString msg = "");


// pjlink commands
    void get_power_status    ();

    void get_input_source    ();

    void get_available_inputs();

    /** true = shutter closed - no output
     * false = shutter open   */
    void    get_shutter_status   ();

    bool    get_audio_mute_status();

    void    get_error_status     ();

    void    get_lamp_status      ();

    void    get_manufacturer     ();
    void    get_model            ();
    void    get_name             ();

    void    get_other_info       ();

    void    get_class            ();

//pjlink info requests
    void    set_power_on         ();
    void    set_power_off        ();

    void    set_input_source     (QString src = "");

    void    set_shutter_closed   ();
    void    set_shutter_open     ();

    void    set_audio_muted      ();
    void    set_audio_unmuted    ();

public:
    QString       address;
    int           port;

    QByteArray    password;
    QByteArray    digest;
    bool          is_connected;
    QTcpSocket    socket;
    QTimer*       update;

    QString       status;
    QString       power_status;
    QString       name;
    QString       model;
    QString       manufacturer;
    QString       error_status;
    QString       lamp_status;
};

#endif // PROJECTOR_H
