#include "Actuators/LLAMAServo.h"
#include "Actuators/Actuators2.h"
#include <Servo.h>
const int inD = 2;
Actuator* A = new LLAMAServo(9);
Actuator* LLList[inD] = {new LLAMAServo(9), new LLAMAServo(10)};
float target1[inD] = {90,90};
float target2[inD] = {0,0};


Actuators<inD> Acts(LLList);



void setup(){
  Serial.begin(9600);
}

void loop(){
    
  Acts.setTarget(target1);
  while(!Acts.hasReached()){
    Acts.runThis();
  }
  Acts.setTarget(target2);
  while(!Acts.hasReached()){
    Acts.runThis();
  }
   
}
