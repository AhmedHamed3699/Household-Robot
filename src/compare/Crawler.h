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
      pinMode(speedPin, OUTPUT);
      pinMode(pinOne, OUTPUT);
      pinMode(pinTwo, OUTPUT);
      setSpeed(speed);
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

    void setSpeed(byte speed){

      if(speed < 0){
        analogWrite(speedPin, this->speed);
        return;
      }

      if(speed > 255){
        speed = 255;
      }

      this->speed = speed;
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
      leftWheel.Init(180);
      rightWheel.Init(180);
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

};