#include "Arduino.h"

int initialize();
int commandModeEnable();

int initialize() {
  Serial1.begin(115200);
  if(commandModeEnable()<0)
    return -1;
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
