/* 
 * This is a test program that uses the robot's proximity sensors to help it follow a target. 
 * While the sample code in SumoProximitySensors only considers the speed the robot should travel or how much it should turn, this program considers both.
 */

#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4LCD lcd;
Zumo32U4ButtonA buttonA;
Zumo32U4Motors motors;

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

  uint8_t sum = proxSensors.countsFrontWithRightLeds() + proxSensors.countsFrontWithLeftLeds();
//  int8_t diff = proxSensors.countsFrontWithRightLeds() - proxSensors.countsFrontWithLeftLeds();

  int8_t diff = proxSensors.countsRightWithRightLeds() - proxSensors.countsLeftWithLeftLeds();
  
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

  /* Calculate the driving speed */

  /*
   * The variable sum should be the sum of the values from the robot's front proximity sensor.
   * The higher sum is, the closer the robot is to a target.
   * Usually, sum ranges from 4 (for no target) to 12 (the closest a target can be).
   * These values were determined via experimental data in a target-rich environment.
   * Therefore, the values may be slightly lower if the robot does not have as many targets surrounding it when you test this.
   */

  int leftSpeed; // How fast we want to drive on the left side.
  int rightSpeed; // How fast we want to drive on the right side.

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

  /* Calculate the turning speed */

  /*
   * The variable diff should be the difference between the values from the right proximity sensor and the left proximity sensor. 
   * The higher diff is, the more the robot should turn to the right, and the lower diff is, the more the robot should turn to the left.
   * If diff is zero, then the robot should not turn at all.
   * Usually, diff is between -2 and 2 (this is based off of experimental data). 
   */

  int turnSpeed = diff * 100; // How much we want to turn to the right (this value is added to leftSpeed and subtracted from rightSpeed).

  if (sum == 12)
  {
    // There's an object right in front of us, so we should ram it.
    lcd.clear();
    lcd.print("Ramming...");

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
