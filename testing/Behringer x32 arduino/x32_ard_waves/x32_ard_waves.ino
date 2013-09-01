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
 * It will make the faders move in a sine wave
 *
 * This is provided for information only, and you use it at your own risk.
 *
 * Installing:
 * 
 * You will need to do the following steps:
 * 1. change the mac address below to match your arduino.
 * 3. Compile and upload this sketch using the arduino software.
 * 4. Test with your Behringer x32. Please turn off all your amps/inductive loops 
 *    etc to protect your system until you are happy this works.
 * 5. Enjoy.
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
 * 
 * For more possibilities see Behringer OSC documents for the x32 on their website.
 *
 ************************************************************************************/

char*            channel_address[] = { "/bus/01/mix/fader",
                                       "/bus/02/mix/fader",
                                       "/bus/03/mix/fader",
                                       "/bus/04/mix/fader",
                                       "/bus/05/mix/fader",
                                       "/bus/06/mix/fader",
                                       "/bus/07/mix/fader",
                                       "/bus/08/mix/fader",
                                       "/bus/09/mix/fader",
                                       "/bus/10/mix/fader",
                                       "/bus/11/mix/fader",
                                       "/bus/12/mix/fader",
                                       "/bus/13/mix/fader",
                                       "/bus/14/mix/fader",
                                       "/bus/15/mix/fader",
                                       "/bus/16/mix/fader",
                                       "/dca/1/fader",
                                       "/dca/2/fader",
                                       "/dca/3/fader",
                                       "/dca/4/fader",
                                       "/dca/5/fader",
                                       "/dca/6/fader",
                                       "/dca/7/fader",
                                       "/dca/8/fader"
                                     };


  
void setup()
{
    Serial.begin(9600);
/*
    Ethernet.begin(mac, ourIp);
    Udp.begin(10023);*/
}

float deg2rads(int deg)
{
    return deg * (3.1412 / 180);
}

void read_and_send_channel(int channel, int step_no)
{
    float value = (sin(deg2rads((channel + step_no) *30)) / 2) + 0.5;
    
    Serial.print(step_no);
    Serial.print(" channel: ");
    Serial.print(channel);
    Serial.print("  value: ");
    Serial.println(value);
    
    OSCMessage msg(channel_address[channel]);
    msg.add( value );
      
    Udp.beginPacket(ourIp, ourPort);
    msg.send(Udp);
    Udp.endPacket();
    msg.empty();
}

void loop()
{
    for (int i = 0; i < 12; i += 1)
    {
        for (int c = 0; c < 24; c++)
        {
            read_and_send_channel(c, i);
        }
        delay(200);
    }
}

