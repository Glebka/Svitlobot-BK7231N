#include <Arduino.h>
#include <WiFi.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>

#define SSID "SSID"
#define PASSWORD "PASSWORD"
#define SVITLOBOT_HOST "api.svitlobot.in.ua"
#define SVITLOBOT_PORT 80
#define SVITLOBOT_URI "/channelPing?channel_key="
#define SVITLOBOT_KEY "XXXXX"

WiFiMulti wifimulti;

__attribute__((weak)) String ipToString(const IPAddress &ip)
{
    char szRet[16];
    sprintf(szRet, "%hhu.%hhu.%hhu.%hhu", ip[0], ip[1], ip[2], ip[3]);
    return String(szRet);
}

void setup()
{
    Serial.begin(115200);

    Serial.println();
    Serial.println();
    Serial.println();

    Serial.println("Svitlobot BK7231N");

    WiFi.mode(WIFI_STA);
    wifimulti.addAP(SSID, PASSWORD);

    Serial.print("Waiting for WiFi to connect...");
    while ((wifimulti.run() != WL_CONNECTED))
    {
        Serial.print(".");
    }
    Serial.println(" connected");
}

void loop()
{
    Serial.println();
    Serial.println("Waiting 60s before the next ping...");
    delay(600000);
    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    if (http.begin(SVITLOBOT_HOST, SVITLOBOT_PORT, SVITLOBOT_URI SVITLOBOT_KEY))
    { // HTTPS
        Serial.print("[HTTP] GET " SVITLOBOT_API SVITLOBOT_KEY "\n");
        // start connection and send HTTP header
        int httpCode = http.GET();

        // httpCode will be negative on error
        if (httpCode > 0)
        {
            // HTTP header has been send and Server response header has been handled
            Serial.printf("[HTTP] GET... code: %d\n", httpCode);
        }
        else
        {
            Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
        }

        http.end();
    }
    else
    {
        Serial.printf("[HTTPS] Unable to connect\n");
    }

    // End extra scoping block
}