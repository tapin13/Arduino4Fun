/*
 * Got task from http://wiki.amperka.ru/%D0%BA%D0%BE%D0%BD%D1%81%D0%BF%D0%B5%D0%BA%D1%82-arduino:%D0%BC%D0%B0%D1%8F%D1%87%D0%BE%D0%BA-%D1%81-%D0%BD%D0%B0%D1%80%D0%B0%D1%81%D1%82%D0%B0%D1%8E%D1%89%D0%B5%D0%B9-%D1%8F%D1%80%D0%BA%D0%BE%D1%81%D1%82%D1%8C%D1%8E
*/

#define LED_PIN 9
#define HIGH_LED_LIGHT 255
#define LOW_LED_LIGHT HIGH_LED_LIGHT * 1 / 3
#define MEDIUM_LED_LIGHT HIGH_LED_LIGHT * 2 / 3
#define STEP_DELAY 250

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  analogWrite(LED_PIN, LOW_LED_LIGHT);
  delay(STEP_DELAY);

  analogWrite(LED_PIN, MEDIUM_LED_LIGHT);
  delay(STEP_DELAY);

  analogWrite(LED_PIN, HIGH_LED_LIGHT);
  delay(STEP_DELAY);
}
