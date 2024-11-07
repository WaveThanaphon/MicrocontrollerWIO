#include <TFT_eSPI.h>
#include "DHT.h"
#define DHTPIN 0
#define DHTTYPE DHT11
TFT_eSPI tft;
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  tft.begin();
  dht.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_RED, TFT_BLACK);
  tft.setTextSize(2);
  tft.drawString("DHT", 80, 20);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
}

void loop() {
  float humi = dht.readHumidity();
  float temp = dht.readTemperature();
  tft.drawString("Humi: " + String(humi) + String(" %    "), 80, 40);
  tft.drawString("Temp: " + String(temp) + String(" C    "), 80, 60);
  delay(200);
}
