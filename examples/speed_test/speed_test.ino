/*
	This example is purely to objectively show and measure the speed difference
	between the built-in functions vs my library.
	
	An oscilloscope, frequency counter or some other form of external equipment
	is required to measure the signals.
	
	****************************************************************************
	
	****************************************************************************
*/

#include "chASM2.h"
//Declare both pins, one is a chASM2 pin the other is a built-in pin
#define slowPin 10
chasm_t fastPin;

void setup() {
	chasm_init(&fastPin, 10);

	//Configure the pin to be an OUTPUT
	chasm_setmode(&fastPin, OUTPUT);
	
	//Unrolled the loop so speed is more directly comparable per test.	
	//Uncomment the test you wish to test
	while(true) {
		/** Fast pin **/
		/*
		chasm_write(&fastPin, HIGH);
		chasm_write(&fastPin, LOW);
		chasm_write(&fastPin, HIGH);
		chasm_write(&fastPin, LOW);
		chasm_write(&fastPin, HIGH);
		chasm_write(&fastPin, LOW);
		chasm_write(&fastPin, HIGH);
		chasm_write(&fastPin, LOW);
		*/
		
		//36 bytes for a high low pulser
		
		//18 bytes per chasm_write(HIGH)
		/** Slow Pin **/
		/*
		digitalWrite(slowPin, HIGH);
		digitalWrite(slowPin, LOW);
		digitalWrite(slowPin, HIGH);
		digitalWrite(slowPin, LOW);
		digitalWrite(slowPin, HIGH);
		digitalWrite(slowPin, LOW);
		digitalWrite(slowPin, HIGH);
		digitalWrite(slowPin, LOW);
		*/
	}
}

void loop() {
}
