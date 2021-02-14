#include <Servo.h>

int VHGPIN = 2;
int HHGPIN = 3;
int VHDPIN = 4;
int HHDPIN = 5;
int VADPIN = 6;
int HADPIN = 7;
int HAGPIN = 14;
int VAGPIN = 15;

int val_init = 90;

struct Patte {
  Servo horizon;
  Servo vertical;
  int maxUp;
  int maxDown;
  int maxFront;
  int maxBack;
  int positionH;
  int positionV;
  int axisH;
  int axisV;
};


Patte AVD;
Patte AVG;
Patte ARD;
Patte ARG;

void init_leg(Patte patte, int pinV, int pinH,   int maxUp,  int maxDown,  int maxFront,  int maxBack,  int axisH,  int axisV)
{
  patte.vertical.attach(pinV);
  patte.horizon.attach(pinH);
  patte.maxUp=maxUp;
  patte.maxDown=maxDown;
  patte.maxFront=maxFront;
  patte.maxBack=maxBack;
  patte.axisH=axisH;
  patte.axisV=axisV;
  patte.positionH=val_init;
  patte.positionV=val_init;
  patte.vertical.write(val_init);
  patte.horizon.write(val_init);
}

void init_legs()
{
  init_leg(AVD,VHDPIN,HHDPIN,50,80,110,55,-1,1);
  init_leg(AVG,VHGPIN,HHGPIN,130,100,70,125,1,-1);
  init_leg(ARD,VADPIN,HADPIN,130,100,140,70,1,1);
  init_leg(ARG,VAGPIN,HAGPIN,50,80,60,130,-1,-1);
}


void partialMoveUP(Patte patte,int inc)
{
  int newPosition=patte.positionV + (patte.axisV *inc);
  if(newPosition > patte.maxUp)
    patte.positionV=patte.maxUp;
  else
    patte.positionV=newPosition;
  patte.vertical.write(patte.positionV);
}

void partialMoveDOWN(Patte patte,int inc)
{
  int newPosition=patte.positionV - (patte.axisV *inc);
  if(newPosition < patte.maxDown)
    patte.positionV=patte.maxDown;
  else
    patte.positionV=newPosition;
  patte.vertical.write(patte.positionV);
}

void partialMoveFRONT(Patte patte,int inc)
{
  int newPosition=patte.positionH + (patte.axisH *inc);
  if(newPosition > patte.maxFront)
    patte.positionH=patte.maxFront;
  else
    patte.positionH=newPosition;
  patte.horizon.write(patte.positionH);
}

void partialMoveBACK(Patte patte,int inc)
{
  int newPosition=patte.positionH - (patte.axisH *inc);
  if(newPosition < patte.maxBack)
    patte.positionH=patte.maxBack;
  else
    patte.positionH=newPosition;
  patte.horizon.write(patte.positionH);
}



void moveUP(Patte patte)
{
  partialMoveUP(patte,patte.maxUp);
}

void moveDOWN(Patte patte)
{
  partialMoveDOWN(patte,patte.maxDown);
}

void moveFRONT(Patte patte)
{
  partialMoveFRONT(patte,patte.maxFront);
}

void moveBACK(Patte patte)
{
  partialMoveBACK(patte,patte.maxBack);
}
