/*
 * Got task from http://wiki.amperka.ru/%D0%BA%D0%BE%D0%BD%D1%81%D0%BF%D0%B5%D0%BA%D1%82-arduino:%D0%BC%D0%B0%D1%8F%D1%87%D0%BE%D0%BA-%D1%81-%D0%BD%D0%B0%D1%80%D0%B0%D1%81%D1%82%D0%B0%D1%8E%D1%89%D0%B5%D0%B9-%D1%8F%D1%80%D0%BA%D0%BE%D1%81%D1%82%D1%8C%D1%8E
*/

#define LED_1_PIN 3
#define LED_2_PIN 9
#define HIGH_LED_LIGHT 255
#define STEPS 5
#define STEP_LIGHT HIGH_LED_LIGHT / STEPS
#define STEPS_TIME 2000
#define STEP_DELAY STEPS_TIME / STEPS

byte step = 1;
byte up = 1;
unsigned long last_time = millis();

void setup() {
  pinMode(LED_1_PIN, OUTPUT);
  pinMode(LED_2_PIN, OUTPUT);
  //Serial.begin(9600);
}

void loop() {
  byte led_1_light, led_2_light;
  
  if(millis() - last_time > STEP_DELAY) {
    last_time = millis();
    
    step += up;
    
    if(step >= STEPS || step <= 0) {
      up *= -1;
      //Serial.println("----------------");
    }

    if(step == 0) {
      led_1_light = 0;
      led_2_light = HIGH_LED_LIGHT;
    } else if(step == STEPS) {
      led_1_light = HIGH_LED_LIGHT;
      led_2_light = 0;
    } else {
      led_1_light = STEP_LIGHT * step;
      led_2_light = STEP_LIGHT * (STEPS - step);
    }

    analogWrite(LED_1_PIN, led_1_light);
    analogWrite(LED_2_PIN, led_2_light);

    /*
    Serial.print("step: ");
    Serial.print(step);

    Serial.print(" led1: ");
    Serial.print(led_1_light);
    
    Serial.print(" led2: ");
    Serial.println(led_2_light);
    */
  }
}
