//define pins
#define DIRECTION 8
#define ENABLE 7
#define STEP 9
//define forward and backward so I stop getting confused
#define FORWARD true
#define BACKWARD false

//#define DEBUG //uncomment this to spit out debug comments

#include <Arduino.h> //include arduino so that we can use basic arduino commands


class Actuator{
  
  public:
    void init();
    void steps(int steps, int micro);
    void enable_motors(bool state);
    void directions(bool state);
    Actuator();
    int count;
  private:
    void one_step(int del);
  
};
