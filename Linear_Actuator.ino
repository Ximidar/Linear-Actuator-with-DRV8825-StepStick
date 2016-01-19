//Made by Matt Pedler MattJPedler@gmail.com

//Includes
#include "actuator.h"

//objects
Actuator rail;

//Setup
void setup(){
  rail.init(); // sets up necessary pins
  Serial.begin(9600);//start serial for error reporting and state reporting
}

//loop
void loop(){
  delay(3000); //place holder for a button push to start the sequence
  rail.enable_motors(true); //enable motors
  rail.directions(BACKWARD); //set backward motion
  rail.steps(17000, 200); //steps 17000 steps with 200 microseconds between steps
  rail.directions(FORWARD);// sets forward motion
  rail.steps(17000, 500); // steps 17000 steps with 500 microseconds between steps
  
  //test for seeing if the stepping is happening correctly
  for(int i = 0 ; i < 10 ; i++){
    rail.directions(BACKWARD);
    rail.steps(1700*i,200); 
    rail.directions(FORWARD);
    rail.steps(1700*i, 200);
    
  }
  
  rail.enable_motors(false);//disable motors
  while(true);//end loop indefinitely
  
  
}
