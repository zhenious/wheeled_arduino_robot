// (c) https://vk.com/myrobotics

#ifndef KemaState_h
#define KemaState_h

#include "Arduino.h"

class KemaState
{
  public:
    KemaState();
    int speed();
    int turnAng();
    int echoR();
	int echoL();
	char act();
	char led();
	int irL();
	int irR();
	int crashL();
	int crashR();
	int sensSpeed();
    void setSpeed(int speed);
    void setTurnAng(int turn_ang);
    void setEchoR(int echo_right);
	void setEchoL(int echo_left);
	void setAct(char action);
	void setLed(char led);
	void setIRL(int ir_left);
	void setIRR(int ir_right);
	void setCrashL(int crash_left);
	void setCrashR(int crash_right);
	void setSensSpeed(int speed);
  private:
    int _speed;
	int _sens_speed;
	int _turn_ang;
	int _echo_right;
	int _echo_left;
	int _ir_left;
	int _ir_right;
	int _crash_left;
	int _crash_right;
	char _action;
	char _led;
};

#endif