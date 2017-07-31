void setup() {
  pinMode(A5, INPUT_PULLUP);
  pinMode(13, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  boolean button1 = !digitalRead(A5);

  if(button1 == 1) {
    digitalWrite(13, 1);
  }
  digitalWrite(13, 0);

  Serial.print("Button1: ");
  Serial.print(button1);
  Serial.println();
}
