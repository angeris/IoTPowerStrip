#include "Arduino.h"

void setup() {
	// Begin both Serial ports (9600 for computer, 115200 for the
	// wifi module.

	Serial.begin(9600);
	Serial1.begin(115200);
}

void loop() {
	if(Serial1.available()) {
		//Output whatever was received from the WiFi module.
		Serial.println(Serial1.read());
	}

	if(Serial.available()) {
		Serial1.print("AT+PING=google.com");
	}
	
}
