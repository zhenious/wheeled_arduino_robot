// (c) https://vk.com/myrobotics

#ifndef KemaMem_h
#define KemaMem_h

#include "Arduino.h"
#include "KemaState.h"

class KemaMem
{
  public:
    KemaMem();
	void push(int spd, int ang);
	int getSpeed();
	int getAngel();
	boolean isNext();
  private:
    int _length;
    int _speedArr[30];
	int _angArr[30];
    int _ind;
	
};

#endif