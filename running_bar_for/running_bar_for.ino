#define FIRST_LED_PIN 2
#define LAST_LED_PIN 6
#define LEDS (LAST_LED_PIN - FIRST_LED_PIN + 1)
#define DELAY 1000

byte currentPin = FIRST_LED_PIN;

void setup() {
  for(int pin = FIRST_LED_PIN; pin <= LAST_LED_PIN; pin++) {
    pinMode(pin, OUTPUT);
  }
  Serial.begin(9600);

  digitalWrite(currentPin, HIGH);
}

void loop() {

  for(byte pin = FIRST_LED_PIN; pin <= LAST_LED_PIN; pin++) {
    digitalWrite(currentPin, LOW);
    digitalWrite(pin, HIGH);
    delay(1000);
    currentPin = pin;
  }
}
