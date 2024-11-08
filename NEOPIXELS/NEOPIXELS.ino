#include <Adafruit_NeoPixel.h>
#include <initializer_list>

#define PINPIXELS 2
#define NUMPIXELS 12

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PINPIXELS, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
  pixels.setBrightness(50);
  pixels.show();
  initializePixels();
}

void initializePixels() {
  // Initial pixel colors
  pixels.setPixelColor(5, pixels.Color(255, 0, 0));
  pixels.setPixelColor(6, pixels.Color(0, 255, 0));
  pixels.show();
}

void setTemperaturePixels(float temp) {
  pixels.clear();
  setPixels({ 6, 5 }, { pixels.Color(100, 255, 100), pixels.Color(255, 100, 100) });

  if (temp >= 31 && temp < 32) {
    setPixels({ 4 }, { pixels.Color(85, 255, 0) });
  } else if (temp >= 32 && temp < 33) {
    setPixels({ 4, 3 }, { pixels.Color(85, 255, 0), pixels.Color(166, 255, 0) });
  } else if (temp >= 33 && temp < 34) {
    setPixels({ 4, 3, 2 }, { pixels.Color(85, 255, 0), pixels.Color(166, 255, 0), pixels.Color(255, 255, 0, 0) });
  } else if (temp >= 34 && temp < 35) {
    setPixels({ 4, 3, 2, 1 }, { pixels.Color(85, 255, 0), pixels.Color(166, 255, 0), pixels.Color(255, 255, 0, 0), pixels.Color(255, 153, 0) });
  } else if (temp >= 35) {
    setPixels({ 4, 3, 2, 1, 0 }, { pixels.Color(85, 255, 0), pixels.Color(166, 255, 0), pixels.Color(255, 255, 0, 0), pixels.Color(255, 153, 0), pixels.Color(255, 0, 0) });
  } else if (temp >= 29 && temp < 30) {
    setPixels({ 7 }, { pixels.Color(0, 255, 213) });
  } else if (temp >= 28 && temp < 29) {
    setPixels({ 8, 7 }, { pixels.Color(0, 255, 247), pixels.Color(0, 255, 213) });
  } else if (temp >= 27 && temp < 28) {
    setPixels({ 9, 8, 7 }, { pixels.Color(0, 213, 255), pixels.Color(0, 255, 247), pixels.Color(0, 255, 213) });
  } else if (temp >= 26 && temp < 27) {
    setPixels({ 10, 9, 8, 7 }, { pixels.Color(0, 166, 255), pixels.Color(0, 213, 255), pixels.Color(0, 255, 247), pixels.Color(0, 255, 213) });
  } else {
    setPixels({ 11, 10, 9, 8, 7 }, { pixels.Color(0, 98, 255), pixels.Color(0, 166, 255), pixels.Color(0, 213, 255), pixels.Color(0, 255, 247), pixels.Color(0, 255, 213) });
  }

  pixels.show();
}

void setPixels(std::initializer_list<int> indices, std::initializer_list<uint32_t> colors) {
  auto color = colors.begin();
  for (int index : indices) {
    pixels.setPixelColor(index, *color++);
  }
}

void loop() {
  int randNum = random(24, 35);
  setTemperaturePixels(randNum);
  delay(500);
}
