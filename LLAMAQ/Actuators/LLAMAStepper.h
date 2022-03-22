#pragma once

#include <AccelStepper.h>
#include "Actuator.h"
class LLAMAStepper : public Actuator{
  private:
    AccelStepper usedStepper;
    void init(float maxVel = 500, float maxAccel = 500){
      usedStepper.setMaxSpeed(maxVel);
      usedStepper.setSpeed(maxVel);
      usedStepper.setAcceleration(100);
    }
  public:
  LLAMAStepper(int stepPin, int dirPin):Actuator(){
    usedStepper = AccelStepper(AccelStepper::FULL2WIRE, stepPin, dirPin);
    init();
  };

   void setTarget(float target){
    Serial.println(target);
    usedStepper.moveTo(target);
   }


   
   float getValue(){
    return usedStepper.currentPosition();
   }
   bool hasReached(){
    return usedStepper.distanceToGo() == 0;
   }
  
    float getTarget(){
      
      return usedStepper.targetPosition();
    }
   
   bool runThis(){
    usedStepper.run();
    return hasReached();
   }
  
};
