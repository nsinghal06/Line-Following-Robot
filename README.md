# Line-Following Robot

An **autonomous, line-following and Bluetooth-controlled robot** built using an Arduino microcontroller.  
This project combines **embedded programming, circuit design, sensor integration, and 3D mechanical design** to create a robot capable of autonomous navigation and wireless control.

---

## Features
- **3D-Printed Chassis:** Designed and fabricated a custom robot frame using AutoCAD and 3D printing.
- **Embedded Control:** Programmed Arduino to drive DC motors through an H-bridge and process IR sensor inputs for line detection and path correction.
- **Sensor Integration:** Implemented multiple IR sensors (digital and analog) with real-time serial monitoring and debugging.
- **Wireless Communication:** Added Bluetooth control via the Adafruit Bluefruit app for manual override and wireless testing.
- **Competition Performance:** Competed in a university Line-Tracking & Bluetooth-Control competition, placing **5th out of 15 teams**.

---

## Components & Tools
| Category | Items |
|-----------|-------|
| **Hardware** | Arduino Uno, L298N H-Bridge, DC Motors, IR Sensors, Li-ion Battery Pack |
| **Software** | Arduino IDE (C/C++), AutoCAD, Adafruit Bluefruit App |
| **Skills Used** | Circuit Design, Embedded Systems, 3D Modeling & Printing, Sensor Calibration, Motor Control |

---

## How It Works
1. The IR sensors detect the black line on a white surface.  
2. The Arduino processes sensor input to adjust the DC motor speeds through an H-bridge.  
3. When Bluetooth mode is activated, the Adafruit app sends commands wirelessly to control direction and speed.  

---

## Future Improvements
- Add PID control for smoother turns  
- Implement ultrasonic sensors for obstacle avoidance  
- Upgrade chassis design with lighter materials  

---

## Results
Placed **5th out of 15** teams in the line-tracking and Bluetooth-control competition.

---

## Gallery
*(Add images here — e.g. photos of your robot or screenshots of your circuit and 3D model)*  
