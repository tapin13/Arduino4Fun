#define BUTTON_PIN 3
#define LED_PIN 2
#define FLASHE_TIME 1000 // Timeout for On - Off LED
#define LED_FLASHES 3 // Total flashes after button pressed

boolean ledLight; // Button pressed, lets flash our LED
unsigned long timer; // save current millis
int timeout; // difference between current and saves millis 
byte i = 1; // counter

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  //Serial.begin(9600); // uncomment all lines start with Serial, to see logs in Serial Monitor
  
  ledLight = false;
}

void loop() {
  boolean buttonPressed = digitalRead(BUTTON_PIN);
  
  if(buttonPressed == 1 && ledLight == false) {
    //Serial.println("~~~PRESS~~~~~~");
    ledLight = true;
    i = 1;
    timer = millis();
  }

  if(ledLight == true) {
    timeout = millis() - timer;
    
    if(timeout > FLASHE_TIME * i && timeout < FLASHE_TIME * 2 * i && i % 2 != 0) {
      //Serial.println("on");
      //Serial.println(timeout);
      //Serial.println(i);
      digitalWrite(LED_PIN, HIGH);
      i += 1;
    } else if(timeout > FLASHE_TIME * i) {
      //Serial.println("off");
      //Serial.println(timeout);
      //Serial.println(i);
      digitalWrite(LED_PIN, LOW);
      i += 1;
    }

    if(i > LED_FLASHES * 2) {
      ledLight = false;
    }

  }
}
