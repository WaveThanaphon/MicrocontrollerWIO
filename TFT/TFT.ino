#include <TFT_eSPI.h>

TFT_eSPI tft;

void setup(){
    tft.begin();
    tft.setRotation(3);
    tft.fillScreen(TFT_BLACK);
    tft.setTextColor(TFT_RED,TFT_BLACK);
    tft.setTextSize(2);
    tft.drawString("DHT",80,20);
    tft.drawString("HEARTRATE",80,100);
    tft.setTextColor(TFT_WHITE,TFT_BLACK);
}

void loop(){

}