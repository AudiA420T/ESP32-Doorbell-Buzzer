/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "BLYNK_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "BLYNK_TEMPLATE_NAME"
#define BLYNK_AUTH_TOKEN "BLYNK_AUTH_TOKEN"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "YourNetworkName";
char pass[] = "YourNetworkPassword";

BlynkTimer uptimeTimer;
BlynkTimer buzzerCheckTimer;
BlynkTimer wifiCheckTimer;

const int inputPin = 12;
int acValue = digitalRead(inputPin);
int relaycontroltime = 500;

// This function is called every time someone buzzes
BLYNK_WRITE(V6)
{

  Serial.println("Button is pressed.");
  // We allow 1 notification per 5 seconds for now.
  Blynk.logEvent("button_toggled", "Someone buzzed the door");

  // Update state & LED
  digitalWrite(2,HIGH);  // Set digital pin 2 HIGH
  Blynk.virtualWrite(V6, 1);
  delay(5000);
  Blynk.virtualWrite(V6, 0);
  digitalWrite(2,LOW);  // Set digital pin 2 LOW
}

// This function is called every time somone triggers the relay remotely
BLYNK_WRITE(V7)
{
  digitalWrite(13, HIGH);
  digitalWrite(2,HIGH);  // Set digital pin 2 HIGH
  delay(relaycontroltime);
  digitalWrite(13, LOW);
  digitalWrite(2,LOW);  // Set digital pin 2 LOW
  delay(250);
  digitalWrite(13, HIGH);
  digitalWrite(2,HIGH);  // Set digital pin 2 HIGH
  delay(relaycontroltime);
  digitalWrite(13, LOW);
  digitalWrite(2,LOW);  // Set digital pin 2 LOW
}

// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
  //nothing happens here today...
}

// This function sends Arduino's uptime every second to Virtual Pin 2.
void uptimeEvent()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V2, millis() / 1000);
}

// This function checks for someone buzzing and sends a push notification
void buzzerCheckEvent()
{
  // Reading optocoupler value
  acValue = digitalRead(12);

  if(acValue == 0) {
    Serial.println("got a buzz, sending push");
    // We allow 1 notification per 5 seconds for now.
    Blynk.logEvent("button_toggled", "Someone buzzed the door");
    // Update state & LED
    digitalWrite(2,HIGH);  // Set digital pin 2 HIGH
    Blynk.virtualWrite(V6, 1);
    delay(5000);
    Blynk.virtualWrite(V6, 0);
    digitalWrite(2,LOW);  // Set digital pin 2 HIGH
  }
}

// This function checks if WiFi is connected, otherwise resets the ESP32
void wifiCheckEvent()
{
  // Checking WiFi status. If not connected, reset ESP32
  if(WiFi.status() != WL_CONNECTED) {
     ESP.restart();
  }
}

void setup()
{
  // Debug console
  Serial.begin(115200);

  // Initialise digital pin 2 as an output pin
  pinMode(2, OUTPUT);
  //setting up the relay
  pinMode(13,OUTPUT);
  //setting up the optocoupler
  pinMode(12, INPUT_PULLUP);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  // You can also specify server:
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, IPAddress(192,168,1,100), 8080);

  // First timer gets called every second for heartbeat
  uptimeTimer.setInterval(1000L, uptimeEvent);
  // Second timer gets called 10 times per second for incoming buzzes
  buzzerCheckTimer.setInterval(100L, buzzerCheckEvent);
  // First timer gets called every 10 minutes for WiFi check
  wifiCheckTimer.setInterval(600000L, wifiCheckEvent);
}

void loop()
{
  Blynk.run();
  uptimeTimer.run();
  buzzerCheckTimer.run();
  wifiCheckTimer.run();
}