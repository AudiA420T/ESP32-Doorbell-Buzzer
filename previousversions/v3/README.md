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

![image](https://github.com/user-attachments/assets/60e22c8a-bd46-43ee-820d-4f76c3db4855)

![image](https://github.com/user-attachments/assets/04587388-e9cd-473e-b699-7f0da59775b4)

![image](https://github.com/user-attachments/assets/cf17f2ba-4e5b-45bb-80f2-6a703f44449e)

Issues:
- Female header pins were incorrectly spaced for ESP32 (didn't cause an issue completely, but needed to be fixed)
- With the current buck converter design, the door cannot be "buzzed" for a long time, leading to people missing their chance to open the door