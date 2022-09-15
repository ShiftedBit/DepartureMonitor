#include <LedHandler.h>

using namespace LedHandler;

bool LedHandler::ledState = 0;

void LedHandler::initLedHandler() {
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);
}

void LedHandler::toggleLed() {
    Serial.println("Toggle led");
    digitalWrite(LED_BUILTIN, ledState);
    ledState = !ledState;
}