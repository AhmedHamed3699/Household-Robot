#pragma once

#include "Arduino.h"

class DishWasher{

private:
    byte pumbPin;
    byte drainPin;
    byte fanPin;

public:

    DishWasher(byte fanPin, byte pumbPin, byte drainPin){
        this->pumbPin = pumbPin;
        this->drainPin = drainPin;
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

    void startDrain(){
        digitalWrite(drainPin, HIGH);
    }

    void stopDrain(){
        digitalWrite(drainPin, LOW);
    }

    void setup(){
        pinMode(pumbPin, OUTPUT);
        pinMode(fanPin, OUTPUT);
        pinMode(drainPin, OUTPUT);
    }

    void loop(){
        // we can split functionalities here
    }
};



