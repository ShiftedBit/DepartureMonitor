#include <Arduino.h>
#include <WebServer.h>

namespace WebSocket {

    extern AsyncWebSocket ws;

    void notifyClients(String data);
    void processMessage(String message);
    void handleWebSocketMessage(void *arg, uint8_t *data, size_t len);

    void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type,
                void *arg, uint8_t *data, size_t len);

    void setUpWebSocket();

}