#include <DFRobot_MAX30102.h>
DFRobot_MAX30102 particleSensor;
void setup()
{
    Serial.begin(115200);
  while (!particleSensor.begin()) {
    //tft.drawString("MAX30102 Fail!.", 50, 120);
    delay(1000);
  }
   particleSensor.sensorConfiguration(/*ledBrightness=*/60, /*sampleAverage=*/SAMPLEAVG_4, \
                        /*ledMode=*/MODE_MULTILED, /*sampleRate=*/SAMPLERATE_100, \
                        /*pulseWidth=*/PULSEWIDTH_411, /*adcRange=*/ADCRANGE_16384);
}

int32_t SPO2; //SPO2
int8_t SPO2Valid; //Flag to display if SPO2 calculation is valid
int32_t heartRate; //Heart-rate
int8_t heartRateValid; //Flag to display if heart-rate calculation is valid 

void loop()
{
  Serial.print("heartRateValid: ");
  Serial.println(heartRateValid);
  Serial.print("HeartRate: ");
  Serial.println(heartRate);
  Serial.print("SPO2Valid: ");
  Serial.println(SPO2Valid);
  Serial.print("SPO2: ");
  Serial.println(SPO2);
  delay(200);

  // tft.drawString("HeartRate: "+String(heartRate)+String("      "), 50, 150);
  // tft.drawString("SPO2Valid: "+String(SPO2Valid), 50, 180);
  // tft.drawString("SPO2: "+String(SPO2)+String("      "), 50, 210);
}