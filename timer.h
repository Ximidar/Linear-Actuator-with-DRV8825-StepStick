class timer{
  
  public:
    
    
    unsigned long currentTime;
    unsigned long timerLength;
    bool finished = false;
    
    timer();
    void setMilliTimer(unsigned long milli);
    void setSecondTimer(unsigned long seconds);
    void setMinuteTimer(unsigned long minutes);
    bool checkTimer();
  
    
  
};
