#include "./BlockedMotor.h"

BlockedMotor::BlockedMotor(const BlockedMotorInitializer& blockedMotorInitializer):
  servo(), tag(blockedMotorInitializer.tag), spin(blockedMotorInitializer.spin), minPosition(blockedMotorInitializer.minPosition), maxPosition(blockedMotorInitializer.maxPosition), position(blockedMotorInitializer.position)
{
  servo.attach(blockedMotorInitializer.pin);
  servo.write(this->position);
}


BlockedMotor::BlockedMotor(const String& tag,const int& pin, const int& spin, const int& minPosition, const int& maxPosition, const int& initPosition):
  servo(), tag(tag), spin(spin), minPosition(minPosition), maxPosition(maxPosition), position(initPosition)
{
  servo.attach(pin);
  servo.write(this->position);
}

BlockedMotor::~BlockedMotor()
{
}

String BlockedMotor::getTag(){
  return this->tag;   
}

int BlockedMotor::adaptTarget(Messaging* messaging){
  int target=messaging->getCommand()[this->getTag()];

  if(target > this-> maxPosition)
    return this->maxPosition;
  if(target < this-> minPosition)
    return this->minPosition;
  return target;   
}

void BlockedMotor::setPosition(const int& value)
{

  if (value < this->minPosition)
    this->position = this->minPosition;
  else
  {
    if (value > this->maxPosition)
      this->position = this->maxPosition;
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

bool BlockedMotor::isTargetReached(int target)
 {
   return this->position == target;
 }
