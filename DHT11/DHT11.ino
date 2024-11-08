#include "DHT.h"
#define DHTPIN 0
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  dht.begin();
  Serial.begin(115200);
}

void loop() {
  float humi = dht.readHumidity();
  float temp = dht.readTemperature();
  Serial.print("Humidity: ");
  Serial.print(humi);
  Serial.println(" %");
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" C");
  delay(200);
}
