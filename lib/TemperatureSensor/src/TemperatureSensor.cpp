#include <TemperatureSensor.h>

using namespace TemperatureSensor;

#define DHTPIN 4
#define DHTTYPE DHT22

DHT TemperatureSensor::dht(DHTPIN, DHTTYPE);

float TemperatureSensor::readSensor() {
    return dht.readTemperature();
}

void TemperatureSensor::initTemperatureSensor() {
    dht.begin();
    Serial.println(readSensor());
}