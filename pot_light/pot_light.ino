#define LED_PIN 9
#define POT_PIN A0

int old_rotation = 0;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(POT_PIN, INPUT);
  
  //Serial.begin(9600);
}

void loop() {
  int rotation, brightness;

  rotation = analogRead(POT_PIN);

  // round rotation
  rotation = (rotation/ 20) * 20;

  // make changed only if got new value
  if(old_rotation != rotation) {
    old_rotation = rotation;
    
    brightness = rotation / 4;
    
    analogWrite(LED_PIN, brightness);
    /*
    Serial.print("rotation: ");
    Serial.print(rotation);
    Serial.print(" brightness: ");
    Serial.println(brightness);
    */
  }
  
}
