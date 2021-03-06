/* This program drives each motor using PID control with the encoders as feedback. */

#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA;
Zumo32U4Encoders encoders;

Zumo32U4LCD lcd;

int16_t distanceToDrive = 500; // The distance setpoint.

/* PID constants */
double kP = 1.5;
double kI = 0.0;
double kD = 0.0;

/* Integral windup term and error */
double errorSum = 0;
double error = 0;
double lastError = 0;

int counter = 0;

bool drivingDone = false;

/* Starting encoder values */
int16_t startingCountsLeft = 0;
int16_t startingCountsRight = 0;

void setup() {
  // Wait for the user to press button A.
  lcd.clear();
  lcd.print("Press A");
  
  buttonA.waitForButton();
  
  // Delay so that the robot does not move away while the user is
  // still touching it.
  delay(1000);

  Serial.begin(9600);
  
  unsigned long startTime = millis();

  while(millis() - startTime < 1000) {
    motors.setLeftSpeed(400);
    motors.setRightSpeed(400);
  }

  motors.setLeftSpeed(0);
  motors.setRightSpeed(0);

  delay(1000);

  startingCountsLeft = encoders.getCountsLeft();
  startingCountsRight = encoders.getCountsRight();
}

void loop() {
  int16_t countsLeft = encoders.getCountsLeft() - startingCountsLeft;
  int16_t countsRight = encoders.getCountsRight() - startingCountsRight;
  
  counter++;
  
  if(drivingDone || counter % 1000 == 0) {
      lcd.clear();
      lcd.print(countsLeft);
      lcd.print(" ");
  }
    
  if(!drivingDone) { 
    error = distanceToDrive - countsRight;
    errorSum += error;
    if(abs(errorSum) > 1000) errorSum = 0;
  
    double speed = kP * error + kI * errorSum + kD * (error - lastError);
    
    motors.setLeftSpeed(speed);
    motors.setRightSpeed(speed);
    
    lastError = error;

    if(abs(error) < 10) {
      drivingDone = true;
//      lcd.clear();
    }
  } else {
    motors.setLeftSpeed(0);
    motors.setRightSpeed(0);
  
    lcd.print("Done");
    lcd.gotoXY(0, 1);
    lcd.print("Driving!");
    delay(100);

    /*
    lcd.clear();
    lcd.print("Done");
    lcd.gotoXY(0, 1);
    lcd.print("Driving!");
    delay(500);
    */
    /*
    lcd.print("Done");
    lcd.gotoXY(0, 1);
    lcd.print("Driving!");
    */
  }
}
