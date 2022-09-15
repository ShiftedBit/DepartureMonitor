#include <Arduino.h>
#include <WebSocket.h>

void setup() {
  Serial.begin(115200);
  setupWifiManager();
  setupWebServer();
  setUpWebSocket();
} 

void loop() {
}