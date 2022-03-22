#include "LLAMAStepper.h"

LLAMAStepper S1(3,4);
LLAMAStepper S2(6,7);

void setup(){

  //Serial.begin(9600);
    S1.setTarget(100);
    S2.setTarget(200);

    //Serial.println("5000");
}

void loop(){
    if(S1.hasReached()){
        S1.setTarget(-S1.getValue());
    }
    if(S2.hasReached()){
        S2.setTarget(-S2.getValue());
    }

    
    S2.runThis();
    S1.runThis();
}
