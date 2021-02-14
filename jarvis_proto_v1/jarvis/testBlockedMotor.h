
#include "./BlockedMotor.h"



void testMotorGenou()
{
  BlockedMotor::BlockedMotorInitializer genouInit;
  genouInit.spin = 1;
  genouInit.pin = 5;
  genouInit.min = 0;
  genouInit.max = 200;
  genouInit.position = 140;

  BlockedMotor* motor = new BlockedMotor(genouInit);
  Serial.println(motor->getPosition());
  delay(2000);
  motor->setPosition(200);
  Serial.println(motor->getPosition());
  delay(2000);
  motor->remove(200);
  Serial.println(motor->getPosition());
  delay(2000);
  motor->add(100);
  Serial.println(motor->getPosition());
  delay(2000);
  motor->remove(40);
  Serial.println(motor->getPosition());
  delay(2000);
  motor->add(40);
  Serial.println(motor->getPosition());

}
void testMotorCuisse()
{
  BlockedMotor::BlockedMotorInitializer cuisseInit;
  cuisseInit.spin = 1;
  cuisseInit.pin = 4;
  cuisseInit.min = 0;
  cuisseInit.max = 200;
  cuisseInit.position = 130;

  BlockedMotor* motor = new BlockedMotor(cuisseInit);
  Serial.println(motor->getPosition());
  delay(2000);
  motor->setPosition(200);
  Serial.println(motor->getPosition());
  delay(2000);
  motor->remove(200);
  Serial.println(motor->getPosition());
  delay(2000);
  motor->add(100);
  Serial.println(motor->getPosition());
  delay(2000);
  motor->remove(40);
  Serial.println(motor->getPosition());
  delay(2000);
  motor->add(40);
  Serial.println(motor->getPosition());

}

void testMotorHancheEccart()
{
  BlockedMotor::BlockedMotorInitializer hancheEccartInit;
  hancheEccartInit.spin = -1;
  hancheEccartInit.pin = 3;
  hancheEccartInit.min = 100;
  hancheEccartInit.max = 160;
  hancheEccartInit.position = 110;

  BlockedMotor* motor = new BlockedMotor(hancheEccartInit);
  Serial.println(motor->getPosition());
  delay(2000);
  motor->setPosition(160);
  Serial.println(motor->getPosition());
  delay(2000);
  motor->remove(60);
  Serial.println(motor->getPosition());
  delay(2000);
  motor->add(50);
  Serial.println(motor->getPosition());
  delay(2000);
  motor->remove(40);
  Serial.println(motor->getPosition());
  delay(2000);
  motor->add(40);
  Serial.println(motor->getPosition());

}

void testMotorHancheRot()
{
  BlockedMotor::BlockedMotorInitializer hancheRotInit;
  hancheRotInit.spin = -1;
  hancheRotInit.pin = 2;
  hancheRotInit.min = 20;
  hancheRotInit.max = 100;
  hancheRotInit.position = 60;

  BlockedMotor* motor = new BlockedMotor(hancheRotInit);
  Serial.println(motor->getPosition());
  delay(2000);
  motor->setPosition(100);
  Serial.println(motor->getPosition());
  delay(2000);
  motor->remove(60);
  Serial.println(motor->getPosition());
  delay(2000);
  motor->add(50);
  Serial.println(motor->getPosition());
  delay(2000);
  motor->remove(40);
  Serial.println(motor->getPosition());
  delay(2000);
  motor->add(40);
  Serial.println(motor->getPosition());

}


/*
  main test for articulation init
*/
void testArticulationIndependante()
{
  testMotorGenou();
  testMotorCuisse();
  testMotorHancheRot();
  testMotorHancheEccart();
}
