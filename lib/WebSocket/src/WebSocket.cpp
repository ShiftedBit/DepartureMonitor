#include <WebServer.h>
#include <WebSocket.h>
#include <Helpers.h>

using namespace WebSocket;

AsyncWebSocket WebSocket::ws("/ws");

void WebSocket::notifyClients(String data) {
    Serial.println("Notify clients: " + data);
    ws.textAll(data);
}

void WebSocket::processMessage(String message) {
  
}

void WebSocket::handleWebSocketMessage(void *arg, uint8_t *data, size_t len) {
  AwsFrameInfo *info = (AwsFrameInfo*)arg;
  
  if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT) {
    data[len] = 0;

    Serial.println("Message " + String((char*)data));
    processMessage(String((char*)data));
  }
}

void WebSocket::onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type,
             void *arg, uint8_t *data, size_t len) {
    switch (type) {
      case WS_EVT_CONNECT:
        Serial.printf("WebSocket client #%u connected from %s\n", client->id(), client->remoteIP().toString().c_str());
        break;
      case WS_EVT_DISCONNECT:
        Serial.printf("WebSocket client #%u disconnected\n", client->id());
        break;
      case WS_EVT_DATA:
        handleWebSocketMessage(arg, data, len);
        break;
      case WS_EVT_PONG:
      case WS_EVT_ERROR:
        break;
  }
}

void WebSocket::setUpWebSocket() {
  ws.onEvent(onEvent);
  server.addHandler(&ws);
}