// (c) https://vk.com/myrobotics

#ifndef KemaUS_h
#define KemaUS_h

#include "Arduino.h"

class KemaUS
{
  public:
    KemaUS(int trig1,int echo1,int trig2,int echo2);
	float objSpeed();
    int pingL();
    int pingR(); 
  private:
    int _trig1;
    int _echo1;
    int _trig2;
    int _echo2;
	long _durationR;
	long _durationL;
	int _dataBuff[5];
	float _prevData;
	float _curData;
	
};

#endif