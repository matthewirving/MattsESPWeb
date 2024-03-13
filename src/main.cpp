#include <Arduino.h>
#include <Wifi.h>
#include <WebServer.h>
#include "../credentials/info.h"

#define DELAY_FACTOR  (100)
#define NUM_OF_DIGITS (4)

#define WIFI_TIMEOUT_MS 20000
const char *password = WIFI_PASSWORD;
const char *network = WIFI_NETWORK;

void connectToWifi()
{
  Serial.print("Connecting to WiFi");
  WiFi.mode(WIFI_STA);
  WiFi.begin(network, password);

  unsigned long startAttemptTime = millis();

  while(WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < WIFI_TIMEOUT_MS)
  {
    Serial.print(".");
    delay(100);
  }

  if(WiFi.status() != WL_CONNECTED)
  {
    Serial.println("Failed!");
    // take action
  }
  else
  {
    Serial.print("Connected!");
    Serial.println(WiFi.localIP());

    
  }
}

void setup() {
  Serial.begin(115200);
  connectToWifi();
  
}

void loop() {
  // put your main code here, to run repeatedly:
}