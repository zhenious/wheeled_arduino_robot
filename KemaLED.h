// (c) https://vk.com/myrobotics

#ifndef KemaLED_h
#define KemaLED_h

#include "Arduino.h"

class KemaLED
{
  public:
    KemaLED(int rPin, int gPin, int bPin);
	void led(char color);
  private:
    int _rPin;
    int _gPin;
    int _bPin;

};

#endif