#include <TFT_eSPI.h>

TFT_eSPI tft;

Void setup(){
    tft.setRotation(3);
    tft.setTextColor(TFT_RED,TFT_BLACK);
    tft.setTextSize(2);
    tft.drawString("DHT",80,20);
    tft.drawString("HEARTRATE",80,100);
    tft.setTextColor(TFT_WHITE,TFT_BLACK);
}

Void loop(){
    
}