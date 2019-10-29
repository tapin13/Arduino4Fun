#define IN_PIN A5

int sensorValue = 0;

void setup() {
  Serial.begin(9600);
    pinMode(IN_PIN, INPUT);
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    sensorValue = analogRead(IN_PIN);
    Serial.print("Sensor: ");
    Serial.println(sensorValue);

    if(sensorValue > 1000) {
        digitalWrite(LED_BUILTIN, HIGH);
    } else {
        digitalWrite(LED_BUILTIN, LOW);
    }
    
    delay(500);
}
