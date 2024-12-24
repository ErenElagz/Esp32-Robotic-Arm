// Libraries
#include <ESP32Servo.h>
#include "BluetoothSerial.h"

// Objects
BluetoothSerial SerialBT;
Servo servo1;
Servo servo2;
Servo servo3;

// Variables
#define ELECTROMAGNET_PIN 23  // ElectroMagnet Pin
int angle1 = 90;  // Servo 1 Starting Angle
int angle2 = 90;  // Servo 2 Starting Angle
int angle3 = 90;  // Servo 3 Starting Angle

// Setup
void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_RobotArm");  // Bluetooth Device Name
  Serial.println("Bluetooth Started. Robotic Arm Ready.");

  servo1.attach(25);  // Servo1 pin
  servo2.attach(26);  // Servo2 pin
  servo3.attach(27);  // Servo3 pin

  pinMode(ELECTROMAGNET_PIN, OUTPUT);
  digitalWrite(ELECTROMAGNET_PIN, LOW);  // Elektromagned is off in setup

  // Servos in the Starting Position
  servo1.write(angle1);
  servo2.write(angle2);
  servo3.write(angle3);
}

// Loop
void loop() {
  //Bluetoth Connection
  if (SerialBT.available()) {
    String command = SerialBT.readStringUntil('\n');
    command.trim();

    // Angle 1 Controller
    if (command.startsWith("S1:")) {
      angle1 = command.substring(3).toInt();
      angle1 = constrain(angle1, 0, 180);
      servo1.write(angle1);
      SerialBT.println("Servo1 açısı: " + String(angle1));
    }

    // Angle 2 Controller
    else if (command.startsWith("S2:")) {
      angle2 = command.substring(3).toInt();
      angle2 = constrain(angle2, 0, 180);
      servo2.write(angle2);
      SerialBT.println("Servo2 açısı: " + String(angle2));
    } 

    // Angle 3 Controller
    else if (command.startsWith("S3:")) {
      angle3 = command.substring(3).toInt();
      angle3 = constrain(angle3, 0, 180);
      servo3.write(angle3);
      SerialBT.println("Servo3 açısı: " + String(angle3));
    } 

    // Electro Magnetic Open
    else if (command == "MAGNET_ON") {
      digitalWrite(ELECTROMAGNET_PIN, HIGH);
      SerialBT.println("Elektromıknatıs: Açık");
    } 

    // Electro Magnetic Off
    else if (command == "MAGNET_OFF") {
      digitalWrite(ELECTROMAGNET_PIN, LOW);
      SerialBT.println("Elektromıknatıs: Kapalı");
    } 

    // Error Handling
    else {
      SerialBT.println("Bilinmeyen komut: " + command);
    }
  }
}
