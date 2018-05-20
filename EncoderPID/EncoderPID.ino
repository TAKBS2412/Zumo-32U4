/* This program drives each motor using PID control with the encoders as feedback. */

#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA;
Zumo32U4Encoders encoders;

Zumo32U4LCD lcd;

int distanceToDrive = 500; // The distance setpoint.

/* PID constants */
double kP = 0.4;
double kI = 0.0;
double kD = 0.0;

/* Integral windup term and error */
double errorSum = 0;
double error = 0;
double lastError = 0;

void setup() {
  // Wait for the user to press button A.
  lcd.clear();
  lcd.print("Press A");

  buttonA.waitForButton();
  
  // Delay so that the robot does not move away while the user is
  // still touching it.
  delay(1000);
}

void loop() {
  
}
