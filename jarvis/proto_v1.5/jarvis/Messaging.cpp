#include "./Messaging.h"

Messaging::Messaging(/* args */):command(doc_size)
{
  Serial.begin(115200);
}
Messaging::~Messaging() {

}

void Messaging::sendJson(DynamicJsonDocument message)
{
  Serial.print(start_bit);
  serializeJson(message, Serial);
  Serial.print(stop_bit);
}

void Messaging::sendJson(const String& message)
{
  DynamicJsonDocument response(doc_size);
  response["msg"] = message;
  Serial.print(start_bit);
  serializeJson(response, Serial);
  Serial.print(stop_bit);
}

void Messaging::readCommands(const String payload)
{
  this->sendJson(payload);
  DeserializationError err = deserializeJson(command, payload);
  this->sendJson(command);
  if (err) {
    DynamicJsonDocument response(doc_size);
    response["error"] = err.c_str();
    sendJson(response);
    docAvailable = false;
  }else
  {
    docAvailable = true;
  }
}

void Messaging::unFlag()
{
  this-> docAvailable = false;
}

boolean Messaging::hasNewCommand()
{
  return this-> docAvailable;
}

DynamicJsonDocument Messaging::getCommand()
{
  return this-> command;
}
