//Made by Matt Pedler MattJPedler@gmail.com

//Hi Matt! Nice code! you should add header protectors though :P

//Includes
#include "actuator.h"
#include "limit_switch.h"
#include "timer.h"

//objects
Actuator rail;
LimitSwitch start;
LimitSwitch backwardS;
timer timer;

//Setup
void setup(){
  rail.init(); // sets up necessary pins
  Serial.begin(9600);//start serial for error reporting and state reporting
  start.init(A0); //set up Switch to be A0
  backwardS.init(A1);//      ""            A1
  Serial.println("Hit the Red Button to start");
  while(start.CheckLimit()){}; // sit here until start button is pushed
  Serial.println("Starting...");
  //find limit
  Serial.println("Attemptimg to find Limit");
  rail.enable_motors(true);
  while(backwardS.CheckLimit()){
      rail.steps(10, 200, FORWARD); //step a tiny amount until the switch is hit
  }
  rail.set_zero();
}

//loop
void loop(){
  
  rail.enable_motors(true); //enable motors
  rail.relay_on(true);
  rail.steps(MAX, 200, BACKWARD); //steps 17000 steps with 200 microseconds between steps
  delay(200);
  rail.steps(MAX, 200, FORWARD); // steps 17000 steps with 500 microseconds between steps
  rail.relay_on(false);
  
  //return to zero and disable motors
  rail.return_zero();
  rail.enable_motors(false);//disable motors
  Serial.println("Waiting 4 hours");
  //set timer and wait
  timer.setMinuteTimer(240);
  while(timer.checkTimer() == false){} 
  Serial.println("Finished Waiting. Starting next pass");
  
}
