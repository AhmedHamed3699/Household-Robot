#include "Arduino.h"


class Arm{

  private:

    byte gripPen;
    byte rotationPen;
    byte upPin;
    byte downPin;

  public:

    Arm(byte gripPen,byte rotPen,byte upPin,byte downPin) 
    {
      this->gripPen = gripPen;
      this->rotationPen = rotationPen;
      this->upPin = upPin;
      this->downPin = downPin;
    }

    Init(){
      pinMode(gripPen, OUTPUT);
      pinMode(upPin, OUTPUT);
      pinMode(downPin, OUTPUT);
      pinMode(rotationPen, OUTPUT);
    }


}