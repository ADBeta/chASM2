#include <chASM2.h>

//Create a chasm strcut for the wanted pin
chasm_t LED_PIN;

//Define a chASM Pin, Pin 13 aka the LED pin
chASM LED_PIN(13);

void setup() {
	chasm_init(&LED_PIN, 13);

	//Set the pin to output
	chasm_setmode(&LED_PIN, OUTPUT);
}

void loop() {
	//Write LED HIGH, then wait
	chasm_write(&LED_PIN, HIGH);
	delay(1000);
	
	//Write LED LOW, then wait
	chasm_write(&LED_PIN, LOW);
	delay(1000);
}
