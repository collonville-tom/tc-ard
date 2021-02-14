
#include <ArduinoJson.h>


StaticJsonDocument<200> doc;
boolean docAvailable=false;

const char start_bit='$';
const char stop_bit='#';

void readCommands()
{
  boolean loading=false;
  String payload="";
  while (Serial.available())
  {
    char incomingByte = Serial.read(); 
    if(incomingByte == stop_bit)
    {
        loading=false;
    }
    if(loading)
    {
      payload += (char) incomingByte;
    }  
    if(incomingByte == start_bit)
    {
        loading=true;
    }  
  }
  if(payload != ""){
    Serial.print("Payload:(");
    Serial.print(payload);
    Serial.println(")");
    DeserializationError err=deserializeJson(doc, payload);
    if(err) {
      Serial.print("deserializeJson() failed with code ");
      Serial.println(err.c_str());}
    docAvailable=true;
  }

}
