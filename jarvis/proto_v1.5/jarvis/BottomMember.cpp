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
  
  int targetGenouD=legD->getGenou().adaptTarget(messaging);
  int targetCuisseD=legD->getCuisse().adaptTarget(messaging);
  int targetRotD=legD->getHancheRot().adaptTarget(messaging);
  int targetEccartD=legD->getHancheEccart().adaptTarget(messaging);
  
  int targetGenouG=legG->getGenou().adaptTarget(messaging);
  int targetCuisseG=legG->getCuisse().adaptTarget(messaging);
  int targetRotG=legG->getHancheRot().adaptTarget(messaging);
  int targetEccartG=legG->getHancheEccart().adaptTarget(messaging);

  while( !legD->isTargetReached(targetGenouD,targetCuisseD, targetRotD, targetEccartD) || !legG->isTargetReached(targetGenouG,targetCuisseG, targetRotG, targetEccartG) )
  {
    legD->moveTo(targetGenouD,targetCuisseD, targetRotD, targetEccartD);
    legG->moveTo(targetGenouG,targetCuisseG, targetRotG, targetEccartG);
    messaging->sendJson(this->getPosition());
    delay(10);
  }
}

 
