// (c) https://vk.com/myrobotics

#include "Arduino.h"
#include "KemaState.h"

KemaState::KemaState()
{
    _speed = 0;
	_turn_ang = 0;
	_echo_right = 0;
	_echo_left = 0;
	_echo_left = 0;
	
	_ir_left = 1;
	_ir_right = 1;
	_crash_left = 0;
	_crash_right = 0;
	_sens_speed = 0;
	
	_action = 'S';
	_led = '?';
}

int KemaState::speed()
{
   return _speed;
}

int KemaState::turnAng()
{
   return _turn_ang;
}

int KemaState::echoR()
{
   return _echo_right;
}

int KemaState::echoL()
{
   return _echo_left;
}

char KemaState::act()
{
   return _action;
}

char KemaState::led()
{
   return _led;
}

int KemaState::irL()
{
   return _ir_left;
}

int KemaState::irR()
{
   return _ir_right;
}

int KemaState::crashL()
{
   return _crash_left;
}

int KemaState::crashR()
{
   return _crash_right;
}

int KemaState::sensSpeed()
{
   return _sens_speed;
}

void KemaState::setSpeed(int speed)
{
   _speed = speed;
   
}

void KemaState::setTurnAng(int turn_ang)
{
   	_turn_ang = turn_ang;
	
}

void KemaState::setEchoR(int echo_right)
{
   _echo_right = echo_right;
}

void KemaState::setEchoL(int echo_left)
{
   _echo_left = echo_left;
}

void KemaState::setAct(char action)
{
   _action = action;
}

void KemaState::setLed(char led)
{
   _led = led;
}

void KemaState::setIRL(int ir_left)
{
   _ir_left = ir_left;
}

void KemaState::setIRR(int ir_right)
{
   _ir_right = ir_right;
}

void KemaState::setCrashL(int crash_left)
{
   _crash_left = crash_left;
}

void KemaState::setCrashR(int crash_right)
{
   _crash_right = crash_right;
}

void KemaState::setSensSpeed(int speed)
{
   _sens_speed = speed;
   
}