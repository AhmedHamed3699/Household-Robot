#pragma once

#include "Arduino.h"

class DishWasher{

private:
    byte pumbPin;
    byte fanPin;

public:

    DishWasher(byte pumbPin, byte fanPin){
        this->pumbPin = pumbPin;
        this->fanPin = fanPin;
    }

    void startFan(){
        digitalWrite(fanPin, HIGH);
    }

    void stopFan(){
        digitalWrite(fanPin, LOW);
    }

    void startPumb(){
        digitalWrite(pumbPin, HIGH);
    }

    void stopPumb(){
        digitalWrite(pumbPin, LOW);
    }

    void setup(){
        pinMode(pumbPin, OUTPUT);
        pinMode(fanPin, OUTPUT);
    }

    void loop(){
        // we can split functionalities here
    }
};



