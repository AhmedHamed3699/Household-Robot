#include "Arduino.h"
#include <Servo.h>


class Arm{

  private:

    byte gripPin;
    byte rotationPin;
    byte upPin;
    byte downPin;
    Servo rotationServo;
    Servo gripServo;

  public:

    Arm(byte gripPin,byte rotPin,byte upPin,byte downPin) 
    {
      this->gripPin = gripPin;
      this->rotationPin = rotPin;
      this->upPin = upPin;
      this->downPin = downPin;
    }

    Init(){
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
      rotationServo.write(90);
    }

    void rotateForward(){
      rotationServo.write(180);
    }

    void grip(){
      gripServo.write(0);
    }

    void release(){
      gripServo.write(180);
    }

    void handleObject(void (*action)()){
      down();
      delay(500);
      stopLifting();
      delay(800);
      action();
      delay(800);
      up();
      delay(900);
      stopLifting();
    }
};