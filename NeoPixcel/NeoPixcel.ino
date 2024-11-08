#include <Adafruit_NeoPixel.h>
#define PIN 2                                                                        // กำหนดขาที่ต่อกับ NeoPixel
#define NUMPIXELS 12                                                                 // กำหนดจำนวน LED ที่ต่อกับ NeoPixel
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);  // สร้างอ็อบเจ็ค pixels
void setup() {
  pixels.begin();            // สั่งให้เริ่มต้นการทำงาน
  pixels.setBrightness(10);  // สั่งให้ความสว่างเป็น 10%
}

int currentColor = 0;

void loop() {
  for (int i = 0; i < NUMPIXELS; i++) {
    if (currentColor == 0) {
      pixels.setPixelColor(i, pixels.Color(255, 0, 0));  // Red
    } else if (currentColor == 1) {
      pixels.setPixelColor(i, pixels.Color(0, 255, 0));  // Green
    } else if (currentColor == 2) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 255));  // Blue
    }
  }
  pixels.show();
  delay(1000);
  currentColor++;
  if (currentColor > 2) {
    currentColor = 0;
  }
}