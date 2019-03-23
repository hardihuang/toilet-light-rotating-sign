
#include <Servo.h>
Servo myservo;  // create servo object to control a servo
int photocellPin = 1;
int photocellReading;
int lightOnValue = 200;
int lightOffValue = 400;

int peopleState = false;
int ledRelay = 10;

void setup() {
  myservo.attach(3);  // attaches the servo on GIO2 to the servo object
  Serial.begin(9600);
  myservo.write(0);
}

void loop() {
  int pos;
  photocellReading = analogRead(photocellPin);
  Serial.println(photocellReading);
  delay(100);
  if(photocellReading > lightOffValue && peopleState == true){//dark
    peopleState = false;
    //servo to 0
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
  }else if(photocellReading < lightOnValue && peopleState == false){//light on
    peopleState = true;
    //servo to 180
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
  }

/*
  
  
  */
}

