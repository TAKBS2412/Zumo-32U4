/* This is a test program for reading values from the proximity sensors and detecting collisions. */

#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4ProximitySensors proxSensors;

void setup() {
  proxSensors.initThreeSensors();
  Serial.begin(9600);
}

void loop() {
  proxSensors.read();
}
