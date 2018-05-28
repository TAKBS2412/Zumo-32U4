/* This is a test program for reading values from the proximity sensors and detecting collisions. */

#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4LCD lcd;
Zumo32U4ButtonA buttonA;

Zumo32U4ProximitySensors proxSensors;

void setup() {
  proxSensors.initThreeSensors();

  lcd.clear();
  lcd.println("Press A");

  buttonA.waitForButton();

  lcd.clear();

  Serial.begin(9600);
}

void loop() {
  proxSensors.read();

  static char buffer[80];
  sprintf(buffer, "%d %d %d %d %d %d\n",
    proxSensors.countsLeftWithLeftLeds(),
    proxSensors.countsLeftWithRightLeds(),
    proxSensors.countsFrontWithLeftLeds(),
    proxSensors.countsFrontWithRightLeds(),
    proxSensors.countsRightWithLeftLeds(),
    proxSensors.countsRightWithRightLeds()
  );
  Serial.print(buffer);
}
