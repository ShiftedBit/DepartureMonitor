#include <WebClient.h>

ESP8266WiFiMulti WiFiMulti;
DynamicJsonDocument doc(1024);

void WebClient::fetchData(const char*) {
    if ((WiFiMulti.run() == WL_CONNECTED)) {

        std::unique_ptr<BearSSL::WiFiClientSecure> client(new BearSSL::WiFiClientSecure);
        client->setInsecure();

        HTTPClient https;

        // Serial.print("[HTTPS] begin...\n");
        if (https.begin(*client, "https://www.wienerlinien.at/ogd_realtime/monitor?activateTrafficInfo=stoerunglang&rbl=543")) {  // HTTPS

            // Serial.print("[HTTPS] GET...\n");
            // start connection and send HTTP header
            int httpCode = https.GET();

            // httpCode will be negative on error
            if (httpCode > 0) {
                // HTTP header has been send and Server response header has been handled
                // Serial.printf("[HTTPS] GET... code: %d\n", httpCode);

                // file found at server
                if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
                    String payload = https.getString();
                    // String payload = https.getString(1024);  // optionally pre-reserve string to avoid reallocations in chunk mode

                    deserializeJson(doc, payload);

                    const char* line = doc["data"]["monitors"][0]["lines"][0]["name"];
                    const char* station = doc["data"]["monitors"][0]["locationStop"]["properties"]["title"];
                    int departure = doc["data"]["monitors"][0]["lines"][0]["departures"]["departure"][0]["departureTime"]["countdown"];

                    std::string lineStr = line;
                    std::string stationStr = station;
                    std::string departureStr = std::to_string(departure);
                    std::string delimiterStr = " ";

                    std::string result = lineStr + delimiterStr + stationStr + delimiterStr + departureStr;

                    Serial.println(result.c_str());
                }
            } else {
                Serial.printf("[HTTPS] GET... failed, error: %s\n", https.errorToString(httpCode).c_str());
            }

            https.end();
        } else {
            Serial.printf("[HTTPS] Unable to connect\n");
        }

    }
}