# PowerStripArduino.cpp

Main class which is run by the Arduino module.

# WiFiLib.h

**WiFiLib.h** contains the following methods. All of the commands used can be found in the [HF-LPT100 documentation](https://gridconnect.box.com/shared/static/ymp3ombs5gpciedzl8rw.pdf). *Please* read through this before making any changes to the code.

## int commandModeEnable()
Enables the command mode if not already enabled by the following protocol:

 - Send +++ each separated by at most 300ms.
 - Receive an ACK as "a" and then send an ACK ("a") after receiving this
 - A "+ok" should be returned by the module.

Returns -1 if there is no ACK or if there is no +ok received. Otherwise returns 0.

**Note:** You can only enable the command mode *once* every time the device is restarted.

## int initialize()
Initializes the WiFi module directly to the command mode. Returns -1 if the command mode cannot be enabled and 0, otherwise.


# TODO
- Connect the device either to (a) Stanford's networks, or (b) to a bridged connection *for testing purposes only*. This should be able to ping, say, google.com and a local server in the network (the controlling computer would be the ideal case).

- Begin implementing methods for receiving and decoding TCP packets by following the Python API found in [Dan's Repository](https://github.com/danXyu/powerstrip_arduino_api). This should be done within the **WiFiLib.h** library.
