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

     if (receivedBluetoothString.toInt() == 576965) {
       digitalWrite(led, HIGH);
     }
     else if (receivedBluetoothString.toInt() == 488230) {
       digitalWrite(led, LOW);
     }

     receivedBluetoothString = "";
   }
 }
}
