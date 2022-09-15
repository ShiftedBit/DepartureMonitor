#include <WebServer.h>
#include <WebSocket.h>
#include <Helpers.h>
#include <SocketEventHandler.h>

using namespace WebSocket;

AsyncWebSocket WebSocket::ws("/ws");

void WebSocket::notifyClients(String data) {
    Serial.println("Notify clients: " + data);
    ws.textAll(data);
}

void WebSocket::setUpWebSocket() {
  ws.onEvent(SocketEventHandler::onEvent);
  server.addHandler(&ws);
}