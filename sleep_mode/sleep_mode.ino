#include <avr/sleep.h>

#define INTERRUPT_PIN 2

void setup() {
    Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(INTERRUPT_PIN, INPUT_PULLUP);
}

void loop() {
    digitalWrite(LED_BUILTIN, LOW);
    delay(3000);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(3000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(3000);

    blinkBeforeSleep();

    Serial.println("Going Sleep...");
    delay(1000);

    
    goSleep();
}

void goSleep() {
    sleep_enable();

    attachInterrupt(0, wakeUp, LOW);

    
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);

    delay(1000);

    sleep_cpu();
}

void wakeUp() {
    sleep_disable();

    Serial.println("Wake Up");
    
    detachInterrupt(0);
}

void blinkBeforeSleep() {
    byte i = 0;
    bool ledStatus = 0;
    
    for(i = 0; i < 6; i++) {
        ledStatus = !ledStatus;
        digitalWrite(LED_BUILTIN, ledStatus);
        delay(500);
    }
}

