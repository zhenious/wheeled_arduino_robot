// (c) https://vk.com/myrobotics

#include "Arduino.h"
#include "KemaDrive.h"

KemaDrive::KemaDrive()
{
 	_in11 = 27;	  //back L
	_in12 = 29;  //back L
	_in21 = 26;  //back R
	_in22 = 28;  //back R
 	_in31 = 51;  //front L
	_in32 = 53;  //front L
	_in41 = 50;  //front R
	_in42 = 52;  //front R
	_enA1 = 2;   //front R
	_enB1 = 3;   //front L
	_enA2 = 4;   //back R
	_enB2 = 5;   //back L
			
  pinMode(_in11, OUTPUT); 
  pinMode(_in12, OUTPUT);
  pinMode(_in21, OUTPUT); 
  pinMode(_in22, OUTPUT);
  pinMode(_in31, OUTPUT); 
  pinMode(_in32, OUTPUT);
  pinMode(_in41, OUTPUT); 
  pinMode(_in42, OUTPUT);
  pinMode(_enA1, OUTPUT); 
  pinMode(_enB1, OUTPUT);
  pinMode(_enA2, OUTPUT); 
  pinMode(_enB2, OUTPUT);
  
  stop();
  
}

void KemaDrive::move(int speed)
{
	if(speed == 0)
       stop();  
	
    if(speed > 0)
	{
	  movFwdR(speed);
	  movFwdL(speed);
	}  
    if(speed < 0)
	{
	  movBckR(abs(speed));
      movBckL(abs(speed));
	}   
}

void KemaDrive::stop()
{
  digitalWrite(_in11, LOW);
  digitalWrite(_in12, LOW); 
  digitalWrite(_in21, LOW);
  digitalWrite(_in22, LOW); 
  digitalWrite(_in31, LOW);
  digitalWrite(_in32, LOW); 
  digitalWrite(_in41, LOW);
  digitalWrite(_in42, LOW); 
  
}

void KemaDrive::movBckR(int speed)
{
    
    int valSpeed = speed*20 + 20;
    digitalWrite(_in41, HIGH);
    digitalWrite(_in42, LOW);
    digitalWrite(_in21, HIGH);
    digitalWrite(_in22, LOW);
	analogWrite(_enA1, valSpeed);
	analogWrite(_enA2, valSpeed);

}

void KemaDrive::movBckL(int speed)
{
    
    int valSpeed = speed*20 + 20;
    digitalWrite(_in31, LOW);
    digitalWrite(_in32, HIGH);
    digitalWrite(_in11, HIGH);
    digitalWrite(_in12, LOW);
	analogWrite(_enB1, valSpeed);
	analogWrite(_enB2, valSpeed);

}

void KemaDrive::movFwdR(int speed)
{
 	int valSpeed = speed*20 + 20;
    digitalWrite(_in41, LOW);
    digitalWrite(_in42, HIGH);
    digitalWrite(_in21, LOW);
    digitalWrite(_in22, HIGH);
	analogWrite(_enA1, valSpeed);
	analogWrite(_enA2, valSpeed);
 
}

void KemaDrive::movFwdL(int speed)
{
 	int valSpeed = speed*20 + 20;
    digitalWrite(_in31, HIGH);
    digitalWrite(_in32, LOW);
    digitalWrite(_in11, LOW);
    digitalWrite(_in12, HIGH);
	analogWrite(_enB1, valSpeed);
	analogWrite(_enB2, valSpeed);
 
}

void KemaDrive::turn(int ang, int curSpeed)
{
  	if(ang == 0)
	   turnReset(curSpeed);
	   
	if((ang > 0)&&(curSpeed > 0))
	    movFwdL(curSpeed + ang);
		
	if((ang < 0)&&(curSpeed > 0))
	    movFwdR(curSpeed + abs(ang));
		
	if((ang > 0)&&(curSpeed < 0))
	    movBckL(abs(curSpeed) + ang);
		
	if((ang < 0)&&(curSpeed < 0))
	    movBckR(abs(curSpeed) + abs(ang));
	
}

void KemaDrive::turnReset(int curSpeed)
{
  	move(curSpeed);
}


