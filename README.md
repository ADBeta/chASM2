# chASM2 - Control Hardware /with/ ASM using lightweight C

chASM2 is a revsions of chASM, with the same goals, but using C instead of C++
The speed and Storage/Memeory overhead has been improved, this is especially
useful for weak MCUs like the Attiny Series

This library natively supports and has been tested with:
* Arduino Uno
* Arduino Nano
* Arduino Mega
* Ardunio Pro Mini
* ATTiny Family

chASM2 Should work on any platform that supports the post Arduino 1.0 IDE method
of digitalWrite/digitalRead, since chASM2 relies on the same `digitalPinToMask`
etc functions that the built-in methods use too.
----

To improve speed and memory overhead, chASM2 has no safety in terms of NULL
checking, or malfored data during execution - Due to this, it's recommended
you are familiar with how C works before using this library

## Usage
When using chASM2, you need to define a chasm_t struct to stand in as a pin,
you can then pass that struct pointer to functions to perform IO Operations

To declare a chASM2 Pin
```C
chasm_t pin;

//In Setup or other function before using he pin
//13 is the pin number, can be anything supported by the hardware
chasm_init(&pin, 13);
```

To set the mode of the chASM2 Pin
```C
chasm_setmode(&pin, t_MODE); //Supports 0/1 or INPUT, OUTPUT and INPUT_PULLUP
```

To Read and Write a bit of the chASM Pin
```C
chasm_write(&pin, bool); //Supports HIGH/LOW 0/1
chasm_read(&pin); //Returns bool, 1/0
```

## Notes
### Speed Measurements:
Testing was done an an offical `Arduino Uno R3`
All tests have been conducted with a Racal-Dana 9914 VHF Freq. Counter, which
has been calibrated to +/- 8Hz accuracy

Psuedo Code:
```C
void loop() {
	write( HIGH );
	write( LOW );
}
```
digitalWrite:  111.7KHz  
chASM2:        661.8KHz    5.92x faster  

```C
void loop() {
	write( HIGH );
	write( LOW );
	write( HIGH );
	write( LOW );
	write( HIGH );
	write( LOW );
	write( HIGH );
	write( LOW );
}
```
digitalWrite:  112.8KHz  
chASM2:        705.0KHz    6.25x faster  

### Storage Profiling
Due to some functions being inlined, they take some amount of Program Storage:  
With chASM2, both `write(HIGH)` and `write(LOW)` take 18 bytes per call, or 36
bytes for a `write(HIGH), write(LOW)` toggle operation. This is an improvement
over chASM (v1) - also consider that this is a consistant and linear overhead, 
whereas the first call to `digitalWrite` takes 160 bytes, and all subsequent 
calls take 0 to 20 bytes, averging 10 bytes per call. 

This means chASM2 is far more efficient with Program Storage; around 9 calls to 
chASM2 will take the same amount of space as a the first call to digitalWrite.

## TODO
* Look into analogRead support for this library.

----
<b>(c) ADBeta 2023</b>
This software is under the GPL v2.0 licence. Please read the LICENCE file
