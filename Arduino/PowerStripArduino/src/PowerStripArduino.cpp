#include "Arduino.h"

void commandMode() {
	Serial1.write("+");
	delay(50);
	Serial1.write("+");
	delay(50);
	Serial1.write("+");
	if(!Serial1.find("a")) {
		Serial.println("No ack from WiFi module");
		return;
	}
	Serial1.write("a");

	if(!Serial1.find("+ok")) {
		Serial.println("No ok received from WiFi module");
		return;
	}
}

void setup() {
	// Begin both Serial ports (9600 for computer, 115200 for the
	// wifi module.

	Serial.begin(9600);
	Serial1.begin(115200);
}

void loop() {
	if(Serial.available()) {
		if(Serial.find("1")) {
			Serial.println("Command Received");
			commandMode();
			Serial1.write("AT+PING=192.168.0.1");
		}
	}
	if(Serial1.available()) {
		Serial.write(Serial1.read());
	}
}
