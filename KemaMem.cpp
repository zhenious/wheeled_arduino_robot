// (c) https://vk.com/myrobotics

#include "Arduino.h"
#include "KemaMem.h"

KemaMem::KemaMem()
{
    _length = 30;
    _ind = -1;
	for (int i=0; i < _length; i++)
	{
        _speedArr[i] = 0;
        _angArr[i] = 0;		
	}	 
}

void KemaMem::push(int spd, int ang)
{
    
    for (int i=_length-1; i > 0; i--)
	{
        _speedArr[i] = _speedArr[i-1];
        _angArr[i] = _angArr[i-1];
		
	}	 
    _speedArr[0] = spd;
	_angArr[0] = ang;
	
}

int KemaMem::getSpeed()
{
    return  _speedArr[_ind];
}

int KemaMem::getAngel()
{
    return  _angArr[_ind];
}

boolean KemaMem::isNext()
{  
    _ind++;
    if(_ind < _length)
       return  true;
	else
	{
	   _ind = -1;
	   return  false;   
	}
}
