#define TRIG_PIN 9
#define ECHO_PIN 8
#define ARDUINO_LED 13

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(ARDUINO_LED, OUTPUT);
  Serial.begin(9600);
}

unsigned int impulseTime = 0;
unsigned int distance_cm = 0;

void loop() {
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  impulseTime = pulseIn(ECHO_PIN, HIGH);
  distance_cm = impulseTime / 58;

  Serial.println(distance_cm);

  if(distance_cm > 30) {
    digitalWrite(ARDUINO_LED, HIGH);
  } else {
    digitalWrite(ARDUINO_LED, LOW);
  }

  delay(100);
}
