/* This program turns the robot to a specified angle using PID control with gyros as feedback */

#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA;
L3G gyro;

Zumo32U4LCD lcd;

int16_t angleToTurn = 90; // The angle setpoint.

/* PID constants */
double kP = 1.5;
double kI = 0.0;
double kD = 0.0;

/* Integral windup term and error */
double errorSum = 0;
double error = 0;
double lastError = 0;

int counter = 0;

bool turningDone = false;

void setup() {
  // Wait for the user to press button A.
  lcd.clear();
  lcd.print("Press A");
  
  buttonA.waitForButton();
  
  // Delay so that the robot does not move away while the user is
  // still touching it.
  delay(1000);

  Serial.begin(9600);
}

void loop() {
  if(!turningDone) {
    int16_t angle = /*somehow get the angle*/;
  
    error = angleToTurn - angle;
    errorSum += error;
    if(abs(errorSum) > 1000) errorSum = 0;
  
    double speed = kP * error + kI * errorSum + kD * (error - lastError);
  
    if(counter % 30 == 0) {
      lcd.clear();
      lcd.print(angle);
    }
    
    motors.setLeftSpeed(speed);
    motors.setRightSpeed(-speed);
    
    lastError = error;
  
    counter++;

    if(abs(error) < 10) {
      turningDone = true;
      lcd.clear();
    }
  } else {
    motors.setLeftSpeed(0);
    motors.setRightSpeed(0);
    lcd.print("Done");
    lcd.gotoXY(0, 1);
    lcd.print("Turning!");
  }
}
