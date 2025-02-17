The problem to solve was that my building has traditionally very old doorbell buzzer systems and porch pirates looking for packages to steal. I needed a way to let me know someone was at the door, and let them in even if I wasn't home.

Features:
- Sending a push message when someone buzzes.
- Allowing you to buzz your door to let that person in.

Changes Made since previous version:
- Fixed spacing on ESP32 female headers
- Added 1F supercapacitor to allow for a longer buzz time
- Added 3.3v power supply to allow for smaller ESP32 modules in the future

Main Components:
1. ESP32 Module
2. Custom PCB with Buck Converter & Relay
4. Blynk Integration for Push Messages / App to trigger the relay

![image](https://github.com/user-attachments/assets/2d752281-bab6-4a0b-bc4d-2e79107c1a4b)

![image](https://github.com/user-attachments/assets/60e22c8a-bd46-43ee-820d-4f76c3db4855)

![image](https://github.com/user-attachments/assets/04587388-e9cd-473e-b699-7f0da59775b4)

![image](https://github.com/user-attachments/assets/cf17f2ba-4e5b-45bb-80f2-6a703f44449e)

![image](https://github.com/user-attachments/assets/6f256b64-f1e1-4c13-b102-c8b284c9dc0b)

Issues:
- C2 Footprint incorrect
- C2 circuit not correct. Needs to connect back to 5v net
- L2 is 68µH not 680µH. Need to correct labels
- Add resistor to the base of the transistor
- Fix nets and labels

Potential Improvements:
- Adding another LED for relay activation
- Use better buck converter. Current LM2596S is at limit
