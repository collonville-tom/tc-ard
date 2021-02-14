#include "./Messaging.h"

Messaging::Messaging(/* args */):command(512)
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
  DynamicJsonDocument response(512);
  response["msg"] = message;
  Serial.print(start_bit);
  serializeJson(response, Serial);
  Serial.print(stop_bit);
}

void Messaging::readCommands(const String payload)
{
  DeserializationError err = deserializeJson(command, payload);
  if (err) {
    DynamicJsonDocument response(512);
    response["error"] = err.c_str();
    sendJson(response);
    docAvailable = false;
  }
  docAvailable = true;
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
