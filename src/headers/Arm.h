#pragma once
#include "Arduino.h"
#include <Servo.h>

class Arm
{

  private:

    byte gripPin;
    byte rotationPin;
    byte upPin;
    byte downPin;
    Servo rotationServo;
    Servo gripServo;

  public:
  Arm(byte gripPin, byte rotPin, byte upPin, byte downPin)
    {
      this->gripPin = gripPin;
      this->rotationPin = rotPin;
      this->upPin = upPin;
      this->downPin = downPin;
    }

    setup(){
      pinMode(upPin, OUTPUT);
      pinMode(downPin, OUTPUT);
      rotationServo.attach(rotationPin);
      gripServo.attach(gripPin);
    }

    void up(){
      digitalWrite(upPin,HIGH);
      digitalWrite(downPin,LOW);
    }

    void down(){
      digitalWrite(upPin,LOW);
      digitalWrite(downPin,HIGH);
    }

    void stopLifting(){
      digitalWrite(upPin,LOW);
      digitalWrite(downPin,LOW);
    }

    void rotateBackward(){
      rotationServo.write(170);
    }

    void rotateForward(){
      rotationServo.write(20);
    }

    void grip(){
      gripServo.write(180);
    }

    void release(){
      gripServo.write(0);
    }

  void handleObject(bool toGrip)
  {
      down();
    delay(800);
      stopLifting();
      delay(800);
      (toGrip) ? grip() : release(); 
    delay(2000);
      up();
    delay(800);
      stopLifting();
    }
};