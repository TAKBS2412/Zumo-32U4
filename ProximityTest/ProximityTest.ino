/* This is a test program for reading values from the proximity sensors and detecting collisions. */

#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4LCD lcd;
Zumo32U4ButtonA buttonA;

Zumo32U4ProximitySensors proxSensors;
Zumo32U4Buzzer buzzer;

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

  uint8_t sum = proxSensors.countsFrontWithRightLeds() + proxSensors.countsFrontWithLeftLeds();
  int8_t diff = proxSensors.countsFrontWithRightLeds() - proxSensors.countsFrontWithLeftLeds();
  
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
  if (sum == 12)
  {
    // There's an object right in front of us, so we should ram it.
    lcd.clear();
    lcd.print("Ramming...");

    buzzer.playNote(NOTE_G(4), 2000, 15);
      
    delay(200);
    buzzer.stopPlaying();
  }
}
