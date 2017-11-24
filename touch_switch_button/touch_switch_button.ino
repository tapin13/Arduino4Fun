// TTP223 Capacitive Touch Switch Button

#define CTS_PIN 2
#define LED_PIN 13
#define CTS_DELAY 1000

unsigned long ctsTime;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(CTS_PIN, INPUT);

  ctsTime = millis();
}

void loop() {
  if(millis() - ctsTime < CTS_DELAY) {
    return;
  }

  ctsTime = millis();

  byte ctsValue = digitalRead(CTS_PIN);

  //Serial.println((String)"ctsValue: " + ctsValue);
  
  if(ctsValue == HIGH) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Touched");
  } else {
    digitalWrite(LED_PIN, LOW);
    Serial.println("Not touched");
  }
}
