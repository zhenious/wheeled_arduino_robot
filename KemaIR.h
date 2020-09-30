// (c) https://vk.com/myrobotics

#ifndef KemaIR_h
#define KemaIR_h

#include "Arduino.h"

class KemaIR
{
  public:
    KemaIR(int ir1, int irr);
	int pingL();
	int pingR();
  private:
    int _ir1;
	int _irr;
};

#endif