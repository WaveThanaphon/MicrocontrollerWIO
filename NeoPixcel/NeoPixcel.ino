#include <Adafruit_NeoPixel.h>
#define PIN            0 // กำหนดขาที่ต่อกับ NeoPixel
#define NUMPIXELS      12 // กำหนดจำนวน LED ที่ต่อกับ NeoPixel
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800); // สร้างอ็อบเจ็ค pixels
void setup() 
{
  pixels.begin(); // สั่งให้เริ่มต้นการทำงาน
  pixels.setBrightness(10); // สั่งให้ความสว่างเป็น 10%
}
void loop() 
{
   unsigned long previousMillis = 0;
   const long interval = 1000;
   int colorIndex = 0;
   uint32_t colors[] = {pixels.Color(255, 0, 0), pixels.Color(0, 255, 0), pixels.Color(0, 0, 255)};

   while (true) {
      unsigned long currentMillis = millis();

      if (currentMillis - previousMillis >= interval) {
         previousMillis = currentMillis;

         for (int i = 0; i < NUMPIXELS; i++) {
            pixels.setPixelColor(i, colors[colorIndex]);
         }
         pixels.show();

         colorIndex++;
         if (colorIndex >= 3) {
            colorIndex = 0;
         }
      }
   }
}