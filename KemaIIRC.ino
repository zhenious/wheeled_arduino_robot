 #include <VirtualWire.h>
 
       int VRx;
       int VRy;
       int SW;
       int adc_key_val [5] = {1, 140, 300, 490, 710};
       int key = -1;
       unsigned long curTime;
       char act, prevAct;
       char *msg = "kema";
void setup() {                

  Serial.begin(9600);  
   vw_set_ptt_inverted(true); // Required for DR3100
   vw_setup(2000);	 // Bits per sec

}

// the loop routine runs over and over again forever:
void loop()
{
       
       VRx = analogRead(0);
       
       if(VRx < 200) 
       {
          act = 'L';
          msg = "kemaL";
          curTime = millis();
       }   
       if(VRx > 800) 
       {
          act = 'R';
          msg = "kemaR";
          curTime = millis();
       }
       VRy = analogRead(1);
       //Serial.println(VRy);
       if(VRy < 200) 
       {
          act = 'F';
          msg = "kemaF";
          curTime = millis();
       }   
       if(VRy > 800) 
       {
          act = 'B';
          msg = "kemaB";
          curTime = millis();
       }
       
       key = get_key (analogRead (3));
       switch (key)
       {
          case 0: 
            act = 'M';
            msg = "kemaM";
            curTime = millis();
          break;
          case 1: 
          
          break;
          case 2: 
             
          break;
          case 3: 
            act = 'P';
            msg = "kemaP";
            curTime = millis();
          break;
          case 4: 
            act = 'S';
            msg = "kemaS";
            curTime = millis();
          break;
      }
                
       if(prevAct != act)  
       {     
           //Serial.println(act);  
           vw_send((uint8_t *)msg, strlen(msg));
           vw_wait_tx(); 
       }    
       if(( millis() - curTime) > 500)
            act = '?';
      
       prevAct = act;
       delay(200);
}

int get_key (unsigned int input)
{
   int k;
   int delta;
   if(input != 1023)
       Serial.println(input);
   for (k = 0; k < 5; k++)
   {
      delta = input - adc_key_val [k];
      if (abs(delta) < 40)
             return k;
       
   }
   if (k >= 5) k = -1; // No valid key pressed
   return k;
}
