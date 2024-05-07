#include "headers/DishWasher.h"
#include "headers/Constants.h"
#include "headers/Crawler.h"

DishWasher disher(fanPin,pumPin);
Crawler crawler(leftForward,leftBackward,speedLeft,rightForward,rightBackward,speedRight);

void setup(){
  // disher.setup();
  // crawler.setup();
  pinMode(8, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop(){

  digitalWrite(8, HIGH);
  digitalWrite(11, LOW);
  analogWrite(6, 255);
  //digitalWrite(rightForward,HIGH);
  // digitalWrite(5, 2);
  // analogWrite(5, 255);
  // disher.startFan();
  // disher.startPumb();

  //crawler.backward();
}
