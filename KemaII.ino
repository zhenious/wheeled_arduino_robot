//(c) https://vk.com/myrobotics

#include <KemaUS.h>
#include <KemaIR.h>
#include <KemaState.h>
#include <KemaDrive.h>
#include <KemaLED.h>
#include <KemaMem.h>
#include <VirtualWire.h>  //pin 11

  KemaDrive myDrive;
  KemaLED myLED(8,9,12);
  KemaState curState;
  KemaState prevState;
  KemaUS ultraSonic(22,23,24,25);  
  KemaIR myIR(30,31);
  KemaMem myMem;
  
  long prevTime = 0;
  long deltaTime = 0;
  int incomingByte = 0;
  boolean rfCtrl = true; 
  boolean past = false;
  char passRfCtrl[4] = {'k', 'e', 'm', 'a'};
  char act = '?';
  byte disallow = B00000000; // 0 - back. 1 - stop. 2 - forward.
  int speedInd = 0;
  
void setup()
{
    myLED.led('B');
  Serial.begin(9600);
    
    vw_set_ptt_inverted(true); // Required for DR3100
    vw_setup(2000);	 // Bits per sec
    vw_rx_start();  
    
}

void loop()
{
   if(rfCtrl)
     myLED.led('W');
   disallow = B00000000;
   prevTime = millis();
   uint8_t buf[VW_MAX_MESSAGE_LEN];
   uint8_t buflen = VW_MAX_MESSAGE_LEN;
      
  // ---------------------------------------------------- Sensor Section
  curState.setEchoR(ultraSonic.pingR());
  curState.setEchoL(ultraSonic.pingL());
  curState.setIRL(myIR.pingL());
  curState.setIRR(myIR.pingR());
     
  //----------------------------------------------------- RF control
    if (vw_get_message(buf, &buflen)) // Non-blocking
    {
	int i;
        char letter;
        boolean getSignal = false;
        for (i = 0; i < buflen-1; i++)
	{
	    letter = buf[i];
            if(letter != passRfCtrl[i])	 
                break;
            getSignal = true;    
	}
        letter = buf[buflen-1];
        if((getSignal)&&(letter == 'M'))
        {
            rfCtrl = !rfCtrl;
            //Serial.println("M"); 
           // Serial.println(rfCtrl);
        }
	if((rfCtrl)&&(getSignal))
        {
            
            //Serial.println(letter);
            switch (letter)
            {
              case 'S':
              curState.setAct('S'); 
              curState.setSpeed(0); 
              act = 'S';
              break;
              case 'B':
              curState.setAct('B');
              curState.setSpeed(curState.speed()-1); 
              act = 'B';
              break;
              case 'F':
              curState.setAct('F');    
              curState.setSpeed(curState.speed()+1);
              act = 'F';
              break;
              case 'R':
              curState.setAct('R');
              curState.setTurnAng(curState.turnAng() + 10);
              act = 'R';
              break;
              case 'L':
              curState.setAct('L');
              curState.setTurnAng(curState.turnAng() - 10);
              act = 'L';
              break;
              case 'W':
              curState.setAct('W');
              curState.setTurnAng(0);
              act = 'W';
              break;
              case 'P':
              past = true;
              break;
              
            }
           
        }
                  
    }   
  // ---------------------------------------------------- Smart Section
    if(past)
    {
       if(myMem.isNext())
       {
           curState.setSpeed(-myMem.getSpeed());
           curState.setTurnAng(myMem.getAngel());
           rfCtrl = false;
          // Serial.println(curState.turnAng());          
       }
       else
       {
          past = false;
          rfCtrl = true;
       }
    }
  
    curState.setLed('G');
    if((curState.echoR() < 300) && (curState.echoL() < 300)) //stop
    {
      if((curState.echoR() != 0) && (curState.echoL() != 0)) //forward
      {
          bitSet(disallow, 2); 
          curState.setLed('Y');
      }    
    }

    if((curState.irL() == 1)||(curState.irR() == 1)) //stop
    {
      bitSet(disallow, 2);
      curState.setLed('Y');
    }
    
    if((curState.echoR() < 150) && (curState.echoL() < 150)) //back
    {
      if((curState.echoR() != 0) && (curState.echoL() != 0)) //forward
      {
        bitSet(disallow, 1);
        curState.setLed('R');
      }  
    }
   
     if (Serial.available() > 0)
  {
     incomingByte = Serial.read();
     Serial.println("command");
     if (incomingByte == 52)
     {
       curState.setAct('L');
       curState.setTurnAng(curState.turnAng() - 10);
       act = 'L';
       Serial.println("left");
     }
     if (incomingByte == 53)
     {
        curState.setAct('W');
        curState.setTurnAng(0);
        act = 'W';
        Serial.println("stop");
     }
     if (incomingByte == 54)
     {
          curState.setAct('R');
          curState.setTurnAng(curState.turnAng() + 10);
          act = 'R';
          Serial.println("right");
     }

  }
  // ---------------------------------------------------- Drive Section
    if(past)
    {
       if(curState.speed() != prevState.speed()) 
          myDrive.move(curState.speed());
       if(curState.turnAng() != prevState.turnAng()) 
          myDrive.turn(curState.turnAng(), curState.speed());
  
    }
    if(rfCtrl)
    {
            switch (act)
            {
              case 'S':
                myDrive.stop();
              break;
              case 'B':
                myDrive.move(curState.speed());
              break;
              case 'F':
                myDrive.move(curState.speed());
             break;
              case 'R':
                myDrive.turn(curState.turnAng(), curState.speed());
              break;
              case 'L':
                myDrive.turn(curState.turnAng(), curState.speed()); 
               break;
            }
  
   }   
   else
   {
     if(!past)
     {
      if(!bitRead(disallow, 2))
         curState.setSpeed(1);
      else
      {
         if(!bitRead(disallow, 1))
              curState.setSpeed(0);
         else
         {
            if(!bitRead(disallow, 0))  
                curState.setSpeed(-1);     
            else
                curState.setSpeed(0);       
         }     
      } 
      myDrive.move(curState.speed());  
     }  
   }   
     
  // ---------------------------------------------------- Memory Section
  if(!past)
  {
      myMem.push(curState.speed(), curState.turnAng());
     
  }
  
  // --------------------------------------------------- Final Section
  act = '?';
  prevState = curState;
  deltaTime = millis() -  prevTime;
  if(past)
     myLED.led('B'); 
  else
     myLED.led(curState.led()); 
  if((deltaTime < 100)&&(deltaTime > 0))
       delay(100 - deltaTime);
  
  
}
