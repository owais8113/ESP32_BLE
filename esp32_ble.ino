#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_BT"); // Name of the Bluetooth device
  Serial.println("The device started, now you can pair it with Bluetooth!");
}

void loop() {
  if (SerialBT.available()) {
    String received = SerialBT.readString();
    Serial.print("Received: ");
    Serial.println(received);
    
    // Echo the received data back to the Bluetooth client
    SerialBT.print("Echo: ");
    SerialBT.println(received);
  }
  
  // If data is available on the Serial Monitor, send it via Bluetooth
  if (Serial.available()) {
    String data = Serial.readString();
    SerialBT.print("Serial data: ");
    SerialBT.println(data);
  }
}
