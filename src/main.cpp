#include <Arduino.h>
#include <WebSocket.h>
#include <LedHandler.h>
#include <WebClient.h>

const unsigned long timeIntervall = 60*1000/2; // 15 minutes
unsigned long timeStamp = 0;

void executePeriodicTasks() {
  WebClient::fetchData("Test");
}

void setup() {
  Serial.begin(115200);
  setupWifiManager();
  setupWebServer();
  WebSocket::setUpWebSocket();
  LedHandler::initLedHandler();
}

void loop() {
  // Code in this section only runs every timeIntervall - rollover safe
  if(millis() - timeStamp > timeIntervall ){
    executePeriodicTasks();
    timeStamp = millis();  // reset the timer
   }
}