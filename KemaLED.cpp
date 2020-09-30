// (c) https://vk.com/myrobotics

#include "Arduino.h"
#include "KemaLED.h"

KemaLED::KemaLED(int rPin, int gPin, int bPin)
{
 	_rPin = rPin;
	_gPin = gPin;
	_bPin = bPin;
	
  pinMode(_rPin, OUTPUT); 
  pinMode(_gPin, OUTPUT);
  pinMode(_bPin, OUTPUT);
	
  analogWrite(_rPin, 0);
  analogWrite(_gPin, 0);
  analogWrite(_bPin, 0);
 
}

void KemaLED::led(char color)
{
    switch (color)
    {
      case 'R':
  	  	 analogWrite(_rPin, 0);
  		 analogWrite(_gPin, 255);
  		 analogWrite(_bPin, 255);
      break;
	  
      case 'G':
  	  	 analogWrite(_rPin, 255);
  		 analogWrite(_gPin, 0);
  		 analogWrite(_bPin, 255);
      break;
	  
      case 'B':
  	  	 analogWrite(_rPin, 255);
  		 analogWrite(_gPin, 255);
  		 analogWrite(_bPin, 0);
	  break; 
	  
      case 'Y':
  	  	 analogWrite(_rPin, 0);
  		 analogWrite(_gPin, 75);
  		 analogWrite(_bPin, 255);
      break;
	  
      case 'W':
  	  	 analogWrite(_rPin, 0);
  		 analogWrite(_gPin, 0);
  		 analogWrite(_bPin, 0);
      break;
	  
     
    }
}
