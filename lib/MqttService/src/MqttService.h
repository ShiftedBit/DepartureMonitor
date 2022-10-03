#include <AsyncMqttClient.h>
#include <Ticker.h>

namespace MqttService {
    // Raspberry Pi Mosquitto MQTT Broker
    // #define MQTT_HOST IPAddress(192, 168, 1, XXX)
    // For a cloud MQTT broker, type the domain name
    #define MQTT_HOST "smarty.local"
    #define MQTT_PORT 1883

    // Temperature MQTT Topics
    #define MQTT_PUB_TEMP "esp/bme680/temperature"

    extern AsyncMqttClient mqttClient;
    extern Ticker mqttReconnectTimer;

    void connectToMqtt();
    void onMqttPublish(uint16_t packetId);
    void connectToMqtt();
    void onMqttConnect(bool sessionPresent);
    void onMqttDisconnect(AsyncMqttClientDisconnectReason reason);
    void publish(String message);
}