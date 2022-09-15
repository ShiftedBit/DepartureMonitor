#include <Arduino.h>
#include <WebServer.h>

extern AsyncWebSocket ws;

void notifyClients();
void handleWebSocketMessage(void *arg, uint8_t *data, size_t len);

void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type,
            void *arg, uint8_t *data, size_t len);

void setUpWebSocket();


