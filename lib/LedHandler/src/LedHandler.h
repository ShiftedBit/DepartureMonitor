#include <Arduino.h>

namespace LedHandler {
    extern bool ledState;

    void initLedHandler();
    void toggleLed();
}