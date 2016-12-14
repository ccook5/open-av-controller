//# -*- coding: utf-8 -*-

//    Provides the constants used for projector errors/status/defaults

#include "pjlink_constants.h"

#include <QString>

/*QString translate (QString a, QString msg)
{
    return msg;
}
*/

//PJLINK_VALID_CMD = {'1': ['PJLINK',  # Initial connection
//                          'POWR',  # Power option
//                          'INPT',  # Video sources option
//                          'AVMT',  # Shutter option
//                          'ERST',  # Error status option
//                          'LAMP',  # Lamp(s) query (Includes fans)
//                          'INST',  # Input sources available query
//                          'NAME',  # Projector name query
//                          'INF1',  # Manufacturer name query
//                          'INF2',  # Product name query
//                          'INFO',  # Other information query
//                          'CLSS'   # PJLink class support query
//                          ]}



//CONNECTION_ERRORS = {E_NOT_CONNECTED, E_NO_AUTHENTICATION, E_AUTHENTICATION, E_CLASS,
//                     E_PREFIX, E_CONNECTION_REFUSED, E_REMOTE_HOST_CLOSED_CONNECTION,
//                     E_HOST_NOT_FOUND, E_SOCKET_ACCESS, E_SOCKET_RESOURCE, E_SOCKET_TIMEOUT,
//                     E_DATAGRAM_TOO_LARGE, E_NETWORK, E_ADDRESS_IN_USE, E_SOCKET_ADDRESS_NOT_AVAILABLE,
//                     E_UNSUPPORTED_SOCKET_OPERATION, E_PROXY_AUTHENTICATION_REQUIRED,
//                     E_SLS_HANDSHAKE_FAILED, E_UNFINISHED_SOCKET_OPERATION, E_PROXY_CONNECTION_REFUSED,
//                     E_PROXY_CONNECTION_CLOSED, E_PROXY_CONNECTION_TIMEOUT, E_PROXY_NOT_FOUND,
//                     E_PROXY_PROTOCOL, E_UNKNOWN_SOCKET_ERROR
//                     }

int PJLINK_ERRORS(QString id)
{
    if      ("ERRA" == id) return E_AUTHENTICATION;   // Authentication error
    else if ("ERR1" == id) return E_UNDEFINED;        // Undefined command error
    else if ("ERR2" == id) return E_PARAMETER;        // Invalid parameter error
    else if ("ERR3" == id) return E_UNAVAILABLE;      // Projector busy
    else if ("ERR4" == id) return E_PROJECTOR;        // Projector or display failure
    else return -1;
}

QString PJLINK_ERRORS(int id)
{
    switch (id)
    {
        case E_AUTHENTICATION : return "ERRA";
        case E_UNDEFINED      : return "ERR1";
        case E_PARAMETER      : return "ERR2";
        case E_UNAVAILABLE    : return "ERR3";
        case E_PROJECTOR      : return "ERR4";

    default: return "";
    }
}

// Map error/status codes to string

QString ERROR_STRING(int id)
{
    switch (id)
    {
        case 0 : return "S_OK";
        case E_GENERAL                       : return "E_GENERAL";
        case E_NOT_CONNECTED                 : return "E_NOT_CONNECTED";
        case E_FAN                           : return "E_FAN";
        case E_LAMP                          : return "E_LAMP";
        case E_TEMP                          : return "E_TEMP";
        case E_COVER                         : return "E_COVER";
        case E_FILTER                        : return "E_FILTER";
        case E_AUTHENTICATION                : return "E_AUTHENTICATION";
        case E_NO_AUTHENTICATION             : return "E_NO_AUTHENTICATION";
        case E_UNDEFINED                     : return "E_UNDEFINED";
        case E_PARAMETER                     : return "E_PARAMETER";
        case E_UNAVAILABLE                   : return "E_UNAVAILABLE";
        case E_PROJECTOR                     : return "E_PROJECTOR";
        case E_INVALID_DATA                  : return "E_INVALID_DATA";
        case E_WARN                          : return "E_WARN";
        case E_ERROR                         : return "E_ERROR";
        case E_CLASS                         : return "E_CLASS";
        case E_PREFIX                        : return "E_PREFIX";  // Last projector error
        case E_CONNECTION_REFUSED            : return "E_CONNECTION_REFUSED";  // First QtSocket error
        case E_REMOTE_HOST_CLOSED_CONNECTION : return "E_REMOTE_HOST_CLOSED_CONNECTION";
        case E_HOST_NOT_FOUND                : return "E_HOST_NOT_FOUND";
        case E_SOCKET_ACCESS                 : return "E_SOCKET_ACCESS";
        case E_SOCKET_RESOURCE               : return "E_SOCKET_RESOURCE";
        case E_SOCKET_TIMEOUT                : return "E_SOCKET_TIMEOUT";
        case E_DATAGRAM_TOO_LARGE            : return "E_DATAGRAM_TOO_LARGE";
        case E_NETWORK                       : return "E_NETWORK";
        case E_ADDRESS_IN_USE                : return "E_ADDRESS_IN_USE";
        case E_SOCKET_ADDRESS_NOT_AVAILABLE  : return "E_SOCKET_ADDRESS_NOT_AVAILABLE";
        case E_UNSUPPORTED_SOCKET_OPERATION  : return "E_UNSUPPORTED_SOCKET_OPERATION";
        case E_PROXY_AUTHENTICATION_REQUIRED : return "E_PROXY_AUTHENTICATION_REQUIRED";
        case E_SLS_HANDSHAKE_FAILED          : return "E_SLS_HANDSHAKE_FAILED";
        case E_UNFINISHED_SOCKET_OPERATION   : return "E_UNFINISHED_SOCKET_OPERATION";
        case E_PROXY_CONNECTION_REFUSED      : return "E_PROXY_CONNECTION_REFUSED";
        case E_PROXY_CONNECTION_CLOSED       : return "E_PROXY_CONNECTION_CLOSED";
        case E_PROXY_CONNECTION_TIMEOUT      : return "E_PROXY_CONNECTION_TIMEOUT";
        case E_PROXY_NOT_FOUND               : return "E_PROXY_NOT_FOUND";
        case E_PROXY_PROTOCOL                : return "E_PROXY_PROTOCOL";
        case E_UNKNOWN_SOCKET_ERROR          : return "E_UNKNOWN_SOCKET_ERROR";
    default: return "";
    }
}

QString STATUS_STRING(int id)
{
    switch (id)
    {
        case S_NOT_CONNECTED:    return "S_NOT_CONNECTED";
        case S_CONNECTING:       return "S_CONNECTING";
        case S_CONNECTED:        return "S_CONNECTED";
        case S_STATUS:           return "S_STATUS";
        case S_OFF:              return "S_OFF";
        case S_INITIALIZE:       return "S_INITIALIZE";
        case S_STANDBY:          return "S_STANDBY";
        case S_WARMUP:           return "S_WARMUP";
        case S_ON:               return "S_ON";
        case S_COOLDOWN:         return "S_COOLDOWN";
        case S_INFO:             return "S_INFO";
        case S_NETWORK_SENDING:  return "S_NETWORK_SENDING";
        case S_NETWORK_RECEIVED: return "S_NETWORK_RECEIVED";
        default:                 return "";
    }
}


// Map error/status codes to message strings

QString ERROR_MSG(int id)
{
    switch (id)
    {
        case E_OK :                            return "OK"; /* E_OK | S_OK;*/ break;
        case E_GENERAL:                        return "General projector error";
        case E_NOT_CONNECTED:                  return "Not connected error";
        case E_LAMP:                           return "Lamp error";
        case E_FAN:                            return "Fan error";
        case E_TEMP:                           return "High temperature detected";
        case E_COVER:                          return "Cover open detected";
        case E_FILTER:                         return "Check filter";
        case E_AUTHENTICATION:                 return "Authentication Error";
        case E_UNDEFINED:                      return "Undefined Command";
        case E_PARAMETER:                      return "Invalid Parameter";
        case E_UNAVAILABLE:                    return "Projector Busy";
        case E_PROJECTOR:                      return "Projector/Display Error";
        case E_INVALID_DATA:                   return "Invalid packet received";
        case E_WARN:                           return "Warning condition detected";
        case E_ERROR:                          return "Error condition detected";
        case E_CLASS:                          return "PJLink class not supported";
        case E_PREFIX:                         return "Invalid prefix character";
        case E_CONNECTION_REFUSED:             return "The connection was refused by the peer (or timed out)";
        case E_REMOTE_HOST_CLOSED_CONNECTION:  return "The remote host closed the connection";
        case E_HOST_NOT_FOUND:                 return "The host address was not found";
        case E_SOCKET_ACCESS:                  return "The socket operation failed because the application lacked the required privileges";
        case E_SOCKET_RESOURCE:                return "The local system ran out of resources (e.g., too many sockets)";
        case E_SOCKET_TIMEOUT:                 return "The socket operation timed out";
        case E_DATAGRAM_TOO_LARGE:             return "The datagram was larger than the operating system\'s limit";
        case E_NETWORK:                        return "An error occurred with the network (Possibly someone pulled the plug?)";
        case E_ADDRESS_IN_USE:                 return "The address specified with socket.bind() is already in use and was set to be exclusive";
        case E_SOCKET_ADDRESS_NOT_AVAILABLE:   return "The address specified to socket.bind() does not belong to the host";
        case E_UNSUPPORTED_SOCKET_OPERATION:   return "The requested socket operation is not supported by the local operating system (e.g., lack of IPv6 support)";
        case E_PROXY_AUTHENTICATION_REQUIRED:  return "The socket is using a proxy, and the proxy requires authentication";
        case E_SLS_HANDSHAKE_FAILED:           return "The SSL/TLS handshake failed";
        case E_UNFINISHED_SOCKET_OPERATION:    return "The last operation attempted has not finished yet (still in progress in the background)";
        case E_PROXY_CONNECTION_REFUSED:       return "Could not contact the proxy server because the connection to that server was denied";
        case E_PROXY_CONNECTION_CLOSED:        return "The connection to the proxy server was closed unexpectedly (before the connection to the final peer was established)";
        case E_PROXY_CONNECTION_TIMEOUT:       return "The connection to the proxy server timed out or the proxy server stopped responding in the authentication phase. return ";
        case E_PROXY_NOT_FOUND:                return "The proxy address set with setProxy() was not found";
        case E_PROXY_PROTOCOL:                 return "The connection negotiation with the proxy server failed because the response from the proxy server could not be understood";
        case E_UNKNOWN_SOCKET_ERROR:           return "An unidentified error occurred";
        case S_NOT_CONNECTED:                  return "Not connected";
        case S_CONNECTING:                     return "Connecting";
        case S_CONNECTED:                      return "Connected";
        case S_STATUS:                         return "Getting status";
        case S_OFF:                            return "Off";
        case S_INITIALIZE:                     return "Initialize in progress";
        case S_STANDBY:                        return "Power in standby";
        case S_WARMUP:                         return "Warmup in progress";
        case S_ON:                             return "Power is on";
        case S_COOLDOWN:                       return "Cooldown in progress";
        case S_INFO:                           return "Projector Information available";
        case S_NETWORK_SENDING:                return "Sending data";
        case S_NETWORK_RECEIVED:               return "Received data";

    default: return "";
    }
}


int PJLINK_POWR_STATUS(QString id)
{
    switch (id.toInt())
    {
        case 0: return S_STANDBY;
        case 1: return S_ON;
        case 2: return S_COOLDOWN;
        case 3: return S_WARMUP;

        default:
            return -1;
    }
}

// Map for POWR return codes to status code
QString PJLINK_POWR_STATUS(int id)
{
    switch (id)
    {
        case S_STANDBY:  return "0";
        case S_ON:       return "1";
        case S_COOLDOWN: return "2";
        case S_WARMUP:   return "3";
        default        : return "";
    }
}



// Map for ERST return codes to string
QString PJLINK_ERST_STATUS(char id)
{
    switch (id)
    {
        case '0': return ERROR_STRING(E_OK);
        case '1': return ERROR_STRING(E_WARN);
        case '2': return ERROR_STRING(E_ERROR);

    default: return "";
    }
}

//PJLINK_DEFAULT_SOURCES = {'1': translate('OpenLP.DB', 'RGB'),
//                          '2': translate('OpenLP.DB', 'Video'),
//                          '3': translate('OpenLP.DB', 'Digital'),
//                          '4': translate('OpenLP.DB', 'Storage'),
//                          '5': translate('OpenLP.DB', 'Network')}

//PJLINK_DEFAULT_CODES = {'11': translate('OpenLP.DB', 'RGB 1'),
//                        '12': translate('OpenLP.DB', 'RGB 2'),
//                        '13': translate('OpenLP.DB', 'RGB 3'),
//                        '14': translate('OpenLP.DB', 'RGB 4'),
//                        '15': translate('OpenLP.DB', 'RGB 5'),
//                        '16': translate('OpenLP.DB', 'RGB 6'),
//                        '17': translate('OpenLP.DB', 'RGB 7'),
//                        '18': translate('OpenLP.DB', 'RGB 8'),
//                        '19': translate('OpenLP.DB', 'RGB 9'),
//                        '21': translate('OpenLP.DB', 'Video 1'),
//                        '22': translate('OpenLP.DB', 'Video 2'),
//                        '23': translate('OpenLP.DB', 'Video 3'),
//                        '24': translate('OpenLP.DB', 'Video 4'),
//                        '25': translate('OpenLP.DB', 'Video 5'),
//                        '26': translate('OpenLP.DB', 'Video 6'),
//                        '27': translate('OpenLP.DB', 'Video 7'),
//                        '28': translate('OpenLP.DB', 'Video 8'),
//                        '29': translate('OpenLP.DB', 'Video 9'),
//                        '31': translate('OpenLP.DB', 'Digital 1'),
//                        '32': translate('OpenLP.DB', 'Digital 2'),
//                        '33': translate('OpenLP.DB', 'Digital 3'),
//                        '34': translate('OpenLP.DB', 'Digital 4'),
//                        '35': translate('OpenLP.DB', 'Digital 5'),
//                        '36': translate('OpenLP.DB', 'Digital 6'),
//                        '37': translate('OpenLP.DB', 'Digital 7'),
//                        '38': translate('OpenLP.DB', 'Digital 8'),
//                        '39': translate('OpenLP.DB', 'Digital 9'),
//                        '41': translate('OpenLP.DB', 'Storage 1'),
//                        '42': translate('OpenLP.DB', 'Storage 2'),
//                        '43': translate('OpenLP.DB', 'Storage 3'),
//                        '44': translate('OpenLP.DB', 'Storage 4'),
//                        '45': translate('OpenLP.DB', 'Storage 5'),
//                        '46': translate('OpenLP.DB', 'Storage 6'),
//                        '47': translate('OpenLP.DB', 'Storage 7'),
//                        '48': translate('OpenLP.DB', 'Storage 8'),
//                        '49': translate('OpenLP.DB', 'Storage 9'),
//                        '51': translate('OpenLP.DB', 'Network 1'),
//                        '52': translate('OpenLP.DB', 'Network 2'),
//                        '53': translate('OpenLP.DB', 'Network 3'),
//                        '54': translate('OpenLP.DB', 'Network 4'),
//                        '55': translate('OpenLP.DB', 'Network 5'),
//                        '56': translate('OpenLP.DB', 'Network 6'),
//                        '57': translate('OpenLP.DB', 'Network 7'),
//                        '58': translate('OpenLP.DB', 'Network 8'),
//                        '59': translate('OpenLP.DB', 'Network 9')
//                        }

//}


QList<int> CONNECTION_ERRORS;

void init_pjlink_constants()
{

    CONNECTION_ERRORS =
    {
        E_NOT_CONNECTED,
        E_NO_AUTHENTICATION,
        E_AUTHENTICATION,
        E_CLASS,
        E_PREFIX,
        E_CONNECTION_REFUSED,
        E_REMOTE_HOST_CLOSED_CONNECTION,
        E_HOST_NOT_FOUND,
        E_SOCKET_ACCESS,
        E_SOCKET_RESOURCE,
        E_SOCKET_TIMEOUT,
        E_DATAGRAM_TOO_LARGE,
        E_NETWORK,
        E_ADDRESS_IN_USE,
        E_SOCKET_ADDRESS_NOT_AVAILABLE,
        E_UNSUPPORTED_SOCKET_OPERATION,
        E_PROXY_AUTHENTICATION_REQUIRED,
        E_SLS_HANDSHAKE_FAILED,
        E_UNFINISHED_SOCKET_OPERATION,
        E_PROXY_CONNECTION_REFUSED,
        E_PROXY_CONNECTION_CLOSED,
        E_PROXY_CONNECTION_TIMEOUT,
        E_PROXY_NOT_FOUND,
        E_PROXY_PROTOCOL,
        E_UNKNOWN_SOCKET_ERROR
    };
}

bool pjlink_isValidCmd(QString cmd_class, QString cmd)
{
    QStringList valid_commands = QString("PJLINK,POWR,INPT,AVMT,ERST,LAMP,INST,NAME,INF1,INF2,INFO,CLSS").split(',');

    if (cmd_class == "1" && valid_commands.contains(cmd) )
    {
        return true;
    }
    else
    {
        return false;
    }
}
