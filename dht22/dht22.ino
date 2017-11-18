#include "DHT.h"

#define DHT_PIN 2
#define DHT_READ_DELAY 2000

DHT dht(DHT_PIN, DHT22);

unsigned long lastDHTRead;
float temperature;
int humidity;

void setup() {
  Serial.begin(9600);
  dht.begin();

  lastDHTRead = millis();
}

void loop() {

  if(millis() - lastDHTRead < DHT_READ_DELAY) {
    return;
  } else {
    lastDHTRead = millis();
    readDHT();
  }
}

void readDHT() {
  float temperatureTmp = dht.readTemperature();
  int humidityTmp = (int)dht.readHumidity();

  if(isnan(temperatureTmp) || isnan(humidityTmp)) {
    Serial.println("Can not read data from sensor.");
    return;
  }

  if(temperatureTmp == temperature || humidityTmp == humidity) {
    return;
  }

  humidity = humidityTmp;
  temperature = temperatureTmp;

  Serial.println((String)"temperature: \t" + temperature + "C");
  Serial.println((String)"humidity: \t" + humidity + "%");
  Serial.println("~~~~~~~~~~~~~~~~~~~~~~");
}

