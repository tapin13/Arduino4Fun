unsigned long last_time;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if(millis() - last_time > 1000) {
    last_time = millis();
    Serial.print("go: ");
    Serial.println(millis());
  }
}
