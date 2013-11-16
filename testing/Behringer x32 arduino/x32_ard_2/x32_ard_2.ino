#include <OSCMessage.h>
#include <Ethernet.h>
#include <EthernetUdp.h>
#include <SPI.h>    
#include <OSCMessage.h>

EthernetUDP Udp;

/************************************************************************************
 *
 * This sketch is for a controller for a Behringer x32 Sound desk.
 *
 * It uses the analog inputs, and you will need to connect a potentiometer/variable 
 * resistor to the analog inputs.
 *
 * This is provided for information only, and you use it at your own risk.
 *
 * Installing:
 * 
 * You will need to do the following steps:
 * 1. change the mac address below to match your arduino.
 * 2. check you are happy with the channels you want to control. By default we 
 *    change the first six mix busses, and route input channels to the mix bus. 
 *    This lets us override the controler at the sound desk by muting the mix busses.
 * 3. Compile and upload this sketch using the arduino software.
 * 4. Test with your Behringer x32. Please turn off all your amps/inductive loops/outputs 
 *    etc to protect your system until you are happy this works.
 * 5. Finish and install your new controller.
 * 
 ************************************************************************************/

// You will need to enter the mac address written on the underside of most Arduino 
// Ethernet boards or Ethernet Shields. If you have an old one without, you will 
// need to make one up, and it needs to be unique on your network

byte mac[] = {  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

IPAddress                     ourIp   (192, 168, 0, 108);
IPAddress             destinationIp   (192, 168, 0, 100);

const unsigned int          ourPort = 10023;
const unsigned int destinationtPort = 10023;

/************************************************************************************
 * address format examples:
 *
 *  "/bus/01/mix/fader"   - mix busses      - x32 has 16 mix busses
 *  "/ch/01/mix/fader"    - microphone channels     - 32 channels
 *  "/auxin/01/mix/fader" - aux input channels      - 8 channels
 *  "/fxrtn/01/mix/fader" - Effects return channels - 8 channels
 *  "/mtx/01/mix/fader"   - matrix outputs          - 6 channels
 *  "/main/st/mix/fader"  - main stereo output      - 1 stereo channel
 *  "/main/m/mix/fader"   - main mono output        - 1 channel
 *  "/dca/1/fader"        - dca groups              - 6 channels
 *
 * For more possibilities see Behringer OSC documents for the x32 on their website.
 *
 ************************************************************************************/

int              channel_enabled[7]   = { 0, 1, 1, 1, 1, 0, 0 };

char*            channel_address[] = { "",
                                       "/bus/01/mix/fader",
                                       "/bus/02/mix/fader",
                                       "/bus/03/mix/fader",
                                       "/bus/04/mix/fader",
                                       "/bus/05/mix/fader",
                                       "/bus/06/mix/fader"
                                     };

const int        channel_analog_pin[7] = { 0, A0, A1, A2, A3, A4, A5 };

int              last_value[7]      = { 0,  0,  0,  0,  0,  0,  0 };

  
void setup()
{
    Serial.begin(9600);

    Serial.println("Booting, please wait....");
    Serial.println("Booting may take up to 2 minutes.");
    Serial.println("Initialising Ethernet: ");
    
    Ethernet.begin(mac, ourIp);

// In theory, we can requst an IP address via dhcp. In practise, I have found 
// this does't work too well.
// If you use this code, you might find it just hangs at this point...
/*  if (Ethernet.begin(mac) == 0)
    {
        Serial.println("Failed to configure Ethernet using DHCP");
        
        Ethernet.begin(mac, ourIp);
    } else {    
        Serial.println("done!");
    }
*/

    Serial.println(Ethernet.localIP());
    
// set local (source) udp port.
    Udp.begin(10023);
}


/** @returns the difference between value and zero (ie inverts a negative number).
 *
 * This is here because the arduino abs() function/macro had too many issues.
 * I added this whilst working on a bug, but this might not have been the cause. 
 * It might weel be safe to remove this and replace the function call in the next 
 * function (read_and_send_channel(int)).
 */
signed int sensible_abs(signed int value)
{
    if (value < 0) {
        return -value;
    } else {
        return value;
    }
}


/* reads a value from channel, and outputs an osc message.
 * We get the arduino pin from channel_analog_pin[] (defined at the start of this file), 
 * and the desk channel from channel_address[] (also at the start of this file).
 * If there is only a small change (less than allowed_diff), we don't output a message.
 * The arduino inputs are quite sensitive, and will constantly fluctuate. 
 */
void read_and_send_channel(int channel)
{
    signed int value        = analogRead(channel_analog_pin[channel]);
    signed int diff_val     = last_value[channel] - value;
    signed int allowed_diff = 20;
    
    if (sensible_abs(diff_val) > allowed_diff)
    {
        Serial.print   ( "\nchannel          : "        );
        Serial.print   ( channel                        );
        Serial.print   ( "\nold value        : "        );
        Serial.print   ( last_value[channel]            );
        Serial.print   ( "\nvalue            : "        );
        Serial.print   ( value                          );
        Serial.print   ( "\ndiff value       : "        );
        Serial.print   ( diff_val                       );
        Serial.print   ( "\nsensible_abs diff: "        );
        Serial.println ( sensible_abs( diff_val)        );
    
        Udp.beginPacket( destinationIp, destinationPort );

        OSCMessage msg ( channel_address[channel]       );
        msg.add        ( value * (1.0 / 1024.0)         );
        msg.send       ( Udp                            );
 
        Udp.endPacket  ();
      
        msg.empty      ();
 
        last_value[channel] = value;
    }
}

/* Main loop. We run the setup() function defined further up this file, then we run this 
 * bit until the arduino gets turned off.
 * We check 6 channels, and only check each channel if it is enabled in channel_enabled[] at the start of this file.
 */
void loop()
{
    for (int c = 0; c < 7; c++)
    {
        if (channel_enabled[c] != 0)
        {
            read_and_send_channel(c);
            delay(20);
        }
    }
}

