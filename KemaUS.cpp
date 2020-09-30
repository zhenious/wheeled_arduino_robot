// (c) https://vk.com/myrobotics

#include "Arduino.h"
#include "KemaUS.h"

KemaUS::KemaUS(int trig1,int echo1,int trig2,int echo2)
{
 	_trig1 = trig1;
	_echo1 = echo1;
	_trig2 = trig2;
	_echo2 = echo2;
	_durationL = 0;
	_durationR = 0;
	_dataBuff[0] = 0;
	_dataBuff[1] = 0;
	_dataBuff[2] = 0;
	_dataBuff[3] = 0;
	_dataBuff[4] = 0;
	_prevData = 0;
	_curData = 0;
  pinMode(_trig1, OUTPUT);
  pinMode(_echo1, INPUT);  
  pinMode(_trig2, OUTPUT);
  pinMode(_echo2, INPUT);  
 
}

int KemaUS::pingL()
{
      digitalWrite(_trig1, LOW);
      digitalWrite(_trig1, HIGH);
 	  _durationL = pulseIn(_echo1, HIGH, 3000);
	  return int((_durationL/2)/3.4);
}

int KemaUS::pingR()
{
      digitalWrite(_trig2, LOW);
      digitalWrite(_trig2, HIGH);
 	  _durationR = pulseIn(_echo2, HIGH, 3000);
	  return int((_durationR/2)/3.4);
}

float KemaUS::objSpeed()
{
   int summ = 0;
   int i;
   for (i = 0; i < 5; i = i + 1)
	   summ += _dataBuff[i];
   _prevData = float(summ)/5;
   	   
    int tempBuff[5];
	
    for (i = 0; i < 4; i = i + 1)
	   tempBuff[i] = _dataBuff[i+1];
	tempBuff[4] = int((_durationR/2)/3.4);  
	_dataBuff[0] = tempBuff[0];
	_dataBuff[1] = tempBuff[1];
	_dataBuff[2] = tempBuff[2];
	_dataBuff[3] = tempBuff[3];
	_dataBuff[4] = tempBuff[4];
	
   summ = 0;
   for (i = 0; i < 5; i = i + 1)
	   summ += _dataBuff[i];
   _curData = float(summ)/5;
  return (_curData - _prevData);	
}