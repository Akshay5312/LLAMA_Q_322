#pragma once

#include "Actuator.h"
#include<Servo.h>

class LLAMAServo:public Actuator{
  private:
    float thisTarget = 0;
    float pos = 0;
    float timeDelay = 30;
    float lastTime;
    bool initialized = false;
    int pin;
    
    bool countingUp = true;
public:
    Servo myServo;
  LLAMAServo(int pinNo):Actuator(){
    pin = pinNo;
    //pos = initPos;
  }

  
  void setTarget(float target){
    thisTarget = target;
    lastTime = millis();
  
    countingUp = (target >= pos);
  }
  
  float getValue(){
    return pos;
  }

  float getTarget(){
    return thisTarget;
  }
  
  bool runThis(){
    if(!initialized){initialized = true; myServo.attach(pin);}
    if((millis() - lastTime) > timeDelay){
      if(countingUp){pos = pos + 1; if(pos > thisTarget){ pos = thisTarget;}}
      if(!countingUp){pos = pos - 1; if(pos < thisTarget){ pos = thisTarget;}}
      lastTime = millis();
    }
    wts(pos);
    return hasReached();
  }

  void wts(float p){
      myServo.write(p);
  }
  
  bool hasReached(){
    return ((pos == thisTarget));
  }

};