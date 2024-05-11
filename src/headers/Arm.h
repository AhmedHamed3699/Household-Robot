#include "Arduino.h"
#include <Servo.h>


class Arm{

  private:

    byte gripPin;
    byte rotationPin;
    byte upPin;
    byte downPin;
    Servo myservo;

  public:

    Arm(byte gripPin,byte rotPin,byte upPin,byte downPin) 
    {
      this->gripPin = gripPin;
      this->rotationPin = rotPin;
      this->upPin = upPin;
      this->downPin = downPin;
    }

    Init(){
      pinMode(gripPen, OUTPUT);
      pinMode(upPin, OUTPUT);
      pinMode(downPin, OUTPUT);
      myservo.attach(rotationPin);
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

    void rotateDown(){
      myservo.write(90);
    }

    void rotateUp(){
      myservo.write(180);
    }
};