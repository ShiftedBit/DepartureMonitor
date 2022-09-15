#include <Arduino.h>
#include <WebSocket.h>
#include <TemperatureSensor.h>

void setup() {
  Serial.begin(115200);
  setupWifiManager();
  setupWebServer();
  setUpWebSocket();
  TemperatureSensor::initTemperatureSensor();
}

void loop() {
  
}