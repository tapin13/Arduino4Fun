#define READER A0
#define MAX_ANALOG_PIN_VALUE 1023
#define MAX_ANALOG_PIN_VOLT 5
#define CONVERT_TO_VOLT MAX_ANALOG_PIN_VOLT / MAX_ANALOG_PIN_VALUE
#define TIMEOUT 1000

unsigned long timer;

void setup() {
  Serial.begin(9600);
  pinMode(READER, INPUT);
}

void loop() {
  if(millis() - timer > TIMEOUT) {
    timer = millis();
    Serial.println("~~~~~~~~~~~~~~~~");
    int reader_raw_val = analogRead(READER);
    Serial.print("reader_raw_val: ");
    Serial.println(reader_raw_val);
    Serial.print("Volts: ");
    Serial.println(reader_raw_val * CONVERT_TO_VOLT);
  }
}
