#include "actuator.h"

//Sets up basic pins for output
Actuator::Actuator(){
 pinMode(DIRECTION, OUTPUT);
 pinMode(ENABLE, OUTPUT);
 pinMode(STEP, OUTPUT); 
 count = 0;
 #ifdef DEBUG
   Serial.begin(9600);
 #endif  
}
// use this to initialize the pins so it's ready to go. 
// in the future this will find the zero point on the rail
void Actuator::init(){
 digitalWrite(DIRECTION, LOW);
 digitalWrite(ENABLE, HIGH);
 digitalWrite(STEP, LOW);
}

//this moves the motor one step
void Actuator::one_step(int del){
  digitalWrite(STEP,HIGH);
  delayMicroseconds(del);
  digitalWrite(STEP,LOW);
  delayMicroseconds(del);
}

// decides if the motor is enabled or not
void Actuator::enable_motors(bool state){
  if(state == true){
    digitalWrite(ENABLE, LOW); // enable the chip for movement
  }
  else{
   digitalWrite(ENABLE, HIGH); // disable the chip for movement
  }
}

//decides what direction to move the motor
void Actuator::directions(bool state){
   if(state == true){
    digitalWrite(DIRECTION, LOW); // enable forward
  }
  else{
   digitalWrite(DIRECTION, HIGH); // enable backward
  }
}

//Moves the motor a certain amount of steps with a certain amount of microseconds in between each step. 
// 200 microseconds at a maximum speed otherwise the stepper motor doesn't have enough time to step
void Actuator::steps(int steps, int micro){
 for(int i = 0 ; i <= steps ; i++){
  one_step(micro);
  //if debug is enables this will print out how many steps the motor has taken.
  #ifdef DEBUG
    count++;
    Serial.println(count);
  #endif
 } 
}
