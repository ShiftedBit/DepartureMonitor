#include <WebServer.h>

AsyncWebServer server(80);
DNSServer dns;

String processor(const String& var) {
  return String();
}

void setupWebServer() {

  // Initialize LittleFS
    if(!LittleFS.begin()){
        Serial.println("Error on LittleFS begin");
        return; 
    }

  server.serveStatic("/", LittleFS, "/").setDefaultFile("index.html");

  server.on("/api", HTTP_GET, [](AsyncWebServerRequest *request) { 
    request->send(200, "text/javascript", "Hurray");
  });

  server.begin();
}

void setupWifiManager() {
  AsyncWiFiManager wifiManager(&server, &dns);  
  Serial.println("Setup called");
  wifiManager.autoConnect("DepartureMonitor");
}