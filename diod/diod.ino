unsigned long last_time = 0;

boolean led_on = 0;

void setup() {
  pinMode(13, OUTPUT);

}

void loop() {
  if(millis() - last_time > 2000) {
    if(led_on == 0) {
      digitalWrite(13, LOW);
    } else {
      digitalWrite(13, HIGH);
    }
    led_on = !led_on;
    last_time = millis();
  }
}

void short_up() {
  
}

