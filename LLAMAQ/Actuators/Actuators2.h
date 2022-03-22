#pragma once
#include "Actuator.h"


template<int inDOF>
class Actuators{
private:
  Actuator** LLList;
public:

  Actuators(Actuator** inList){
    LLList = inList;
  }

  void setTarget(float* target){
    for(int i = 0; i < inDOF; i++){
      LLList[i]->setTarget(target[i]);
    }
  }

  bool hasReached(){
    for(int i = 0; i < inDOF; i++){
      if(!LLList[i]->hasReached()) return false;
    }
    return true;
  }

  void runThis(){
    for(int i = 0; i < inDOF; i++){
      LLList[i]->runThis();
    }
  }
};