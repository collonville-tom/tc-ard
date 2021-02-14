
#include "./leg.h"
#include "./bt.h"
#include <ArduinoJson.h>
#include "./mem.h"

int cycle_base=1000;


void setup() {
  init_legs();
  
  Serial.begin(115200);
  Serial.print("Init Done");
}

void loop() {
  
  if( docAvailable )
  {
    Serial.print("Execution de la commande");
    serializeJson(doc, Serial);
    docAvailable=false; 
  }
  Serial.println("En attente d'un nouveau message");
  print_mem_state();
  delay(cycle_base);
}

//Serial read data
void serialEvent()
{
    readCommands();
}
