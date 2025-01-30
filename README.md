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

![IMG_2528](https://github.com/user-attachments/assets/70c68e16-c3e6-4513-86ce-83aca9fca62b)

![image](https://github.com/user-attachments/assets/60e22c8a-bd46-43ee-820d-4f76c3db4855)

![image](https://github.com/user-attachments/assets/04587388-e9cd-473e-b699-7f0da59775b4)

![image](https://github.com/user-attachments/assets/cf17f2ba-4e5b-45bb-80f2-6a703f44449e)

![image](https://github.com/user-attachments/assets/6f256b64-f1e1-4c13-b102-c8b284c9dc0b)

Issues:
- Footprint incorrect (found 01/01/24)
- L2 is 68µH not 680µH

Potential Improvements:
- Adding another LED for relay activation
