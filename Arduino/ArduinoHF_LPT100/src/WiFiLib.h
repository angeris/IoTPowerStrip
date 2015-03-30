#include "Arduino.h"

#define SHORT_MESSAGE_LENGTH 20

int initialize();
int commandModeEnable();
int checkCommandMode();
int pingIP(String in);

int initialize() {
  // Initializes the serial port and returns if the module is in Command mode.
  Serial1.begin(115200);
  return checkCommandMode();
}

int commandModeEnable() {
  /* Enabling the command mode for the WiFi module. Protocol: send +++ each
   * separated by at most 300ms. Receive an ACK as "a" and then send an ACK
   * ("a") after receiving this. A "+ok" should be returned by the module.
   */
  Serial1.write('+');
  delay(30);
  Serial1.write('+');
  delay(30);
  Serial1.write('+');

  if(!Serial1.find("a")) {
    Serial.println("No ACK from the WiFi Module");
    return -1;
  }

  Serial1.write('a');

  if(!Serial1.find("+ok")) {
    Serial.println("No +ok from the module");
    return -1;
  }

  Serial.println("Command mode enabled");
  return 0;
}

int checkCommandMode() {
  Serial1.print("AT+\r");
  return Serial1.find("+ok");
}

int pingIP(String in) {
  /* Ping the given IP/Hostname and return whether the host timed out (-2)
   * if the host is unknown (-3) or if the host returned a success (1). This
   * method returns -1 if the module is not in Command mode. If, for some
   * reason, the module responds something else, a value of -5 is returned.
   */
  if(!checkCommandMode()) return -1;

  String _received[SHORT_MESSAGE_LENGTH];
  byte idx = 0;

  while(Serial1.available()>0 && idx<SHORT_MESSAGE_LENGTH-1) {
    _received[idx] = Serial1.read();
    idx++;
    _received[idx] = '\0';
  }

  if(_received.indexOf("Success")>-1) return 1;
  if(_received.indexOf("Timeout")>-1) return -2;
  if(_received.indexOf("Unknown")>-1) return -3;
  return -5;
}
