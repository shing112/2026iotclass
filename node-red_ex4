#define LED D4
void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  if (Serial.available()) {
    char data = Serial.read();
    if (data == '1') {
      digitalWrite(LED, HIGH);
    }
    else if (data =='0') {
      digitalWrite(LED, LOW);
    }
  }
}
