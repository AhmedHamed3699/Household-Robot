#pragma once

#include "Arduino.h"

class Wheel{
  private:
    byte speedPin;
    byte pinOne;
    byte pinTwo;
    byte speed;

  public:

    Wheel(){

    }

    Wheel(byte speedPin,byte pinOne, byte pinTwo){
      this->speedPin = speedPin;
      this->pinOne = pinOne;
      this->pinTwo = pinTwo;
      this->speed = 0;
    }

    void Init(byte speed){
      // pinMode(speedPin, OUTPUT);
      pinMode(pinOne, OUTPUT);
      pinMode(pinTwo, OUTPUT);
      // setSpeed(speed);
    }

    void forward(){
      digitalWrite(pinOne, HIGH);
      digitalWrite(pinTwo, LOW); 
    }

    void backward(){
      digitalWrite(pinOne, LOW);
      digitalWrite(pinTwo, HIGH); 
    }

    void stop(){
      digitalWrite(pinOne, LOW);
      digitalWrite(pinTwo,LOW);
    }

    void setSpeed(int speed){
      analogWrite(speedPin, speed);
    }

};

class Crawler{

  private:
    Wheel leftWheel;
    Wheel rightWheel;

  public:

    Crawler(byte upL, byte backL, byte speedL, byte upR, byte backR, byte speedR)
    {
      leftWheel = Wheel(speedL, upL, backL);
      rightWheel = Wheel(speedR,upR,backR);
    }

    void setup(){
      // TODO: changing 255 to 180, causes a problem
      leftWheel.Init(255);
      rightWheel.Init(255);
    }

    void forward(){
      leftWheel.forward();
      rightWheel.forward();
    }

    void backward(){
      leftWheel.backward();
      rightWheel.backward();
    }

    void left(){
      leftWheel.forward();
      rightWheel.backward();
    }

    void right(){
      rightWheel.forward();
      leftWheel.backward();
    }

    void stop(){
      rightWheel.stop();
      leftWheel.stop();
    }

    void setSpeed(byte speedRight, byte speedLeft){
      leftWheel.setSpeed(speedLeft);
      rightWheel.setSpeed(speedRight);
    }

};