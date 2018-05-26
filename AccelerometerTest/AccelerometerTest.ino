/* This is a test program for reading values from the accelerometer and detecting collisions. */

#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA;

Zumo32U4LCD lcd;

LSM303 accelerometer;

unsigned long startTime = 0;

void setup() {
  Wire.begin();

  if (!accelerometer.init())
  {
    // Failed to detect the accelerometer.
    ledRed(1);
    while(1)
    {
      Serial.println(F("Failed to detect the accelerometer."));
      delay(100);
    }
  }

  accelerometer.enableDefault();
  
  // Tell the user to press button A.
  lcd.clear();
  lcd.print("Press A");

  // Wait for the user to press button A.
  buttonA.waitForButton();

  // Delay so that the robot does not move away while the user is
  // still touching it.
  delay(1000);
  Serial.begin(9600);
  startTime = millis();
}

void loop() {
  lcd.clear();
  accelerometer.read();
  if(millis() - startTime < 1000) {
    Serial.println("Hello, world!");
    motors.setLeftSpeed(400);
    motors.setRightSpeed(400);

    if(accelerometer.a.x < 0) {
      ledRed(0);
    }
  } else {
    motors.setLeftSpeed(0);
    motors.setRightSpeed(0);
  }

  Serial.println(accelerometer.a.x);
//  lcd.println(accelerometer.a.y);
  
  delay(50);
  
}
