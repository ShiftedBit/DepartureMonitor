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

  // server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) { 
  //   request->send(LittleFS, "/index.html", "text/html");
  // });

  // server.on("/main.69fdad11ff0222ed.js", HTTP_GET, [](AsyncWebServerRequest *request) { 
  //   request->send(LittleFS, "/main.69fdad11ff0222ed.js", "text/javascript");
  // });

  // server.on("/polyfills.031eeff310a74e26.js", HTTP_GET, [](AsyncWebServerRequest *request) { 
  //   request->send(LittleFS, "/polyfills.031eeff310a74e26.js", "text/javascript");
  // });

  // server.on("/runtime.63972edfff3e0bb5.js", HTTP_GET, [](AsyncWebServerRequest *request) { 
  //   request->send(LittleFS, "/runtime.63972edfff3e0bb5.js", "text/javascript");
  // });

  // server.on("/styles.ef46db3751d8e999.css", HTTP_GET, [](AsyncWebServerRequest *request) { 
  //   request->send(LittleFS, "/styles.ef46db3751d8e999.css", "text/css");
  // });

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