#include <ESP8266WiFi.h>
#define LED_PIN D10
#define BUTTON_PIN D4
#define PORT 3
const char* ssid = "senWiFi_Free_2.4G_AP43";
const char* password = "123456789a";
WiFiClient client;
WiFiServer server(PORT);
int prevBtn = 0; int currBtn = 0;
void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(200);
  }
  Serial.println("");
  Serial.println(WiFi.localIP());
  delay(200);
  server.begin();
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  while (!client.connected()) {
    client = server.available();
  }
  currBtn = digitalRead(BUTTON_PIN);
  if (currBtn != prevBtn) {
    prevBtn = currBtn;
    if(currBtn == 1) {
      Serial.println("button_on");
      client.println("button_on");
    }
    if(currBtn == 0) {
      Serial.println("button_off");
      client.println("button_off");
    }
  }
  if (client.connected()) {
    if (client.available()) {
      String strData = client.readStringUntil('\n');
      if(strData.indexOf("led_on") != -1) {
        Serial.println("OK, turn on the LED");
        digitalWrite(LED_PIN, HIGH);
      }
      else if(strData.indexOf("led_off") != -1) {
        Serial.println("OK, turn off the LED");
        digitalWrite(LED_PIN, LOW);
      }
    }
  }
}
