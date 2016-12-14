#ifndef PJLINK_CONSTANTS_H
#define PJLINK_CONSTANTS_H

#include <QMap>
#include <QStringList>

//    Provides the constants used for projector errors/status/defaults
//"""


//__all__ = ['S_OK', 'E_GENERAL', 'E_NOT_CONNECTED', 'E_FAN', 'E_LAMP', 'E_TEMP',
//           'E_COVER', 'E_FILTER', 'E_AUTHENTICATION', 'E_NO_AUTHENTICATION',
//           'E_UNDEFINED', 'E_PARAMETER', 'E_UNAVAILABLE', 'E_PROJECTOR',
//           'E_INVALID_DATA', 'E_WARN', 'E_ERROR', 'E_CLASS', 'E_PREFIX',
//           'E_CONNECTION_REFUSED', 'E_REMOTE_HOST_CLOSED_CONNECTION', 'E_HOST_NOT_FOUND',
//           'E_SOCKET_ACCESS', 'E_SOCKET_RESOURCE', 'E_SOCKET_TIMEOUT', 'E_DATAGRAM_TOO_LARGE',
//           'E_NETWORK', 'E_ADDRESS_IN_USE', 'E_SOCKET_ADDRESS_NOT_AVAILABLE',
//           'E_UNSUPPORTED_SOCKET_OPERATION', 'E_PROXY_AUTHENTICATION_REQUIRED',
//           'E_SLS_HANDSHAKE_FAILED', 'E_UNFINISHED_SOCKET_OPERATION', 'E_PROXY_CONNECTION_REFUSED',
//           'E_PROXY_CONNECTION_CLOSED', 'E_PROXY_CONNECTION_TIMEOUT', 'E_PROXY_NOT_FOUND',
//           'E_PROXY_PROTOCOL', 'E_UNKNOWN_SOCKET_ERROR',
//           'S_NOT_CONNECTED', 'S_CONNECTING', 'S_CONNECTED',
//           'S_STATUS', 'S_OFF', 'S_INITIALIZE', 'S_STANDBY', 'S_WARMUP', 'S_ON', 'S_COOLDOWN',
//           'S_INFO', 'S_NETWORK_SENDING', 'S_NETWORK_RECEIVED',
//           'ERROR_STRING', 'CR', 'LF', 'PJLINK_ERST_STATUS', 'PJLINK_POWR_STATUS',
//           'PJLINK_PORT', 'PJLINK_MAX_PACKET', 'TIMEOUT', 'ERROR_MSG', 'PJLINK_ERRORS',
//           'STATUS_STRING', 'PJLINK_VALID_CMD', 'CONNECTION_ERRORS']

QString translate (QString a, QString msg);

//# Set common constants.
const char CR = '\r'; // chr(0x0D)  # \r
const char LF = '\n'; // chr(0x0A)  # \n

const int   PJLINK_PORT       = 4352;
const float TIMEOUT           = 30.0;
const int   PJLINK_MAX_PACKET = 136;
// Error and status codes

//const int S_OK = E_OK = 0  // E_OK included since I sometimes forget
const int E_OK = 0;
const int S_OK = 0;


// Error codes. Start at 200 so we don't duplicate system error codes.
const int E_GENERAL                       = 200; // Unknown error
const int E_NOT_CONNECTED                 = 201;
const int E_FAN                           = 202;
const int E_LAMP                          = 203;
const int E_TEMP                          = 204;
const int E_COVER                         = 205;
const int E_FILTER                        = 206;
const int E_NO_AUTHENTICATION             = 207;  // PIN set and no authentication set on projector
const int E_UNDEFINED                     = 208;  // ERR1
const int E_PARAMETER                     = 209;  // ERR2
const int E_UNAVAILABLE                   = 210;  // ERR3
const int E_PROJECTOR                     = 211;  // ERR4
const int E_INVALID_DATA                  = 212;
const int E_WARN                          = 213;
const int E_ERROR                         = 214;
const int E_AUTHENTICATION                = 215;  // ERRA
const int E_CLASS                         = 216;
const int E_PREFIX                        = 217;

// Remap Qt socket error codes to projector error codes
const int E_CONNECTION_REFUSED            = 230;
const int E_REMOTE_HOST_CLOSED_CONNECTION = 231;
const int E_HOST_NOT_FOUND                = 232;
const int E_SOCKET_ACCESS                 = 233;
const int E_SOCKET_RESOURCE               = 234;
const int E_SOCKET_TIMEOUT                = 235;
const int E_DATAGRAM_TOO_LARGE            = 236;
const int E_NETWORK                       = 237;
const int E_ADDRESS_IN_USE                = 238;
const int E_SOCKET_ADDRESS_NOT_AVAILABLE  = 239;
const int E_UNSUPPORTED_SOCKET_OPERATION  = 240;
const int E_PROXY_AUTHENTICATION_REQUIRED = 241;
const int E_SLS_HANDSHAKE_FAILED          = 242;
const int E_UNFINISHED_SOCKET_OPERATION   = 243;
const int E_PROXY_CONNECTION_REFUSED      = 244;
const int E_PROXY_CONNECTION_CLOSED       = 245;
const int E_PROXY_CONNECTION_TIMEOUT      = 246;
const int E_PROXY_NOT_FOUND               = 247;
const int E_PROXY_PROTOCOL                = 248;
const int E_UNKNOWN_SOCKET_ERROR          = -1;

// Status codes start at 300
const int S_NOT_CONNECTED                 = 300;
const int S_CONNECTING                    = 301;
const int S_CONNECTED                     = 302;
const int S_INITIALIZE                    = 303;
const int S_STATUS                        = 304;
const int S_OFF                           = 305;
const int S_STANDBY                       = 306;
const int S_WARMUP                        = 307;
const int S_ON                            = 308;
const int S_COOLDOWN                      = 309;
const int S_INFO                          = 310;

// Information that does not affect status
const int S_NETWORK_SENDING               = 400;
const int S_NETWORK_RECEIVED              = 401;

extern QList<int> CONNECTION_ERRORS;

QString PJLINK_ERRORS(int id);
int PJLINK_ERRORS(QString id);
//PJLINK_ERRORS = {'ERRA': E_AUTHENTICATION,   # Authentication error
//                 'ERR1': E_UNDEFINED,        # Undefined command error
//                 'ERR2': E_PARAMETER,        # Invalid parameter error
//                 'ERR3': E_UNAVAILABLE,      # Projector busy
//                 'ERR4': E_PROJECTOR,        # Projector or display failure
//                 E_AUTHENTICATION: 'ERRA',
//                 E_UNDEFINED:      'ERR1',
//                 E_PARAMETER:      'ERR2',
//                 E_UNAVAILABLE:    'ERR3',
//                 E_PROJECTOR:      'ERR4'}

// Map error/status codes to string
QString ERROR_STRING(int id);

QString STATUS_STRING(int id);

QString ERROR_MSG(int id);

// Map for ERST return codes to string
QString PJLINK_ERST_STATUS(char id);

//PJLINK_ERST_STATUS = {'0': ERROR_STRING[E_OK],
//                      '1': ERROR_STRING[E_WARN],
//                      '2': ERROR_STRING[E_ERROR]}

int PJLINK_POWR_STATUS(QString id);
QString PJLINK_POWR_STATUS(int id);

// Map for POWR return codes to status code
//PJLINK_POWR_STATUS = {'0': S_STANDBY,
//                      '1': S_ON,
//                      '2': S_COOLDOWN,
//                      '3': S_WARMUP}

//PJLINK_DEFAULT_SOURCES = {'1': translate('OpenLP.DB', 'RGB'),
//                          '2': translate('OpenLP.DB', 'Video'),
//                          '3': translate('OpenLP.DB', 'Digital'),
//                          '4': translate('OpenLP.DB', 'Storage'),
//                          '5': translate('OpenLP.DB', 'Network')}

//PJLINK_DEFAULT_CODES  = {'11': translate('OpenLP.DB', 'RGB 1'),
//                         '12': translate('OpenLP.DB', 'RGB 2'),
//                         '13': translate('OpenLP.DB', 'RGB 3'),
//                         '14': translate('OpenLP.DB', 'RGB 4'),
//                         '15': translate('OpenLP.DB', 'RGB 5'),
//                         '16': translate('OpenLP.DB', 'RGB 6'),
//                         '17': translate('OpenLP.DB', 'RGB 7'),
//                         '18': translate('OpenLP.DB', 'RGB 8'),
//                         '19': translate('OpenLP.DB', 'RGB 9'),
//                         '21': translate('OpenLP.DB', 'Video 1'),
//                         '22': translate('OpenLP.DB', 'Video 2'),
//                         '23': translate('OpenLP.DB', 'Video 3'),
//                         '24': translate('OpenLP.DB', 'Video 4'),
//                         '25': translate('OpenLP.DB', 'Video 5'),
//                         '26': translate('OpenLP.DB', 'Video 6'),
//                         '27': translate('OpenLP.DB', 'Video 7'),
//                         '28': translate('OpenLP.DB', 'Video 8'),
//                         '29': translate('OpenLP.DB', 'Video 9'),
//                         '31': translate('OpenLP.DB', 'Digital 1'),
//                         '32': translate('OpenLP.DB', 'Digital 2'),
//                         '33': translate('OpenLP.DB', 'Digital 3'),
//                         '34': translate('OpenLP.DB', 'Digital 4'),
//                         '35': translate('OpenLP.DB', 'Digital 5'),
//                         '36': translate('OpenLP.DB', 'Digital 6'),
//                         '37': translate('OpenLP.DB', 'Digital 7'),
//                         '38': translate('OpenLP.DB', 'Digital 8'),
//                         '39': translate('OpenLP.DB', 'Digital 9'),
//                         '41': translate('OpenLP.DB', 'Storage 1'),
//                         '42': translate('OpenLP.DB', 'Storage 2'),
//                         '43': translate('OpenLP.DB', 'Storage 3'),
//                         '44': translate('OpenLP.DB', 'Storage 4'),
//                         '45': translate('OpenLP.DB', 'Storage 5'),
//                         '46': translate('OpenLP.DB', 'Storage 6'),
//                         '47': translate('OpenLP.DB', 'Storage 7'),
//                         '48': translate('OpenLP.DB', 'Storage 8'),
//                         '49': translate('OpenLP.DB', 'Storage 9'),
//                         '51': translate('OpenLP.DB', 'Network 1'),
//                         '52': translate('OpenLP.DB', 'Network 2'),
//                         '53': translate('OpenLP.DB', 'Network 3'),
//                         '54': translate('OpenLP.DB', 'Network 4'),
//                         '55': translate('OpenLP.DB', 'Network 5'),
//                         '56': translate('OpenLP.DB', 'Network 6'),
//                         '57': translate('OpenLP.DB', 'Network 7'),
//                         '58': translate('OpenLP.DB', 'Network 8'),
//                         '59': translate('OpenLP.DB', 'Network 9')
//                        }

void init_pjlink_constants();

#endif // PJLINK_CONSTANTS_H

