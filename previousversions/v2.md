This was the very first attempt at a PCB version that combined the relay board, buck converter board, and separate optocoupler

Main Components:
1. ESP32 Module
2. Custom PCB including Relay, Buck Converter, & Optocoupler
3. Blynk Integration for Push Messages / App to trigger the relay

<img width="376" alt="image" src="https://github.com/user-attachments/assets/17a36121-2cff-44e2-bf4e-f614a5cd41ff" />

Issues:
- Many traces were wrong, including the relay trace and missing connections on the main AC connector
- Adding the ESP32 vertically added unneccessary space
- Extra resistor on the optocoupler
- Included unneccessary potentiometer
