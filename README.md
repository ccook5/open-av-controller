open-av-controller
==================

Program to control Pro/Semi Pro AV systems including PJLink projectors, Kramer(tm) video switchers and the Behringer(tm) x32.

This isn't at a usable stage yet. Use at your own risk, and feel free to contribute.

This will have two halves, a python Web.py/jQuery program to control everything, and then an Arduino ethernet program to provide a physical interface.

In order to use the arduino half, you will need to make the interface yourself. This will involve purchasing the hardware and electronic components, uploading the firmware, building the electronics and the enclosure. This is not a simple thing.

I also plan to implement a temperature sensor and graphing system on the Raspberry Pi. This will use a DS18B20 digital thermometer.


Contents
--------

1. PJ Link info
2. Kramer info
3. Behringer x32 info
4. Arduino info
5. Raspberry Pi info
6. Building the interface.

PJLink info
-----------

This is a fairly standard protocol for controlling video projectors over ethernet. Many newer projectors support it, although not all of them. Its well documented online, and a quick google will provide more info than we can fit in here.

We will probably use this python module for this: https://pypi.python.org/pypi/pjlink


Kramer info
-----------

Kramer use 2 different protocols for controlling there matrix switchers, 'Protocol 2000' and 'Protocol 3000'. These can be sent over RS232 or ethernet. The exact features available depend on the device(s) you are using.

The documentation for these protocols is availible on the Kramer website:
http://www.kramerelectronics.co.uk/downloads/protocols/protocol_2000_rev0_51.pdf
http://www.kramerelectronics.co.uk/downloads/protocols/protocol_3000_full.pdf

Not mentioned in the documentation is the fact that Protocol 2000 over ethernet uses TCP port 5000. Wireshark is useful for diagnosing problems with these protocols. There are a number of tools on the Kramer website that you can packet sniff to gain more insight into the protocols.

Products may only support one of the protocols, or they may support both. I have no knowledge of which products support what, but it is listed in the product specs.



Behringer x32 info
------------------

This is a fairly new digital sound desk from Behringer. It has 32 inputs, 6 aux inputs and 16 outputs. Its pretty cool. The desk can be controlled via OSC over ethernet. There is a python module for OSC which we will likely use for this.

Our x32 has now arrived! We love it so far. It does exactly what we want. We have had it running pretty much continuously for the last 2 months and not had a single crash or reliability issue. 

Under the testing folder, there are two sketches, one for a basic remote control using a couple of potentiometers to remotely control channels on the x32. The other is an attempt at making the flying faders do a sine wave type thing that you may have seen on other digital desks. This one is pretty useless other than being cool.

Both of these projects have had minimal testing. The waves one has actually had no testing with the desk. Its close enough to the other one that I think it will roughly do what it is intended to do.

You will need this Arduino OSC module: https://github.com/CNMAT/OSC

Like everything else here, use at your own risk. I recommend testing without anything else connected to your desk, especially outputs.

Arduino info
------------

We will use an Arduino with built in Ethernet and POE for a physical interface. It will communicate via http with the Raspberry Pi


Raspberry Pi info
-----------------

This will run the main python app, and have a web interface for tablets and PCs.


Building the interface.
-----------------------

This will require you to drill holes in the box to mount switches etc. If care is not used, the end result may be less than professional.
