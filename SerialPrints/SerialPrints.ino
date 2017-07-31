void setup() {
  Serial.begin(9600);
  Serial.println("Hello Arduino");
}

void loop() {
  int in_data;
  
  if(Serial.available() > 0) {
    in_data = Serial.read() - '0';
    //Serial.println(in_data);

    if(in_data == 1) {
      Serial.println("Part 1");
    } else if(in_data == 2) {
      Serial.println("Part 2");
    } else if(in_data == 3) {
      Serial.println("Part 3");
    } else {
      Serial.println("Menu");
    }
  }
}
