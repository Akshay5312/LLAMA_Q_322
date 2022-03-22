#include "Actuators/LLAMAServo.h"
#include <Servo.h>
LLAMAServo S1(9);
LLAMAServo S2(10);
void setup(){
  Serial.begin(9600);
}

void loop(){
    
  S1.setTarget(90);
  S2.setTarget(90);
  while(!(S1.hasReached()&&S2.hasReached())){
    //Serial.println(S1.getValue());
    S1.runThis();
    S2.runThis();
    //S1.myServo.write(S1.getPos());
  }
  S1.setTarget(0);
  S2.setTarget(0);
  while(!(S1.hasReached()&&S2.hasReached())){
    S1.runThis();
    S2.runThis();
    //S1.myServo.write(S1.getPos());
  }
   
}
