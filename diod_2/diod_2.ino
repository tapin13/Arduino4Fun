#define DELAY_SHORT 300
#define DELAY_LONG 600
#define DELAY_NEXT_STEP 1000

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);
  delay(DELAY_SHORT);
  digitalWrite(13, LOW);
  delay(DELAY_SHORT);
  digitalWrite(13, HIGH);
  delay(DELAY_SHORT);
  digitalWrite(13, LOW);
  delay(DELAY_SHORT);
  digitalWrite(13, HIGH);
  delay(DELAY_SHORT);
  digitalWrite(13, LOW);
  
//

  delay(DELAY_LONG);
  digitalWrite(13, HIGH);
  delay(DELAY_LONG);
  digitalWrite(13, LOW);
  delay(DELAY_LONG);
  digitalWrite(13, HIGH);
  delay(DELAY_LONG);
  digitalWrite(13, LOW);
  delay(DELAY_LONG);
  digitalWrite(13, HIGH);
  delay(DELAY_LONG);
  digitalWrite(13, LOW);

//
  delay(DELAY_SHORT);
  digitalWrite(13, HIGH);
  delay(DELAY_SHORT);
  digitalWrite(13, LOW);
  delay(DELAY_SHORT);
  digitalWrite(13, HIGH);
  delay(DELAY_SHORT);
  digitalWrite(13, LOW);
  delay(DELAY_SHORT);
  digitalWrite(13, HIGH);
  delay(DELAY_SHORT);
  digitalWrite(13, LOW);

  delay(DELAY_NEXT_STEP);

}
