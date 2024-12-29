This was the very first attempt at a PCB version that combined the relay board, buck converter board, and separate optocoupler

Main Components:
1. ESP32 Module
2. Custom PCB including Relay, Buck Converter, & Optocoupler
3. Blynk Integration for Push Messages / App to trigger the relay

![image](https://github.com/user-attachments/assets/60e22c8a-bd46-43ee-820d-4f76c3db4855)

Issues:
- Many traces were wrong, including the relay trace and missing connections on the main AC connector
- Adding the ESP32 vertically added unneccessary space
- Extra resistor on the optocoupler
- Included unneccessary potentiometer
