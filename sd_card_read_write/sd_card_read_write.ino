#include <SD.h>

#define CS_PIN 4 // Chip Select depends on your SD card shield or module. Pin 4 used here for consistency with other Arduino examples.
//MOSI - pin 11 on Arduino Uno
//MISO - pin 12 on Arduino Uno

File file;
char* file_name = "test.txt";
char file_text[255];

void setup() {
  Serial.begin(9600);

  Serial.print("Initialization SD card... ");
  if(!SD.begin(CS_PIN)) {
    Serial.println("failed.");
    return;
  }
  Serial.println("done.");

  SD.remove(file_name);

  Serial.print("Open file with write permissions... ");
  file = SD.open(file_name, FILE_WRITE);
  if(file) {
    Serial.println("OK");
    file.println("This text will be saved in file. 3.14...");
    file.close();
    Serial.println("Write done");
  } else {
    Serial.println("Error");
    return;
  }

  Serial.print("Open file with read permissions... ");
  file = SD.open(file_name, FILE_READ);
  if(file) {
    Serial.println("OK");
    Serial.println("File data:");
    while(file.available()) {
      char c = file.read();
      Serial.write(c);
    }
    file.close();
    Serial.println("Read done");
  } else {
    Serial.println("Error");
    return;
  }
}

void loop() {
}
