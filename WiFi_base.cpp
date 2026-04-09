#include <ESP8266WiFi.h>

const char* ssid = "senWiFi_Free_2.4G_AP43";
const char* password = "123456789a";

#define PORT 10

WiFiClient client;
WiFiServer server(PORT);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  Serial.println("Connecting to Wi-Fi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print();
  }

  Serial.println("\nConnected to Wi-Fi!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("WiFi is still connected.");
  }
  else {
    Serial.println("WiFi disconnected!");
  }
  delay(3000);
