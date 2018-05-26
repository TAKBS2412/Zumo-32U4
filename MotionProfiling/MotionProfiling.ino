#include "Trajectory.h"

unsigned int segIndex = 0; // Which segment we're currently on.

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  segIndex = 0;
}

void loop() {
  if(segIndex < profileSize) {
    double pos = motionProfile[segIndex][0];
    
    Serial.print("Position: ");
    Serial.println(pos);

    double velocity = motionProfile[segIndex][1];

    Serial.print("Velocity: ");
    Serial.println(velocity);
    
    segIndex++;
    delay(200);
  }
}
