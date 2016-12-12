#include "pjlink.h"

#include <QString>

#include "log.h"

/* based on code from OpenLP */

/** setup instance of class
 *
 * @param name display name
 * @param ip   IP address to connect to
 * @param port Port to use. Default to PJLINK_PORT
 * @param pin  Access pin (if needed)
 *
 * optional parameters
 *
 * @param dbid            Database ID number
 * @param location        Location where projector is physically located
 * @param notes           Extra notes about the projector
 * @param poll_time       Time (in seconds) to poll connected projector
 * @param socket_timeout  Time (in seconds) to abort the connection if no response
 */
PjLink::PjLink(QString name      , QString ip             , int     port    ,
               int     pin       , QString location       , QString notes   ,
               int     poll_time , int     socket_timeout , bool    no_poll )
       : QTcpSocket()
{
    this->name     = name;
    this->ip       = ip;
    this->port     = port;
    this->pin      = pin;
    this->location = location;
    this->notes    = notes;

// Poll time 20 seconds unless called with something else
    this->poll_time = poll_time * 1000;

// Timeout 5 seconds unless called with something else
    this->socket_timeout   = socket_timeout * 1000;

// In case we're called from somewhere that only wants information
    this->no_poll          = no_poll;
    this->i_am_running     = false;
    this->status_connect   = S_NOT_CONNECTED;
    this->last_command     = "";
    this->projector_status = S_NOT_CONNECTED;
    this->error_status     = S_OK;

// Socket information
// Add enough space to input buffer for extraneous \n \r
    this->maxSize          = PJLINK_MAX_PACKET + 2;
    this->setReadBufferSize(this->maxSize);

// PJLink information
    this->pjlink_class     = '1';            // Default class
    this->reset_information();

// Set from ProjectorManager.add_projector()
    this->widget     = 0;                   // QListBox entry
//    this->timer;                   // Timer that calls the poll_loop
    this->send_queue.clear();
    this->send_busy   = false;


// Map command to function
//    this->PJLINK1_FUNC["AVMT"  ] = process_avmt;
//    this->PJLINK1_FUNC["CLSS"  ] = this->process_clss;
//    this->PJLINK1_FUNC["ERST"  ] = this->process_erst;
//    this->PJLINK1_FUNC["INFO"  ] = this->process_info;
//    this->PJLINK1_FUNC["INF1"  ] = this->process_inf1;
//    this->PJLINK1_FUNC["INF2"  ] = this->process_inf2;
//    this->PJLINK1_FUNC["INPT"  ] = this->process_inpt;
//    this->PJLINK1_FUNC["INST"  ] = this->process_inst;
//    this->PJLINK1_FUNC["LAMP"  ] = this->process_lamp;
//    this->PJLINK1_FUNC["NAME"  ] = this->process_name;
//    this->PJLINK1_FUNC["PJLINK"] = this->check_login;
//    this->PJLINK1_FUNC["POWR"  ] = this->process_powr;
}

PjLink::~PjLink()
{
}


const char    PJLINK_PREFIX    = '%';
const char    PJLINK_CLASS     = '1';
const QString PJLINK_HEADER    = QString(PJLINK_PREFIX) + QString( PJLINK_CLASS);
const char    PJLINK_SUFFIX    = '\r';


/*** Reset projector-specific information to default */
void  PjLink::reset_information()
{
        this->power            = S_OFF;

        this->shutter          = "";
        this->mute             = "";
//        this->lamp             = "";
//        this->fan              = "";
//        this->source_available = 0;
        this->source           = "";
        this->other_info       = "";


        this->timer.stop();

        this->socket_timer.stop();

        this->send_queue.clear();
        this->send_busy = false;
}

/** Connects signals to methods when thread is started. */
void PjLink::thread_started()
{
        this->i_am_running = true;
        this->connect(this, SIGNAL(   connected()), this, SLOT(          check_login() ) );
        this->connect(this, SIGNAL(disconnected()), this, SLOT( disconnect_from_host() ) );
        this->connect(this, SIGNAL(       error()), this, SLOT(            get_error() ) );
}


/** Cleanups when thread is stopped. */

void PjLink::thread_stopped()
{
    this->disconnect(SIGNAL(    connected()          ), this, SLOT(          check_login() ) );
    this->disconnect(SIGNAL( disconnected()          ), this, SLOT( disconnect_from_host() ) );
    this->disconnect(SIGNAL(        error()          ), this, SLOT(            get_error() ) );
    this->disconnect(SIGNAL( projectorReceivedData() ), this, SLOT(         send_command() ) );

    this->disconnect_from_host();
    this->deleteLater();
    this->i_am_running = false;
}

/** Aborts connection and closes socket in case of brain-dead projectors.
 *
 * Should normally be called by socket_timer().
 */
void PjLink::socket_abort()
{
    this->disconnect_from_host(/*abort=*/true);
}

/** Retrieve information from projector that changes.
 *
 * Normally called by timer().
 */
void PjLink::poll_loop()
{
    log::debug("poll_loop");
        if (this->state() != this->ConnectedState)
        {
            return;
        }

        // Reset timer in case we were called from a set command
        if (this->timer.interval() < this->poll_time) {
// Reset timer to 5 seconds
            this->timer.setInterval(this->poll_time);
        }
// Restart timer
        this->timer.start();

// These commands may change during connetion
        QStringList commands;
        commands << "POWR" << "ERST" << "LAMP" << "AVMT" << "INPT";
        foreach (QString command, commands )
        {
            this->send_command(command, "?", "", true);
        }

        // The following commands do not change, so only check them once
        if (this->power == S_ON && this->source_available.isEmpty())
        {
            this->send_command("INST", "?", "", true);
        }
        if (this->other_info == "")
        {
            this->send_command("INFO", "?", "", true);
        }
        if (this->manufacturer == "")
        {
            this->send_command("INF1", "?", "", true);
        }
        if (this->model == "")
        {
            this->send_command("INF2", "?", "", true);
        }
        if (this->pjlink_name == "")
        {
            this->send_command("NAME", "?", "", true);
        }
        if (this->power == S_ON && this->source_available.isEmpty())
        {
            this->send_command("INST", "?", "", true);
        }
}


/** Helper to retrieve status/error codes and convert to strings.
 *
 * @param status: Status/Error code
 * @returns: (Status/Error code, String)
 *
 **/
QString PjLink::get_status(int status)
{
    if (ERROR_STRING(status) != "")
        return ERROR_STRING(status) + " : " + ERROR_MSG(status);
    else if (STATUS_STRING(status) != "")
        return STATUS_STRING(status) + " : " + ERROR_MSG(status);
    else
        return QString("%1 : Unknown status").arg(status);
}

/** Check connection/error status, set status for projector, then emit status change signal
 *
 *  for gui to allow changing the icons.
 *
 * :param status: Status code
 * :param msg: Optional message
 *
 **/
void PjLink::change_status( int status, QString msg)
{
        QString message, code, m;
        QString status_message, status_code;
        QString str_status;

        QString om = "("+this->ip+") %4: %2: %3";

        if (msg == "") {
            message = "No message";
        } else {
            message = msg;
        }

        str_status = this->get_status(status);

        code    = str_status.split(" : ").at(0);
        message = str_status.split(" : ").at(1);

        if (msg != "")
        {
            message = msg;
        }

        if (CONNECTION_ERRORS.contains(status))
        {
            // Projector, connection state
            this->projector_status = this->error_status = this->status_connect = E_NOT_CONNECTED;
        }
        else if (status >= S_NOT_CONNECTED && status < S_STATUS)
        {
            this->status_connect = status;
            this->projector_status = S_NOT_CONNECTED;
        }
        else if (status < S_NETWORK_SENDING)
        {
            this->status_connect = S_CONNECTED;
            this->projector_status = status;
        }

// status_connect
        str_status = this->get_status(this->status_connect);

        status_code    = str_status.split(" : ").at(0);
        status_message = str_status.split(" : ").at(1);

        m = om.arg(status_code);
        if (msg == "") { m = m.arg(status_message); } else {   m = m.arg(msg);    }

        log::debug(m.arg("status_connect"));

// projector_status
        str_status = this->get_status(this->projector_status);

        status_code    = str_status.split(" : ").at(0);
        status_message = str_status.split(" : ").at(1);

        m = om.arg(status_code);
        if (msg == "") { m = m.arg(status_message); } else {   m = m.arg(msg);    }
        log::debug(m.arg("projector_status"));

// error_status
        str_status = this->get_status(this->error_status);

        status_code    = str_status.split(" : ").at(0);
        status_message = str_status.split(" : ").at(1);

        m = om.arg(status_code);
        if (msg == "") { m = m.arg(status_message); } else {   m = m.arg(msg);    }
        log::debug(m.arg("error_status"));

        emit changeStatus(this->ip, status, message);
}

/** Processes the initial connection and authentication (if needed).
  * Starts poll timer if connection is established.
  *
  * @param data: Optional data if called from another routine
  *
  * SLOT */
void PjLink::check_login(QByteArray data/* = ""*/)
{
        log::debug( "(" + this->ip + ") check_login(data='" + data + "')");

        if (data == "")
        {
            // Reconnected setup?
            if ( ! this->waitForReadyRead(2000) )
            {
// Possible timeout issue
                log::error("("+this->ip+") Socket timeout waiting for login.");
                this->change_status(E_SOCKET_TIMEOUT);
                return;
            }
            QByteArray read = this->readLine(this->maxSize);
            QString dontcare = this->readLine(this->maxSize);  // Clean out the trailing \r\n
            if (read == "")
            {
                log::warn("("+this->ip+") read is None - socket error?");
                return;
            }
            else if (read.length() < 8)
            {
                log::warn(QString("(%s) Not enough data read)").arg( this->ip ) );
                return;
            }
            data = read;

            // Possibility of extraneous data on input when reading.
            // Clean out extraneous characters in buffer.
            dontcare = this->readLine(this->maxSize);

            log::debug("("+this->ip+") check_login() read '" + data + "'");
        }
        // At this point, we should only have the initial login prompt with
        // possible authentication
        // PJLink initial login will be:
        // 'PJLink 0' - Unauthenticated login - no extra steps required.
        // 'PJLink 1 XXXXXX' Authenticated login - extra processing required.
        if (! data.toUpper().startsWith("PJLINK"))
        {
// Invalid response
            return this->disconnect_from_host();
        }

        QStringList data_check;

        if (data.contains('=')) {
// Processing a login reply
            data_check = QString(data).simplified().split('=');
        } else {
            // Process initial connection
            data_check = QString(data).simplified().split(' ');
            log::debug(QString("(%1) data_check='%2'").arg(this->ip).arg(data_check.join(' ')));
        }
// Check for projector reporting an error
        if (data_check[1].toUpper() == "ERRA")
        {
            // Authentication error
            this->disconnect_from_host();
            this->change_status(E_AUTHENTICATION);
            log::debug(QString("(%1) emitting projectorAuthentication() signal").arg( this->name ) );
            return;
        }
        else if (data_check[1] == "0" && this->pin != 0)
        {
            // Pin set and no authentication needed
            this->disconnect_from_host();
            this->change_status(E_AUTHENTICATION);
            log::debug(QString("(%1) emitting projectorNoAuthentication() signal").arg(this->name));
            emit(SIGNAL(this->projectorNoAuthentication()), this->name);

            return;
        }
        else if (data_check[1] == "1")
        {
            // Authenticated login with salt
//            log.debug("(%s) Setting hash with salt=\"%s\"" % (this->ip, data_check[2]));
//            log.debug("(%s) pin=\"%s\"" % (this->ip, this->pin));
//            salt = qmd5_hash(salt=data_check[2].encode("ascii"), data=this->pin.encode("ascii"));
        } else {
//            salt = "None";
        }
        // We're connected at this point, so go ahead and do regular I/O
//        this->readyRead.connect(this->get_data);
//        this->projectorReceivedData.connect(this->_send_command);
        // Initial data we should know about
//        this->send_command(cmd="CLSS", salt=salt);
        this->waitForReadyRead();

//        if (not this->no_poll) && (this->state() == this->ConnectedState)
        {
//            log.debug("(%s) Starting timer" % this->ip)
//            this->timer.setInterval(2000);  // Set 2 seconds for initial information
//            this->timer.start();
        }
}


/** Socket interface to retrieve data.
 *
 *  @pyqtSlot()
 */
    void  PjLink::get_data()
    {
        log::debug(QString("(%1) get_data(): Reading data").arg(this->ip));

        if (this->state() != this->ConnectedState)
        {
            log::debug(QString("(%1) get_data(): Not connected - returning").arg( this->ip));
            this->send_busy = false;
            return;
        }
        QByteArray read = this->readLine(this->maxSize);

        if (read == "")
        {
// No data available
           log::debug(QString("(%1) get_data(): No data available (-1)").arg( this->ip));
            this->send_busy = false;
            emit(SIGNAL(this->projectorReceivedData));
            return;
        }
        this->socket_timer.stop();
        emit(SIGNAL(this->projectorNetwork()),S_NETWORK_RECEIVED);
        QByteArray data_in = read;
        QString data = QString(data_in.simplified());
        if (data.length() < 7)
        {
// Not enough data for a packet
            log::debug(QString("(%1) get_data(): Packet length < 7: '%2'").arg(this->ip).arg(data));
            this->send_busy = false;
            emit(SIGNAL(this->projectorReceivedData()));
            return;
        }
        log::debug(QString("(%s) get_data(): Checking new data \"%s\"").arg(this->ip, data));
        if ( data.toUpper().startsWith("PJLINK") )
        {
// Reconnected from remote host disconnect ?
            this->check_login(data.toUtf8());
            this->send_busy = false;
            emit(SIGNAL(this->projectorReceivedData));
            return;
        }
        else if (! data.contains('='))
        {
            log::warn(QString("(%1) get_data(): Invalid packet received").arg(this->ip));
            this->send_busy = false;
            emit(SIGNAL(this->projectorReceivedData()));
            return;
        }
        QStringList data_split = QString(data).split('=');

        QString prefix, class_, cmd;
//        try
//        {
            prefix = data_split[0][0];
            class_ = data_split[0][1];
            cmd    = data_split[0].right(2);
            data   = data_split[1];
//        }
//        catch (ValueError e)
//        {
//            log.warn('(%s) get_data(): Invalid packet - expected header + command + data' % this->ip)
//            log.warn('(%s) get_data(): Received data: "%s"' % (this->ip, read))
//            this->change_status(E_INVALID_DATA);
//            this->send_busy = false;
//            this->projectorReceivedData.emit()
//            return;
//        }

        if (! PjLink::isValidCmd(this->pjlink_class, cmd))
        {
            log::warn(QString("(%s) get_data(): Invalid packet - unknown command '%s'").arg(this->ip, cmd));
            this->send_busy = false;
            emit(SIGNAL(this->projectorReceivedData()));
            return;
        }
        return this->process_command(cmd, data);
}


/** Process error from SocketError signal.
 *
 * Remaps system error codes to projector error codes.
 *
 * @param err: Error code
 *
 * @pyqtSlot(int)
 */
void PjLink::get_error(int err)
{
    int check = 0;

        log::debug(QString("(%1) get_error(err=%2): %3").arg(this->ip).arg(err).arg(this->errorString()));
        if (err <= 18)
        {
// QSocket errors. Redefined in projector.constants so we don't mistake them for system errors
            check = err + E_CONNECTION_REFUSED;
            this->timer.stop();
        }
        else {
            check = err;
        }
        if (check < E_GENERAL)
        {
// Some system error?
            this->change_status(err, this->errorString());
        }
        else
        {
            this->change_status(E_NETWORK, this->errorString());
        }
        emit(SIGNAL(this->projectorUpdateIcons()));
        if (this->status_connect == E_NOT_CONNECTED)
        {
            this->abort();
            this->reset_information();
        }
        return;
}

/*************************************************/

/** Add command to output queue if not already in queue.
 *
 * :param cmd:   Command to send
 * :param opts:  Command option (if any) - defaults to '?' (get information)
 * :param salt:  Optional  salt for md5 hash initial authentication
 * :param queue: Option to force add to queue rather than sending directly
 */
void PjLink::send_command(QString cmd, QString opts/*='?'*/, QString salt/*=None*/, bool queue/*=false*/)
{
    QString out;

        if (this->state() != this->ConnectedState) {
            log::warn(QString("(%s) send_command(): Not connected - returning").arg( this->ip));
            this->send_queue.clear();
            return;
        }

        emit(SIGNAL(this->projectorNetwork(S_NETWORK_SENDING)));
        QString msg = "(%s) send_command(): Building cmd=\"%s\" opts=\"%s\" %s";

        if (salt == "") {
            msg = msg.arg(this->ip).arg(cmd).arg(opts).arg("");
        } else {
            msg = msg.arg(this->ip).arg(cmd).arg(opts).arg("with hash");
        }

        log::debug(msg);

        if (salt == "") {
            out = QString("%1%2 %3%4")            .arg(PJLINK_HEADER).arg(cmd).arg(opts).arg('\r');
        } else {
            out = QString("%1%2%3 %4%5").arg(salt).arg(PJLINK_HEADER).arg(cmd).arg(opts).arg('\r');
        }

        if (this->send_queue.contains(out))
        {
// Already there, so don't add
            log::debug(QString("(%s) send_command(out='%s') Already in queue - skipping").arg(this->ip).arg(out.simplified()));
        }
        else if (! queue && this->send_queue.length() == 0)
        {
// Nothing waiting to send, so just send it
            log::debug(QString("(%s) send_command(out='%s') Sending data").arg(this->ip).arg(out.simplified()));
            return this->_send_command(out);
        } else {
            log::debug(QString("(%s) send_command(out='%s') adding to queue").arg(this->ip, out.simplified()));
            this->send_queue.append(out);
            emit(SIGNAL(this->projectorReceivedData()));
        }

//        log.debug('(%s) send_command(): send_busy is %s' % (this->ip, this->send_busy))
        if (! this->send_busy) {
//            log.debug('(%s) send_command() calling _send_string()');
            this->_send_command();
        }
}

/** Socket interface to send data. If data=None, then check queue.
 *
 * :param data: Immediate data to send
 *
 * @pyqtSlot()
 */
    void PjLink:: _send_command(QString data/*=None*/)
    {
//        log.debug("(%s) _send_string()" % this->ip);
//        log.debug("(%s) _send_string(): Connection status: %s" % (this->ip, this->state()));

        if (this->state() != this->ConnectedState)
        {
//            log.debug("(%s) _send_string() Not connected - abort" % this->ip);
            this->send_queue.empty();
            this->send_busy = false;
            return;
        }
        if (this->send_busy)
        {
            // Still waiting for response from last command sent
            return;
        }

        QString out;
        if (data != "")
        {
            out = data;
//            log.debug("(%s) _send_string(data=%s)" % (this->ip, out.strip()));
        }
        else if (this->send_queue.length() != 0)
        {
            out = this->send_queue.pop();
//            log.debug("(%s) _send_string(queued data=%s)" % (this->ip, out.strip()));
        } else {
            // No data to send
//            log.debug('(%s) _send_string(): No data to send' % this->ip);
            this->send_busy = false;
            return;
        }
        this->send_busy = true;
//        log.debug("(%s) _send_string(): Sending \"%s\"" % (this->ip, out.strip()));
//        log.debug("(%s) _send_string(): Queue = %s" % (this->ip, this->send_queue));
        this->socket_timer.start();

//        try
        {
            emit(SIGNAL(this->projectorNetwork(S_NETWORK_SENDING)));
            int sent = this->write(out.toLocal8Bit());
            this->waitForBytesWritten(2000); // 2 seconds should be enough
            if (sent == -1)
            {
// Network error?
                this->change_status(E_NETWORK, "Error while sending data to projector");
            }
        }
//        catch (SocketError as e)
        {
//            this->disconnect_from_host(abort=true);
//            this->changeStatus(E_NETWORK, "%s : %s" % (e.error(), e.errorString()));
        }
}


/**  Verifies any return error code. Calls the appropriate command handler.
 *
 * @param cmd:  Command to process
 * @param data: Data being processed
 *
 **/
    void PjLink::process_command(QString cmd, QString data)
    {
        log::debug(QString("(%1) Processing command '%2'").arg(this->ip, cmd));
        if (PJLINK_ERRORS(data) != -1)
        {
// Oops - projector error
            if (data.toUpper() == "ERRA")
            {
// Authentication error
                this->disconnect_from_host();
                this->change_status(E_AUTHENTICATION);
                log::debug(QString("(%1) emitting projectorAuthentication() signal").arg(this->ip));
                emit(SIGNAL(this->projectorAuthentication(this->name)));
            }
            else if (data.toUpper() == "ERR1")                // Undefined command
            {
                this->change_status(E_UNDEFINED, QString("%s %s").arg("Undefined command:", cmd));
            }
            else if (data.toUpper() == "ERR2")                // Invalid parameter
            {
                this->change_status(E_PARAMETER);
            }
            else if (data.toUpper() == "ERR3")                // Projector busy
            {
                this->change_status(E_UNAVAILABLE);
            }
            else if (data.toUpper() == "ERR4")                // Projector/display error
            {
                this->change_status(E_PROJECTOR);
            }
            this->send_busy = false;
            emit(SIGNAL(this->projectorReceivedData()));
            return;
        }

// Command succeeded - no extra information
        else if (data.toUpper() == "OK")
        {
            log::debug(QString("(%s) Command returned OK").arg( this->ip) );
// A command returned successfully, recheck data
            this->send_busy = false;
            emit(SIGNAL(this->projectorReceivedData()));
            return;
        }


        if (! QMetaObject::invokeMethod(this, cmd.toLocal8Bit().data(), Q_ARG(QString, data)))
        {
            log::warn(QString("(%s) Invalid command %s").arg (this->ip, cmd));
        }
        this->send_busy = false;
        emit(SIGNAL(this->projectorReceivedData()));
}

/*******************************************************/
    
/** Lamp(s) status. See PJLink Specifications for format.
 *
 *  Data may have more than 1 lamp to process.
 *  Update this->lamp dictionary with lamp status.
 *
 * @param data: Lamp(s) status.
 */
void PjLink:: process_lamp(QString data)
{
        QStringList data_dict = data.split(' ');

        this->lamps.clear();

        while ( ! data_dict.isEmpty() )
        {
            QMap<QString, QString> fill;

            fill["Hours"] = data_dict[0];
            fill["On"]    = data_dict[1];

            this->lamps.append(fill);

            data_dict.removeFirst();  // Remove lamp hours
            data_dict.removeFirst();  // Remove lamp on/off
        }
}

/** Power status. See PJLink specification for format.
 *
 * Update this->power with status. Update icons if change from previous setting.
 *
 * @param data: Power status
 */
void PjLink::process_powr(QString data)
{
    if (PJLINK_POWR_STATUS(data) == -1)
    {
// Log unknown status response
        log::warn(QString("Unknown power response: ") + data);
        return;
    }

    int power = PJLINK_POWR_STATUS(data);

    bool update_icons = (this->power != power);
    this->power  = power;

    this->change_status(PJLINK_POWR_STATUS(data));

    if (update_icons)
    {
        emit(SIGNAL(this->projectorUpdateIcons()));

// Update the input sources available
        if (power == S_ON)
        {
            this->send_command("INST");
        }
    }
}


/** Process shutter and speaker status. See PJLink specification for format.
 *
 *  Update this->mute (audio) and this->shutter (video shutter).
 *
 * @param data: Shutter and audio status
 **/
void PjLink::process_avmt(QString data)
{
        bool shutter = this->shutter;
        bool mute    = this->mute;

        switch (data.toInt())
        {
        // Video
            case 10:  shutter = false;  mute = false;  break;
            case 11:  shutter = true;   mute = false;  break;
        // Audio
            case 20:  shutter = false;  mute = false;  break;
            case 21:  shutter = false;  mute = true;   break;
        // Video + Audio
            case 30:  shutter = false;  mute = false;  break;
            case 31:  shutter = true;   mute = true;   break;

            default:
                log::warn(QString("Unknown shutter response: %1").arg(data));
            break;
        }

        bool update_icons = (shutter != this->shutter);
             update_icons = (update_icons || (mute != this->mute));

        this->shutter = shutter;
        this->mute    = mute;

        if (update_icons)
        {
            emit(SIGNAL(this->projectorUpdateIcons()));
        }
        return;
}

/** Current source input selected. See PJLink specification for format.
 *
 * Update this->source
 *
 * @param data: Currently selected source
 */
void PjLink:: process_inpt(QString data)
{
        this->source = data;
}

/** PJLink class that this projector supports. See PJLink specification for format.
 *
 * Updates this->class.
 *
 * @param data: Class that projector supports.
 */
void PjLink:: process_clss(QString data)
{
    this->pjlink_class = data;
    log::debug(QString("(%1) Setting pjlink_class for this projector to '%2'").arg(this->ip, this->pjlink_class));
}

/** Projector name set in projector.
 *
 *  Updates this->pjlink_name
 *
 * @param data: Projector name
 */
void PjLink:: process_name(QString data)
{
    this->pjlink_name = data;
}

/** Manufacturer name set in projector.
 *
 * Updates this->manufacturer
 *
 * @param data: Projector manufacturer
 */
void PjLink:: process_inf1(QString data)
{
    this->manufacturer = data;
}


/** Projector Model set in projector.
 *
 *  Updates this->model.
 *
 *  @param data: Model name
 */
void PjLink::process_inf2(QString data)
{
    this->model = data;
}

/** Any extra info set in projector.
 *
 *  Updates this->other_info.
 *
 *  @param data: Projector other info
 **/
void PjLink::process_info(QString data)
{
    this->other_info = data;
}


/** Available source inputs. See PJLink specification for format.
 *
 *  Updates this->source_available
 *
 *  @param data: Sources list
 */
void PjLink:: process_inst(QString data)
{
    QStringList sources;
    QStringList check = data.split(QRegExp("\\s+"));

    foreach (source,  check)
    {
        sources.append(source);
    }

    sources.sort();
    this->source_available = sources;

    emit(SIGNAL(this->projectorUpdateIcons()));
}

/** Error status. See PJLink Specifications for format.
 * 
 *  Updates this->projector_errors
 * 
 *  @param data: Error status
 */
void PjLink:: process_erst(QString data)
{
    bool ok        = false;

    int  datacheck = data.toInt(&ok);

    if (ok) return; // Bad data - ignore

    if (datacheck == 0) {
        this->projector_errors.clear();
    } else {
        this->projector_errors.clear();

        if (data[0] != '0')        this->projector_errors[ "Fan"        ] = PJLINK_ERST_STATUS( data[0].toLatin1() );
        if (data[1] != '0')        this->projector_errors[ "Lamp"       ] = PJLINK_ERST_STATUS( data[1].toLatin1() );
        if (data[2] != '0')        this->projector_errors[ "Temperature"] = PJLINK_ERST_STATUS( data[2].toLatin1() );
        if (data[3] != '0')        this->projector_errors[ "Cover"      ] = PJLINK_ERST_STATUS( data[3].toLatin1() );
        if (data[4] != '0')        this->projector_errors[ "Filter"     ] = PJLINK_ERST_STATUS( data[4].toLatin1() );
        if (data[5] != '0')        this->projector_errors[ "Other"      ] = PJLINK_ERST_STATUS( data[5].toLatin1() );
    }
    return;
}

/**************************************************/

/** Initiate connection to projector. */
void PjLink:: connect_to_host()
{
    if (this->state() == this->ConnectedState)
    {
        log::warn(QString("(%1) connect_to_host(): Already connected - returning").arg(this->ip));
        return;
    }

    this->change_status(S_CONNECTING);

    this->connectToHost(this->ip, this->port );
}

/** Close socket and cleanup.
 *
 * Slot
 */
 void PjLink::disconnect_from_host(bool abort /*= false*/)
 {
        if (abort || (this->state() != this->ConnectedState) )
        {
            if (abort) {
                log::warn(QString("(%s) disconnect_from_host(): Aborting connection").arg(this->ip));
            } else {
                log::warn(QString("(%s) disconnect_from_host(): Not connected - returning").arg(this->ip));
            }
            this->reset_information();
        }
        this->disconnectFromHost();

        disconnect(this, SIGNAL(readyRead), this, SLOT(get_data));

        if (abort) {
            this->change_status(E_NOT_CONNECTED);
        } else {
            QString s("(%1) disconnect_from_host() Current status %2");
            s = s.arg(this->ip).arg(this->get_status(this->status_connect)[0]);
            log::debug(s);
            if (this->status_connect != E_NOT_CONNECTED) {
                this->change_status(S_NOT_CONNECTED);
            }
        }
        this->reset_information();
        emit(SIGNAL(this->projectorUpdateIcons()));
}

/******************************************************/
 
/** Send command to retrieve available source inputs. */
void PjLink:: get_available_inputs()
{
        return this->send_command("INST");
}

/** Send command to retrieve currently known errors. */
void PjLink:: get_error_status()
{
        return this->send_command("ERST");
}

/** Send command to retrieve currently selected source input. */
void PjLink:: get_input_source()
{
        return this->send_command("INPT");
}

/** Send command to return the lap status. */
void PjLink:: get_lamp_status()
{
        return this->send_command("LAMP");
}

/** Send command to retrieve manufacturer name. */
void PjLink:: get_manufacturer()
{
        return this->send_command("INF1");
}

/** Send command to retrieve the model name. */
void PjLink:: get_model()
{
        return this->send_command("INF2");
}

/** Send command to retrieve name as set by end-user (if set). */
void PjLink:: get_name()
{
        return this->send_command("NAME");
}

/** Send command to retrieve extra info set by manufacturer. */
void PjLink:: get_other_info()
{
        return this->send_command("INFO");
}

/** Send command to retrieve power status. */
void PjLink:: get_power_status()
{
        return this->send_command("POWR");
}

/** Send command to retrieve shutter status. */
void PjLink:: get_shutter_status()
{
        return this->send_command("AVMT");
}


/** Verify input source available as listed in 'INST' command,
 *  then send the command to select the input source.
 *
 *  @param src: Video source to select in projector
 */

void PjLink:: set_input_source(QString src /*= "" */)
{
        log::debug(QString("(%s) set_input_source(src=%s)").arg(this->ip).arg(src));

    if (this->source_available.isEmpty()) {
            return;
    }
    else if (! this->source_available.contains(src))
    {
            return;
    }
    log::debug(QString("(%s) Setting input source to %s").arg(this->ip).arg(src));
    this->send_command("INPT", src);
    this->poll_loop();
}

/** Send command to turn power to on.  */
void PjLink:: set_power_on()
{
        this->send_command("POWR", "1");
        this->poll_loop();
}

/** Send command to turn power to standby.            */
void PjLink:: set_power_off()
{
        this->send_command("POWR", "0");
        this->poll_loop();
}

/**  Send command to set shutter to closed position.  */
void PjLink:: set_shutter_closed()
{
        this->send_command("AVMT", "11");
        this->poll_loop();
}

/** Send command to set shutter to open position.     */
void PjLink:: set_shutter_open()
{
        this->send_command("AVMT", "10");
        this->poll_loop();
}

