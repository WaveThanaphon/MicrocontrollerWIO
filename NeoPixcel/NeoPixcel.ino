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
   // for(int i=0;i<NUMPIXELS;i++) // วนลูปเปลี่ยนสีของ LED
   // {
   //    pixels.setPixelColor(i, pixels.Color(255,0,0));   // แสดงสีแดง
   //    pixels.show();    // สั่งให้แสดงสีที่เลือก
   // }
   // delay(1000); 
   static unsigned long lastUpdate = 0;
   unsigned long currentMillis = millis();

   if (currentMillis - lastUpdate >= 1000) {
      for(int i=0;i<NUMPIXELS;i++) {
         pixels.setPixelColor(i, pixels.Color(0,255,0));   // แสดงสีเขียว
         pixels.show();    // สั่งให้แสดงสีที่เลือก
      }
      lastUpdate = currentMillis;
   }
}
