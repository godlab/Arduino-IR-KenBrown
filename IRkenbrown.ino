/*
 * IRremote: IRsendDemo - demonstrates sending IR codes with IRsend
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

#define KenPower              0x10EFEB14
#define KenVolUp              0x10EFC13E
#define KenVolDown            0x10EF619E
#define bits        32

IRsend irsend;

void setup()
{
  Serial.begin(9600);
}

void loop() {
 // if (Serial.read() != -1) {
   //   irsend.sendNEC(0x10EFC13E, bits); // Sony TV power code
    
     //Serial.println("sended");
  //}
}


void serialEvent() {
 char inChar = (char)Serial.read(); 
if (inChar == 'A')
  {
          irsend.sendNEC(KenPower, bits); 
          Serial.println("sended ENCENDER");
  }
 

else if (inChar == 'B' )
  {
    irsend.sendNEC(KenVolUp, bits); 
    Serial.println("sended V0L +");
  }
else if (inChar == 'C' )
  {
    irsend.sendNEC(KenVolDown, bits); 
    Serial.println("sended VOL - ");
  }
}
