#ifndef ServoGG_h
#define ServoGG_h

#include "Arduino.h"

class ServoGG{
  public:
    ServoGG(int pin);
    void setAngulo(int angulo);
  private:
    int _pin;
};

#endif