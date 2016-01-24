#include "timer.h"
#include "Arduino.h"

#define DEBUG;
 
void timer::setMilliTimer(unsigned long milli){

   currentTime = millis();

   timerLength = currentTime + milli;

   
   #ifdef DEBUG
    
      Serial.print("timerLength = ");
      Serial.println(timerLength);
    
   #endif

 
}
void timer::setSecondTimer(unsigned long seconds){
    currentTime = millis();

   timerLength = currentTime + (seconds * 1000);

   
   #ifdef DEBUG
    
      Serial.print("timerLength = ");
      Serial.println(timerLength);
    
   #endif

}
void timer::setMinuteTimer(unsigned long minutes){
   currentTime = millis();

   timerLength = currentTime + (minutes * 60000);

   
   #ifdef DEBUG
    
      Serial.print("timerLength = ");
      Serial.println(timerLength);
    
   #endif

}
bool timer::checkTimer(){

  currentTime = millis();

  #ifdef DEBUG
   
      Serial.print("currentTime = ");
      Serial.println(currentTime);
    
   #endif
  
  if(currentTime >= timerLength && finished == false){
    return true;
    
  }
  else{
    return false;
  }
 
}
  
 
timer::timer(){}
