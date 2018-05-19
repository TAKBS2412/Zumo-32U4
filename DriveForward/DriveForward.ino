/* This example drives each motor on the Zumo forward, then
backward.  The yellow user LED is on when a motor should be
running forward and off when a motor should be running backward.
If a motor on your Zumo has been flipped, you can correct its
direction by uncommenting the call to flipLeftMotor() or
flipRightMotor() in the setup() function. */

/* DOCUMENTATION: pololu.com/docs/0J63/all 
                  http://pololu.github.io/zumo-32u4-arduino-library/
*/

#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA;

Zumo32U4LCD lcd;

Zumo32U4LineSensors lineSensors;

#define NUM_SENSORS 5
uint16_t lineSensorValues[NUM_SENSORS];

unsigned long time;
unsigned long startTime;

int speed = 300;

void setup()
{
  // Uncomment if necessary to correct motor directions:
  //motors.flipLeftMotor(true);
  //motors.flipRightMotor(true);

  /** INITIALIZE LINE SENSORS*/

  lineSensors.initFiveSensors(); //We initialize five sensors but in reality we only use 0, 2, and 4.

  // Tell the user to press button A.
  lcd.clear();
  lcd.print("Press A");

  // Wait for the user to press button A.
  buttonA.waitForButton();

  // Delay so that the robot does not move away while the user is
  // still touching it.
  delay(1000);
//  Serial.begin(9600);
  startTime = millis();
}

void loop()
{
  lcd.clear();

  // Read values from the sensors.
  lineSensors.read(lineSensorValues, QTR_EMITTERS_ON);

  lcd.print(lineSensorValues[2]);
  
  // Run both motors forward.
  ledYellow(1);
  time = millis() - startTime;
//  Serial.println(time);
  if(time < 0.5*1000) {
    speed = 300;
//    lcd.print("Driving");
  } else {
    speed = 0;
//    lcd.print("Stopped");
  }
  motors.setLeftSpeed(speed);
  motors.setRightSpeed(speed);
  delay(500);
}
