#include "./BottomMember.h"

BottomMember::BottomMember(const Leg& legD,const Leg& legG):
legD(legD),legG(legG)
{

}

BottomMember::~BottomMember()
{
    
}

DynamicJsonDocument BottomMember::getPosition(){
  DynamicJsonDocument response(512);
  return response;
}

void BottomMember::moveTo(Messaging* messaging)
{
}
