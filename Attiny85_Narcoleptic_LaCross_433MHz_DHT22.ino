/*
*                                ATtiny-85-Version!!!
*
*******************************************************************************************
*   Bei Programmer-Fehler: Dallas Sensor entfernen! Wenn: Mosi = Data & SCK = Sensor !
*   Auf Pin-Belegung der Platine achten!!!!! -> Board_Typ setzen!
*******************************************************************************************
*      Auszug aus der Beschreibung des Herstellers:
– 120 Powerful Instructions – Most Single Clock Cycle Execution
– 32 x 8-bit General Purpose Working Registers
– Up to 20 MIPS Througput at 20 MHz
– 8K Bytes of In-System Programmable Program Memory Flash
– 512 Bytes In-System Programmable EEPROM
– 512 Bytes Internal SRAM
– Write/Erase Cycles: 10,000 Flash/100,000 EEPROM
– Data retention: 20 Years at 85°C/100 Years at 25°C
– 8-bit Timer/Counter with Prescaler and Two PWM Channels
– 8-bit High Speed Timer/Counter with Separate Prescaler
– USI – Universal Serial Interface with Start Condition Detector
– 10-bit ADC: 4 Single Ended Channels, 2 Differential ADC Channel Pairs
– Temperature Measurement
– On-chip Analog Comparator
– Low Power Idle, ADC Noise Reduction, and Power-down Modes
– Internal Calibrated Oscillator
– Six Programmable I/O Lines
– 2.7 - 5.5V Operating Voltage

- Gehäuseform: DIP, 8-polig, Herstellerbezeichnung "ATtiny85-20PU"

*** Fuses auf 8Mhz internal clock gestellt (Standard) und Clock-Divider nicht gesetzt!
avrdude: safemode: Fuses OK (H:FF, E:DF, L:E2)
Uploading to I/O board using 'USBasp'
Uploader started for board ATtiny w/ ATtiny85
Uploader will use programmer name: usbasp
C:\Users\js\AppData\Local\arduino15\packages\arduino\tools\avrdude\6.0.1-arduino5\bin\avrdude "-CC:\Users\js\AppData\Local\arduino15\packages\arduino\tools\avrdude\6.0.1-arduino5/etc/avrdude.conf" -v -pattiny85 -cusbasp -Pusb "-Uflash:w:C:\Users\js\AppData\Local\Temp\VMicroBuilds\ATtiny85_LaCrosse_TempSensor\attiny_attiny_attiny85/ATtiny85_LaCrosse_TempSensor.ino.hex:i"
avrdude: Version 6.0.1, compiled on Apr 15 2015 at 19:59:58
Copyright (c) 2000-2005 Brian Dean, http://www.bdmicro.com/
Copyright (c) 2007-2009 Joerg Wunsch
System wide configuration file is "C:\Users\js\AppData\Local\arduino15\packages\arduino\tools\avrdude\6.0.1-arduino5/etc/avrdude.conf"
Using Port                    : usb
Using Programmer              : usbasp
AVR Part                      : ATtiny85
Chip Erase delay              : 400000 us
PAGEL                         : P00
BS2                           : P00
RESET disposition             : possible i/o
RETRY pulse                   : SCK
serial program mode           : yes
parallel program mode         : yes
Timeout                       : 200
StabDelay                     : 100
CmdexeDelay                   : 25
SyncLoops                     : 32
ByteDelay                     : 0
PollIndex                     : 3
PollValue                     : 0x53
Memory Detail                 :
Block Poll               Page                       Polled
Memory Type Mode Delay Size  Indx Paged  Size   Size #Pages MinW  MaxW   ReadBack
----------- ---- ----- ----- ---- ------ ------ ---- ------ ----- ----- ---------
eeprom        65    12     4    0 no        512    4      0  4000  4500 0xff 0xff
flash         65     6    32    0 yes      8192   64    128 30000 30000 0xff 0xff
signature      0     0     0    0 no          3    0      0     0     0 0x00 0x00
lock           0     0     0    0 no          1    0      0  9000  9000 0x00 0x00
lfuse          0     0     0    0 no          1    0      0  9000  9000 0x00 0x00
hfuse          0     0     0    0 no          1    0      0  9000  9000 0x00 0x00
efuse          0     0     0    0 no          1    0      0  9000  9000 0x00 0x00
calibration    0     0     0    0 no          2    0      0     0     0 0x00 0x00
Programmer Type : usbasp
Description     : USBasp, http://www.fischl.de/usbasp/


ATMEL ATTINY 25/45/85 / ARDUINO

+-\/-+
Ain0 (D 5) PB5  1|    |8  Vcc
Ain3 (D 3) PB3  2|    |7  PB2 (D 2) Ain1
Ain2 (D 4) PB4  3|    |6  PB1 (D 1) pwm1
GND  4|    |5  PB0 (D 0) pwm0
+----+

Install ATtiny - Models in Arduino IDE:
	http://highlowtech.org/?p=1695

ATtiny:
	https://cpldcpu.wordpress.com/2014/04/25/the-nanite-85/

Powersave modes:
================
	http://www.rocketscream.com/blog/2011/07/04/lightweight-low-power-arduino-library/
	http://www.gammon.com.au/forum/?id=11488&reply=9#reply9
	http://gammon.com.au/forum/?id=11497&reply=6#reply6
	http://www.gammon.com.au/power
	https://forum.arduino.cc/index.php?topic=326237.0
	https://www.insidegadgets.com/2011/02/05/reduce-attiny-power-consumption-by-sleeping-with-the-watchdog-timer/
	... und weitere Powersave-Gedanken:
	https://harizanov.com/2013/08/every-%CE%BCa-counts/
	http://electronics.stackexchange.com/questions/49182/how-can-i-get-my-atmega328-to-run-for-a-year-on-batteries

	Hier noch ein weiteres Projekt mit RFM69:
	http://johan.kanflo.com/the-aaduino/
	
	und der Sketch dazu:
	https://github.com/kanflo/aaduino

*
* The LaCrosse-protocol seems to be:
*
Bits 0-3: header
Bits 4-11: device ID, changes when replacing the batteries. Unlike in the post linked above, bit 11 does not appear to be a checksum.
Bits 12-15: either 1111 for automatic transmission (once every 60 seconds) or 1011 for manual transmission (using the button in the battery compartment). Manual transmission does not update the weather station.
Bits 16-27: encode the temperature. The system of encoding decimal digits seems to be ditched in favor of a more elegant one: apply a NOT (change 1 to 0 and 0 to 1), convert to base 10, divide by 10 (into a float), subtract 50, and the result is the temperature in C.
Bits 28-35: encode the relative humidity. Apply a NOT, convert to base 10, and the result is the relative humidity in %.
Bits 36-43: appear to encode a checksum (though I plan to double-check if this is not the dew point, also reported by the weather station).

Example:
HHHH 1000 0010 1111 1101 0010 1111 1101 0011 1010 0100
encoding T=22.0C and RH=44%

*/
//**************************************************************
// Thanks to: http://www.f6fbb.org/domo/sensors/tx3_th.php
// Thanks to: http://forum.arduino.cc/index.php?topic=155483.0
// Thanks to: https://forum.fhem.de/index.php/topic,50333.0.html
//**************************************************************
//  OneWire DS18S20, DS18B20, DS1822 Temperature Version 
//  using this Arduino Library: http://www.pjrc.com/teensy/td_libs_OneWire.html
//  The DallasTemperature library can do all this work for you!
//  http://milesburton.com/Dallas_Temperature_Control_Library
//  http://images.google.de/imgres?imgurl=http://www.tweaking4all.com/wp-content/uploads/2014/03/ds18b20-waterproof.jpg&imgrefurl=http://www.tweaking4all.com/hardware/arduino/arduino-ds18b20-temperature-sensor/&h=988&w=800&tbnid=mowdJDteDQmw_M:&tbnh=104&tbnw=84&docid=7g-v-bKlWHiqKM&usg=__9sTNcsYyWEgAZF-aP5rpUuvCyio=&sa=X&ved=0ahUKEwiRvJfp44HMAhVDDCwKHc1OBgcQ9QEIKjAB
//  http://www.tweaking4all.com/hardware/arduino/arduino-ds18b20-temperature-sensor/
//  https://github.com/PaulStoffregen/OneWire
//  https://arduino-info.wikispaces.com/Brick-Temperature-DS18B20
//  https://arduino-info.wikispaces.com/MultipleTemperatureSensorsToLCD
//  http://www.pjrc.com/teensy/td_libs_OneWire.html
//
//  Hardware Overview and HowTo:
//  http://www.tweaking4all.com/hardware/arduino/arduino-ds18b20-temperature-sensor/
//
//  Additionals:
//  https://gcc.gnu.org/onlinedocs/gcc-3.1/cpp/Standard-Predefined-Macros.html
//	https://gcc.gnu.org/onlinedocs/gcc-3.1/cpp/Invocation.html#Invocation
//  https://gcc.gnu.org/onlinedocs/gcc/Preprocessor-Options.html
//

/* How to connect multiple Sensors:
The DS18B20 Digital Temperature sensor allows you to set multiple in parallel. When doing this, the OneWire library will read all sensors.
For larger networks of sensors (more than 10), using smaller resistors should be considered, for example 1.6 KΩ or even less.
It has been observed that large amounts of sensors (more than 10) in the same network can cause issues (colliding data),
and for that purpose an additional resistor of say 100 … 120 Ω should be added between the data line to the Arduino and the data pin of the sensor, for each sensor !
***/

/*
	Sollte (bei korrektem Aufruf) der DHT22-Treiber schon beim ersten Versuch einen Wert zurückliefern, 
	so handelt es sich nicht um einen aktuellen Messwert. 
	Der DHT22 liefert nämlich beim Aufruf den abgespeicherten Messwert der zurückliegenden Messung und startet parallel einen neuen Messvorgang. 
	Der Hersteller empfiehlt, den Sensor zweimal aufzurufen und nur den letzten Rückgabewert zu verwenden.
*/

/******************************************************************************************************************************************************/
// --- benutze hier lokale Kopien der Libs 
#include "DHT22.h"			// SPARKFUN Lib
#include "Narcoleptic.h"
#include "LaCrosse.h"		// FHEM-Forum: simonberry: https://forum.fhem.de/index.php/topic,50333.0.html

// ATMEL ATTINY45 / ARDUINO
//
//                  +-\/-+
// Ain0 (D 5) PB5  1|    |8  Vcc
// Ain3 (D 3) PB3  2|    |7  PB2 (D 2)  Ain1
// Ain2 (D 4) PB4  3|    |6  PB1 (D 1) pwm1
//            GND  4|    |5  PB0 (D 0) pwm0
//                  +----+

#define BOARD_TYP_1		YES

#ifdef BOARD_TYP_1
	#define SENSOR_PIN			3	  //   PIN2 
	#define TX_433_PIN          4     //   PIN3 	- PIN_SEND in LaCrosse.cpp
#else
	#define SENSOR_PIN			3      // PB3
	#define TX_433_PIN          4      // PB4  
#endif

#define PIN_SEND			TX_433_PIN		//--- where digal pin 433 Sender (TX) is connected PB0 on ATtiny-85 

//*********************************************
#define SENSORID				123					// Sensor-ID wird in Setup-Methode gesetzt!
//*********************************************
#define DHT22_PIN				SENSOR_PIN
//*********************************************

// Setup a DHT22 instance
DHT22 myDHT22(DHT22_PIN);

//--- t,h:  global float-vars as Temperature and Humidity members of LaCrosseClass 
float temp;   
float hum; 

//------------------------------------------------
void setup()
{ 
	//--- inits
	pinMode(PIN_SEND, OUTPUT);	

	//--- preset SensorId
	LaCrosse.bSensorId = SENSORID;
}
//-----------------------------------
void loop()
{
	//--- The sensor can only be read from every 1-2s, and requires a minimum
	//--- 2s warm-up after power-on.
	LaCrosse.sleep(2);	//--- two seconds, no deep sleep 


	//Hinweis zum Auslesen des DHT22 :
	//	https://forum.fhem.de/index.php/topic,47090.0.html
	//	Sollte(bei korrektem Aufruf) der DHT22 - Treiber schon beim ersten Versuch einen Wert zurückliefern, 
	//	so handelt es sich nicht um einen aktuellen Messwert.Der DHT22 liefert nämlich beim Aufruf den abgespeicherten Messwert 
	//	der zurückliegenden Messung und startet parallel einen neuen Messvorgang.Der Hersteller empfiehlt, 
	//	den Sensor zweimal aufzurufen und nur den letzten Rückgabewert zu verwenden.

	DHT22_ERROR_t errorCode = myDHT22.readData();	
	//LaCrosse.sleep(1);
	//errorCode = myDHT22.readData(); // doppelte Auslesung um aktuellen Wert zu erhalten
	switch (errorCode)
	{
		case DHT_ERROR_NONE:
			//---Get Data
			temp = myDHT22.getTemperatureC();
			hum  = myDHT22.getHumidity();
			break;
		case DHT_ERROR_CHECKSUM:
			//--- send erraneous data as err indicator
			temp = -99.99;
			hum  = -99.99;
			break;
		case DHT_BUS_HUNG:
			temp = -88.88;
			hum  = -88.88;		
			break;
		case DHT_ERROR_NOT_PRESENT:
			temp = -77.77;
			hum  = -77.77;		
			break;
		case DHT_ERROR_ACK_TOO_LONG:
			temp = -66.66;
			hum  = -66.66;		
			break;
		case DHT_ERROR_SYNC_TIMEOUT:
			temp = -55.55;
			hum  = -55.55;		
			break;
		case DHT_ERROR_DATA_TIMEOUT:
			temp = -44.44;
			hum  = -44.44;		
			break;
		case DHT_ERROR_TOOQUICK:
			temp = -33.33;
			hum  = -33.33;
			break;
		default:		
			temp = -22.22;
			hum  = -22.22;
	}

	//--- transfer measured values to LaCrosse-instance
	LaCrosse.t = temp; 
	LaCrosse.h = hum; 
	LaCrosse.sendTemperature(); 	
	LaCrosse.sleep(1);        /* 1 second, no power-reduction! */
	LaCrosse.sendHumidity();

	//--- preserve power during sleep phase 
	//pinMode(SENSOR_PIN, INPUT);   //--- not working with DHT-Instance?
	LaCrosse.setTxPinMode(INPUT);

	//--- we will wait some minutes in reduced power consumption until next data are send. 
	Narcoleptic.delay_minutes(3); 

	//--- set back to normal operation mode
	//pinMode(SENSOR_PIN, OUTPUT);	//--- not working with DHT-Instance?
	LaCrosse.setTxPinMode(OUTPUT);
}
