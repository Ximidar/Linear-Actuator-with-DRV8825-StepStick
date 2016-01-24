#include <Arduino.h>


class LimitSwitch{
 public:
  LimitSwitch();
  void init(int pin);
  bool CheckLimit(); 
  int PIN;
  
};
