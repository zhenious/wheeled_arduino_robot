// (c) https://vk.com/myrobotics

#ifndef KemaDrive_h
#define KemaDrive_h

#include "Arduino.h"

class KemaDrive
{
  public:
    KemaDrive();
    void move(int speed);     
    void turn(int ang, int curSpeed);	
    void stop();

  private:
    int _in11;
	int _in12;
	int _in21;
	int _in22;
    int _in31;
	int _in32;
	int _in41;
	int _in42;
	int _enB1;
	int _enA1;
	int _enB2;
	int _enA2;
	
	void turnReset(int curSpeed);
	void movFwdL(int fwd_speed);
	void movBckL(int bck_speed);
	void movFwdR(int fwd_speed);
	void movBckR(int bck_speed);
	

};

#endif