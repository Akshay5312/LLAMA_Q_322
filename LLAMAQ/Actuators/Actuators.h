#pragma once

#include <ArduinoEigen.h>
#include <ArduinoEigenDense.h>
#include <ArduinoEigenSparse.h>
#include "Actuator.h"
using Eigen::VectorXd;

template<int inDOF>
class ActuatorArray{
  Actuator* thisArray;
  public:
  ActuatorArray(Actuator* inArray){
    thisArray = inArray; 
  }

  VectorXd<inDOF> getVals(){
        VectorXd<inDOF> values;
        for(int i = 0; i < inDOF; i++){
          
            values(i) = thisArray[i].getValue();
        }
        return values;
  }

  void setTargets(VectorXd<inDOF> targets){
      for(int i = 0; i < inDOF; i++){
          thisArray[i].setTarget(targets(i));
      }
  }

  void runThis(){
      for(int i = 0; i < inDOF; i++){
          thisArray[i].runThis();
      }
  }

  bool hasReached(){
    for(int i = 0; i < inDOF; i++){
      if(!thisArray[i].hasReached()) return false;
    }
    return true;
  }
  
};
