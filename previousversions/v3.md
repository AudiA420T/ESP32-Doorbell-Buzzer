This was the second attempt at a PCB version that fixed many of the previous issues previously faced.

Changes Made:
- Fixed all traces with issues
- Moved ESP32 female headers from vertical to horizontal to save space
- Removed extra unneccessary resistor on optocoupler circuit
- Removed unneccessary potentiometer

Main Components:
1. ESP32 Module
2. Custom PCB including Relay, Buck Converter, & Optocoupler
3. Blynk Integration for Push Messages / App to trigger the relay

<img width="336" alt="image" src="https://github.com/user-attachments/assets/26b66895-a4eb-4b2d-a457-fc156aaac0bc" />

![image](https://github.com/user-attachments/assets/60e22c8a-bd46-43ee-820d-4f76c3db4855)

Issues:
- Female header pins were incorrectly spaced for ESP32 (didn't cause an issue completely, but needed to be fixed)
- With the current buck converter design, the door cannot be "buzzed" for a long time, leading to people missing their chance to open the door
