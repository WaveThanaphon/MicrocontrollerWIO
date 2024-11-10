#include <TFT_eSPI.h>
#include <DFRobot_MAX30102.h>
#include <Adafruit_NeoPixel.h>

#define PIN 2
#define NUMPIXELS 12

TFT_eSPI tft;
DFRobot_MAX30102 particleSensor;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_RED, TFT_BLACK);
  tft.setTextSize(2);
  tft.drawString("HEARTRATE", 80, 20);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  pixels.begin();
  pixels.setBrightness(50);

  Serial.begin(115200);
  while (!particleSensor.begin()) {
    tft.drawString("MAX30102 Fail!.", 50, 200);
    delay(1000);
  }
  particleSensor.sensorConfiguration(/*ledBrightness=*/60, /*sampleAverage=*/SAMPLEAVG_4,
                                     /*ledMode=*/MODE_MULTILED, /*sampleRate=*/SAMPLERATE_100,
                                     /*pulseWidth=*/PULSEWIDTH_411, /*adcRange=*/ADCRANGE_16384);
}

int32_t SPO2;       //SPO2
int8_t SPO2Valid;   //Flag to display if SPO2 calculation is valid
int32_t heartRate;  //Heart-rate
int8_t heartRateValid;

void loop() {
  particleSensor.heartrateAndOxygenSaturation(&SPO2, &SPO2Valid, &heartRate, &heartRateValid);
  tft.drawString("heartRateValid: " + String(heartRateValid) + String("      "), 80, 40);
  tft.drawString("HeartRate: " + String(heartRate) + String("      "), 80, 60);
  tft.drawString("SPO2Valid: " + String(SPO2Valid), 80, 80);
  tft.drawString("SPO2: " + String(SPO2) + String("      "), 80, 100);
  pixels.clear();

  for (int i = 0; i < NUMPIXELS; i++) {
    if (heartRate <= 0) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 255));
      pixels.show();
      delay(200);
    } else if (heartRate > 0 && heartRate <= 130) {
      pixels.setPixelColor(i, pixels.Color(0, 255, 0));  // Green
    } else if (heartRate > 130) {
      pixels.setPixelColor(i, pixels.Color(255, 0, 0));  // Blue
    }
  }
  pixels.show();
  delay(1000);
}
