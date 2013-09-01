#include <OSCMessage.h>
#include <Ethernet.h>
#include <EthernetUdp.h>
#include <SPI.h>    
#include <OSCMessage.h>

EthernetUDP Udp;

/**********************************************************************************
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
 * 4. Test with your Behringer x32. Please turn off all your amps/inductive loops 
 *    etc to protect your system until you are happy this works.
 * 5. Finish and install your new controller.
 * 
 *************************************************************/

// You will need to enter the mac address written on the underside of most Arduino 
// Ethernet boards or Ethernet Shields. If you have an old one without, you will 
// need to make one up, and it needs to be unique on your network

byte mac[] = {  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

IPAddress                     ourIp   (192, 168, 0, 108);
IPAddress             destinationIp   (192, 168, 0, 100);

const unsigned int          ourPort = 10023;
const unsigned int destinationtPort = 10023;

/*************************************************************************************
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

int              current_value[7]      = { 0,  0,  0,  0,  0,  0,  0 };

  
void setup()
{
    Serial.begin(9600);

    Ethernet.begin(mac, ourIp);
    Udp.begin(10023);
}

void read_and_send_channel(int channel)
{
    int value = analogRead(channel_analog_pin[channel]);
    
    Serial.println("channel: ");
    Serial.print(channel);
    Serial.println("value: ");
    Serial.print(value);
    
    if (current_value[channel] != value)
    {        
        OSCMessage msg(channel_address[channel]);
        msg.add( value * (1.0 / 1024.0) );
      
        Udp.beginPacket(ourIp, ourPort);
        msg.send(Udp);
        Udp.endPacket();
        msg.empty();
    }
}

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

