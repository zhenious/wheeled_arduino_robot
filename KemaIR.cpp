// (c) https://vk.com/myrobotics

#include "Arduino.h"
#include "KemaIR.h"

KemaIR::KemaIR(int ir1, int irr)
{
 	_ir1 = ir1;
	_irr = irr;
  pinMode(_ir1, INPUT);  
  pinMode(_irr, INPUT);
 
}

int KemaIR::pingL()
{
	  return digitalRead(_ir1);
}

int KemaIR::pingR()
{
	  return digitalRead(_irr);
}