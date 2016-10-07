#include <SoftwareSerial.h>;

SoftwareSerial bluetooth(10, 11); // RX, TX
int led = 4;
String receivedBluetoothString = "";

void setup() {
 bluetooth.begin(9600);
 pinMode(led, OUTPUT);
}

void loop() {


 while (bluetooth.available() > 0) {

   char receivedBluetoothChar = bluetooth.read();
   receivedBluetoothString += receivedBluetoothChar;

   if (receivedBluetoothChar == '\n') {

     if (receivedBluetoothString == "Krispy Kreme Port Rd Hotlight is on!") {
       digitalWrite(led, HIGH);
       delay(300);
       digitalWrite(led, LOW);
       delay(300);
       digitalWrite(led, HIGH);
       delay(300);
       digitalWrite(led, LOW);
       delay(300);
       digitalWrite(led, HIGH);
     }
     else if (receivedBluetoothString == "Hotlight is off :(") {
       digitalWrite(led, LOW);
       delay(300);
       digitalWrite(led, HIGH);
       delay(300);
       digitalWrite(led, LOW);
       delay(300);
       digitalWrite(led, HIGH);
       delay(300);
       digitalWrite(led, LOW);
     }

     receivedBluetoothString = "";
   }
 }
}
