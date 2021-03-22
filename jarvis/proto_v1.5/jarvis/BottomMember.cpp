#include "./BottomMember.h"

BottomMember::BottomMember(const Leg* legD,const Leg* legG):
legD(legD),legG(legG)
{

}

BottomMember::~BottomMember()
{
    
}

DynamicJsonDocument BottomMember::getPosition(){
  DynamicJsonDocument response(512);
  response[legD->getCuisse().getTag()] = legD->getCuisse().getPosition();
  response[legD->getGenou().getTag()] = legD->getGenou().getPosition();
  response[legD->getHancheRot().getTag()] = legD->getHancheRot().getPosition();
  response[legD->getHancheEccart().getTag()] = legD->getHancheEccart().getPosition();

  response[legG->getCuisse().getTag()] = legG->getCuisse().getPosition();
  response[legG->getGenou().getTag()] = legG->getGenou().getPosition();
  response[legG->getHancheRot().getTag()] = legG->getHancheRot().getPosition();
  response[legG->getHancheEccart().getTag()] = legG->getHancheEccart().getPosition();
  return response;
}

void BottomMember::moveTo(Messaging* messaging)
{
  /*
  TODO: prevoir que l'on ne peut envoyer que 5 target dans le meme message json
  donc il faut pour chaque target soit detecter quel target ont a recu et initialiser les autres avec les valeurs par defaut
  */
  
  int targetGenouD=legD->getGenou().targetFilter(messaging->getCommand()["gdt"]);
  int targetCuisseD=legD->getCuisse().targetFilter(messaging->getCommand()["cdt"]);
  int targetRotD=legD->getHancheRot().targetFilter(messaging->getCommand()["rdt"]);
  int targetEccartD=legD->getHancheEccart().targetFilter(messaging->getCommand()["edt"]);
  
  int targetGenouG=legG->getGenou().targetFilter(messaging->getCommand()["ggt"]);
  int targetCuisseG=legG->getCuisse().targetFilter(messaging->getCommand()["cgt"]);
  int targetRotG=legG->getHancheRot().targetFilter(messaging->getCommand()["rgt"]);
  int targetEccartG=legG->getHancheEccart().targetFilter(messaging->getCommand()["egt"]);

  while( !legD->isTargetReached(targetGenouD,targetCuisseD, targetRotD, targetEccartD) || !legG->isTargetReached(targetGenouG,targetCuisseG, targetRotG, targetEccartG) )
  {
    legD->moveTo(targetGenouD,targetCuisseD, targetRotD, targetEccartD);
    legG->moveTo(targetGenouG,targetCuisseG, targetRotG, targetEccartG);
    messaging->sendJson(this->getPosition());
    delay(10);
  }
}

 
