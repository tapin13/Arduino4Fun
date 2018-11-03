#include <Wire.h>
#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

float temperature_ambient, temperature_object;

void setup() {
  Serial.begin(9600);
  mlx.begin();
}

void loop() {
  temperature_ambient = mlx.readAmbientTempC();
  Serial.print("Sensor temperature: ");
  Serial.println(temperature_ambient);

  temperature_object = mlx.readObjectTempC();
  Serial.print("Object temperature: ");
  Serial.println(temperature_object);

  Serial.println("------------------------------");
  
  delay(500);
}
