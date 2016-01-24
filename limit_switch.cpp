#include "limit_switch.h"

LimitSwitch::LimitSwitch(){
  
}

void LimitSwitch::init(int pin){
  pinMode(pin, INPUT_PULLUP); // sets up the chosen pin as what it needs to be
  if(Serial.available()){
    Serial.print("Pin: ");
    Serial.print(pin);
    Serial.println(" put into INPUT_PULLUP Mode");  
  }
  PIN = pin;
}

bool LimitSwitch::CheckLimit(){
  if(digitalRead(PIN) == 1){
    return true;
  }
  else{
    Serial.println("Button Hit!");
    return false;  
  }
}
