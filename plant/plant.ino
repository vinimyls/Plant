#include "Nextion.h"

#define SensorPin A0
int sensorValue = 0;
int printValue;
int maxValue = 90;
int minValue = 40;
/************************ Nextion components ****************/
//page 0
NexPage page0             = NexPage(0, 0, "page0"); //page0
NexPicture picture        = NexPicture(0, 1, "p0");    // picture

void setup() {
  Serial.begin(19200);
}
void loop() {
  sensorValue = analogRead(SensorPin);
  sensorValue = sensorValue/10;
  if(maxValue < sensorValue)
  {
    sensorValue = maxValue;
  }
  if(minValue > sensorValue)
  {
    sensorValue = minValue;
  }
  if(sensorValue>100)
  {
    sensorValue = 100;
  }
  printValue = (maxValue - sensorValue)*2;
  picture.setPic(printValue);
  delay(100);
}
