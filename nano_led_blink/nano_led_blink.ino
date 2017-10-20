#define BOARD_LED 13

void setup() {
  pinMode(BOARD_LED, OUTPUT);
}

void loop() {
  digitalWrite(BOARD_LED, HIGH);
  delay(1000);
  digitalWrite(BOARD_LED, LOW);
  delay(500);
}
