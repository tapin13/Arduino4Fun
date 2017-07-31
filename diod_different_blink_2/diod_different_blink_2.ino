/*
 * Got task from http://wiki.amperka.ru/%D0%BA%D0%BE%D0%BD%D1%81%D0%BF%D0%B5%D0%BA%D1%82-arduino:%D0%BC%D0%B0%D1%8F%D1%87%D0%BE%D0%BA-%D1%81-%D0%BD%D0%B0%D1%80%D0%B0%D1%81%D1%82%D0%B0%D1%8E%D1%89%D0%B5%D0%B9-%D1%8F%D1%80%D0%BA%D0%BE%D1%81%D1%82%D1%8C%D1%8E
*/

#define LED_PIN 9
#define HIGH_LED_LIGHT 255
#define STEPS 5
#define STEPS_TIME 1000
#define STEP_DELAY STEPS_TIME / STEPS

byte step = 0;
unsigned long last_time = millis();

void setup() {
  pinMode(LED_PIN, OUTPUT);
  //Serial.begin(9600);
}

void loop() {
  if(millis() - last_time > STEP_DELAY) {
    last_time = millis();
    step++;
    if(step > STEPS) {
      step = 0;
    }
    if(step == 0) {
      analogWrite(LED_PIN, 0);
      //Serial.println(0);
    } else {
      analogWrite(LED_PIN, HIGH_LED_LIGHT / step);  
      //Serial.println(HIGH_LED_LIGHT / step);
    }
  }
}
