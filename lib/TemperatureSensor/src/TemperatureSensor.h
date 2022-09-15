#include <Adafruit_Sensor.h>
#include <DHT.h>

namespace TemperatureSensor {

    extern DHT dht;

    float readSensor();
    void initTemperatureSensor();

}
