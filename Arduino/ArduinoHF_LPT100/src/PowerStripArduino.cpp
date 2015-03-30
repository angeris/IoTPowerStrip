#include "Arduino.h"
#include "WiFiLib.h"

void setup() {
	Serial.begin(9600);

	if(initialize() < 0)
		Serial.println("Init failed.");

}

void loop() {
	if(Serial.available()) {
		switch(Serial.read()) {
		case 'h':
			Serial1.write("AT+H\r");
			break;
		}
	}
	if(Serial1.available()) {
		Serial.write(Serial1.read());
	}
}
