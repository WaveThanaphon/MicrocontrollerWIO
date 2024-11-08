#include <Adafruit_NeoPixel.h>
#define PIN            BCM27
#define NUMPIXELS      12
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int delayval = 500; // delay for half a second
void setup() 
{
  pixels.begin(); // This initializes the NeoPixel library.
  pixels.setBrightness(10);
  pixels.show();
}
void loop() 
{
   for(int i=0;i<NUMPIXELS;i++)
   {
      pixels.setPixelColor(i, pixels.Color(255,0,0));   // Moderately bright green color.
      pixels.show();    // This sends the updated pixel color to the hardware.
   }
   delay(1000);  // Delay for a period of time (in milliseconds).

   for(int i=0;i<NUMPIXELS;i++)
   {
    pixels.setPixelColor(i, pixels.Color(0,255,0));   // Moderately bright green color.
    pixels.show();    // This sends the updated pixel color to the hardware.
   }
   delay(1000);  // Delay for a period of time (in milliseconds).
   
   for(int i=0;i<NUMPIXELS;i++)
   {
    pixels.setPixelColor(i, pixels.Color(0,0,255));   // Moderately bright green color.
    pixels.show();    // This sends the updated pixel color to the hardware.
   }
   delay(1000);  // Delay for a period of time (in milliseconds).
}
