boolean flag = 0;
boolean button = 0;
boolean led = 0;

unsigned long last_time = 0;

void setup() {
  pinMode(3, INPUT_PULLUP);
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  //Serial.println("zzzz");
  
  button = !digitalRead(3);

  if(button == 1 && flag == 0 && millis() - last_time > 50) {
    flag = 1;
    Serial.println("button press");
    led = !led;
    digitalWrite(13, led);
    last_time = millis();
  }

  if(button == 0 && flag == 1) {
    flag = 0;
    Serial.println("button released");
    //led = !led;
    //digitalWrite(13, led);
  }
  
}
