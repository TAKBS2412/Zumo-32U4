/* This is a test program for reading values from the proximity sensors and detecting collisions. */

#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4LCD lcd;
Zumo32U4ButtonA buttonA;
Zumo32U4Motors motors;

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

  Serial.println(buffer);

  int leftSpeed;
  int rightSpeed;

  if (sum == 12) {
    // There's an object right in front of us, so we should drive towards it at maximum speed.
    leftSpeed = 400;
    rightSpeed = 400;
  } else if (sum >= 8) {
    // There's an object somewhat close to us, so we should drive forwards but not too fast.
    leftSpeed = 300;
    rightSpeed = 300;
  } else {
    // The signal isn't very strong, so just drive forward slowly.
    leftSpeed = 200;
    rightSpeed = 200;
  }
  
  if (sum == 12)
  {
    // There's an object right in front of us, so we should ram it.
    lcd.clear();
    lcd.print("Ramming...");

//    buzzer.playNote(NOTE_G(4), 2000, 15);
      
    delay(200);
    buzzer.stopPlaying();

    motors.setSpeeds(400, 400);
  }
  else if (diff > 0)
  {
    // There's an object to the right of us, so we should turn right.
    lcd.clear();
    lcd.print("Turning");
    lcd.gotoXY(0, 1);
    lcd.print("right...");

    motors.setSpeeds(200, 300);
  }
  else if (diff < 0)
  {
    // There's an object to the left of us, so we should turn left.
    lcd.clear();
    lcd.print("Turning");
    lcd.gotoXY(0, 1);
    lcd.print("left...");

    motors.setSpeeds(300, 200);
  }
  else if (diff == 0)
  {
    // There's an object in front of us, but the signal isn't as strong.
    lcd.clear();
    lcd.print("Driving");
    lcd.gotoXY(0, 1);
    lcd.print("forward");

    motors.setSpeeds(200, 200);
  }
}
