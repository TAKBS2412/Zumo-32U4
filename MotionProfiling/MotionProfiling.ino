/* This program drives each motor using motion profiling. */

#include "Trajectory.h"
#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA;
Zumo32U4Encoders encoders;

Zumo32U4LCD lcd;

unsigned int segIndex = 0; // Which segment we're currently on.

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
  
  segIndex = 0;

  startingCountsLeft = encoders.getCountsLeft();
  startingCountsRight = encoders.getCountsRight();
}

void loop() {
  if(segIndex < profileSize) {
    double pos = motionProfile[segIndex][0];
    
    Serial.print("Position: ");
    Serial.println(pos);

    double velocity = motionProfile[segIndex][1];

    Serial.print("Velocity: ");
    Serial.println(velocity);

    double volts = readBatteryMillivolts() / 1000.0;
    Serial.print("Voltage: ");
    Serial.println(volts);
    
    segIndex++;
    delay(200);
  }
}
