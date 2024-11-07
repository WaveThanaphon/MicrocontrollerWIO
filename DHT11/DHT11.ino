#include <DHT.h>
#include <TFT_eSPI.h>
#include <Wire.h>

#define DHTPIN 7     // Pin where the DHT11 is connected
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);
TFT_eSPI tft = TFT_eSPI();  // Create object "tft"

void setup() {
    // Initialize the WIO Terminal display
    tft.begin();
    tft.setRotation(3);
    tft.fillScreen(TFT_BLACK);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setTextSize(2);

    // Initialize the DHT sensor
    dht.begin();
}

void loop() {
    // Read temperature and humidity from DHT11
    float h = dht.readHumidity();
    float t = dht.readTemperature();

    // Check if any reads failed and exit early (to try again).
    if (isnan(h) || isnan(t)) {
        tft.fillScreen(TFT_BLACK);
        tft.setCursor(0, 0);
        tft.println("Failed to read from DHT sensor!");
        delay(2000);
        return;
    }

    // Clear the screen
    tft.fillScreen(TFT_BLACK);

    // Display temperature
    tft.setCursor(0, 0);
    tft.print("Temp: ");
    tft.print(t);
    tft.println(" *C");

    // Display humidity
    tft.setCursor(0, 30);
    tft.print("Humidity: ");
    tft.print(h);
    tft.println(" %");

    // Wait a few seconds between measurements.
    delay(2000);
}