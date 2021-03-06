#include "./BlockedMotor.h"

BlockedMotor::BlockedMotor(const BlockedMotorInitializer& blockedMotorInitializer):
  servo(), spin(blockedMotorInitializer.spin), min(blockedMotorInitializer.min), max(blockedMotorInitializer.max), position(blockedMotorInitializer.position)
{
  servo.attach(blockedMotorInitializer.pin);
  servo.write(this->position);
}


BlockedMotor::BlockedMotor(const int& pin, const int& spin, const int& min, const int& max, const int& initPosition):
  servo(), spin(spin), min(min), max(max), position(initPosition)
{
  servo.attach(pin);
  servo.write(this->position);
}

BlockedMotor::~BlockedMotor()
{
}

int BlockedMotor::targetFilter(const int& target){
  if(target > this-> max)
    return this->max;
  if(target < this-> min)
    return this->min;
  return target;   
}

void BlockedMotor::setPosition(const int& value)
{

  if (value < this->min)
    this->position = this->min;
  else
  {
    if (value > this->max)
      this->position = this->max;
    else
      this->position = value;
  }
  servo.write(this->position);
}

void BlockedMotor::add(const int& value)
{
  this->setPosition(this->getPosition() + (this->spin)*value);
}

void BlockedMotor::remove(const int& value)
{
  this->setPosition(this->getPosition() - (this->spin)*value);
}

int BlockedMotor::getPosition() {
  return this->position;
}
