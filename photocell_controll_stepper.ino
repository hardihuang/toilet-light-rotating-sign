#include "Stepper.h"

//stepper setting
#define STEPS  32   // Number of steps per revolution of Internal shaft
int  Steps2Take;  // 2048 = 1 Revolution
Stepper small_stepper(STEPS,3, 5, 4, 6);

//photocell setting
int photocellPin = 3;
int photocellReading;
int lightOnValue=200;

//global setting
int peopleState = false;
int ledRelay = 10;

void setup(){
  Steps2Take = 1024;
  pinMode(ledRelay,OUTPUT);
  digitalWrite(ledRelay,1); //turn of the relay
  //Serial.begin(9600);
}

void loop(){
   photocellReading = analogRead(photocellPin);
   //Serial.println(photocellReading);

   if(photocellReading > lightOnValue && peopleState ==false){ //toilet light on
      peopleState = true;
      small_stepper.setSpeed(700); //Max seems to be 700
      small_stepper.step(Steps2Take);
      delay(800);
      digitalWrite(ledRelay,0);
   }else if(photocellReading < lightOnValue && peopleState ==true){ //toilet light off
      delay(5000);
      peopleState = false;
      small_stepper.setSpeed(700); //Max seems to be 700
     
      digitalWrite(ledRelay,1);
      small_stepper.step(-Steps2Take);
      
   }
}
