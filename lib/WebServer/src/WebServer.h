#include <ESPAsyncWiFiManager.h>  // WifiManager
#include <ESPAsyncWebServer.h>
#include <LittleFS.h>

extern AsyncWebServer server;
extern DNSServer dns;

void setupWebServer();
void setupWifiManager();