#pragma once

class Actuator{
  public:
  Actuator(){};

  virtual ~Actuator(){}

  virtual void setTarget(float target);
  virtual float getValue();
  virtual bool hasReached();
  virtual float getTarget();
  virtual bool runThis();
};