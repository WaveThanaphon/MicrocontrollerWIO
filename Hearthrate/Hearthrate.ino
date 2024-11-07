#include <TFT_eSPI.h>  // Include the graphics library (this includes the sprite functions)
#include <Wire.h>
#include "DFRobot_MAX30102.h"

TFT_eSPI tft = TFT_eSPI();  // Create object "tft"
DFRobot_MAX30102 sensor;

void setup() {
    tft.init();
    tft.setRotation(1);
    tft.fillScreen(TFT_BLACK);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setTextSize(2);

    Wire.begin();
    sensor.begin();
    sensor.sensorStartCollect();
}

void loop() {
    if (sensor.available()) {
        uint32_t irValue = sensor.getIR();
        if (irValue > 50000) {  // Check if a finger is placed on the sensor
            int heartRate = sensor.getHeartRate();
            tft.fillScreen(TFT_BLACK);
            tft.setCursor(10, 10);
            tft.print("Heart Rate: ");
            tft.print(heartRate);
            tft.print(" BPM");
        } else {
            tft.fillScreen(TFT_BLACK);
            tft.setCursor(10, 10);
            tft.print("No finger detected");
        }
    }

    delay(1000);  // Update every second
}