# ESP32 Robotic Arm with Bluetooth Control

## Description
This project demonstrates how to control a robotic arm using an ESP32 microcontroller. The arm has three servo motors and an electromagnet, which can be controlled via Bluetooth commands.

## Features
- Control three servo motors to adjust the robotic arm angles.
- Toggle an electromagnet on and off for object manipulation.
- Communicate with the ESP32 using Bluetooth commands.

## Components Required
- ESP32 microcontroller
- 3 x Servo motors
- Electromagnet
- Power supply
- Connecting wires
- Breadboard or PCB

## Pin Configuration
| Component          | ESP32 Pin |
|--------------------|-----------|
| Servo 1           | GPIO 25   |
| Servo 2           | GPIO 26   |
| Servo 3           | GPIO 27   |
| Electromagnet     | GPIO 23   |

## Software Requirements
- Arduino IDE
- ESP32 board library
- ESP32Servo library

## Installation
1. Install the [Arduino IDE](https://www.arduino.cc/en/software/).
2. Add the ESP32 board library to the Arduino IDE.
   - Go to `File > Preferences`.
   - Add the following URL to the "Additional Board Manager URLs":
     ```
     https://dl.espressif.com/dl/package_esp32_index.json
     ```
   - Open `Tools > Board > Board Manager` and install the ESP32 library.
3. Install the ESP32Servo library via `Sketch > Include Library > Manage Libraries`.

## Code Explanation
### Libraries Used
- **ESP32Servo**: To control the servo motors.
- **BluetoothSerial**: To enable Bluetooth communication.

### Pin Definitions
- **ELECTROMAGNET_PIN**: GPIO 23 controls the electromagnet.
- Servo pins are GPIO 25, 26, and 27.

### Commands
The ESP32 accepts the following commands via Bluetooth:
| Command           | Description                                |
|-------------------|--------------------------------------------|
| `S1:<angle>`      | Set Servo 1 angle (0–180 degrees)         |
| `S2:<angle>`      | Set Servo 2 angle (0–180 degrees)         |
| `S3:<angle>`      | Set Servo 3 angle (0–180 degrees)         |
| `MAGNET_ON`       | Turn the electromagnet on                 |
| `MAGNET_OFF`      | Turn the electromagnet off                |

### Setup
1. Initialize Bluetooth with the name `ESP32_RobotArm`.
2. Attach the servos to their respective pins.
3. Set the servos to their starting angles.
4. Configure the electromagnet pin as an output and set it to `LOW`.

### Loop
- Check for incoming Bluetooth commands.
- Parse commands to control the servo angles or electromagnet state.
- Handle unrecognized commands gracefully.

## Usage
1. Upload the code to the ESP32 using the Arduino IDE.
2. Pair the ESP32 with your phone or computer using Bluetooth.
3. Use a Bluetooth terminal app to send commands.
   - Example apps: "Serial Bluetooth Terminal" for Android or "LightBlue" for iOS.
4. Send the appropriate commands to control the robotic arm.

## Example Commands
- Set Servo 1 to 45 degrees:
  ```
  S1:45
  ```
- Turn on the electromagnet:
  ```
  MAGNET_ON
  ```
- Set Servo 2 to 90 degrees:
  ```
  S2:90
  ```

## Troubleshooting
- Ensure the ESP32 is powered correctly.
- Verify that the servos and electromagnet are properly connected.
- Check for any syntax errors in the Bluetooth commands.

## License
This project is open-source and available under the MIT License.

## Author
This code and documentation were created for educational and experimental purposes.

