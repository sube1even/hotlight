/***********************************************************
BLE CC41A Bluetooth Master setup sketch
This is a clone of the HM10 BLE board
In the Serial Monitor ensure that 'Both NL and CR' is selected
Select a Baud Rate of 9600
enter the following commands into the MASTER unit
AT - should return OK
AT+RENEW - restores to factory settings
AT+RESET - software reset
AT+ROLE1 - sets to Master
AT+INQ - searches for nearby Slave units
AT+CONN1 - connects to Slave Unit 1
************************************************************/
#include <SoftwareSerial.h>
SoftwareSerial bluetooth(10, 11); // RX, TX
void setup()
{
// Start the hardware serial port
Serial.begin(9600);
pinMode(13, OUTPUT); // onboard LED
digitalWrite(13, LOW); // switch OFF LED
bluetooth.begin(9600);
// un REM this to set up a Master and connect to a Slave
/*
Serial.println("BLE CC41A Bluetooth");
Serial.println("----------------------------------");
Serial.println("");
Serial.println("Trying to connect to Slave Bluetooth");
delay(1000);
bluetooth.println("AT"); // just a check
delay(2000);
bluetooth.println("AT+ROLE1"); // st up as Master
delay(2000);
bluetooth.println("AT+INQ"); // look for nearby Slave
delay(5000);
bluetooth.println("AT+CONN1"); // connect to it
*/
}
void loop()
{
bluetooth.listen();
// while there is data coming in, read it
// and send to the hardware serial port:
while (bluetooth.available() > 0) {
char inByte = bluetooth.read();
Serial.write(inByte);
}
// Read user input if available.
if (Serial.available()){
delay(10); // The DELAY!
bluetooth.write(Serial.read());
}
}
