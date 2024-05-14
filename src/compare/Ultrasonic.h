#pragma once

#include "Arduino.h"

class Ultrasonic{
    private :
        byte echoPin;
        byte trigPin;
        long duration;
        int distance;
    public:
        Ultrasonic(byte echoPin,byte trigPin){
            this->echoPin = echoPin;
            this->trigPin = trigPin;
        }
        void setup(){
            pinMode(trigPin, OUTPUT);
            pinMode(echoPin, INPUT);
        }
        int getDistance(){
            digitalWrite(trigPin, LOW);
            delayMicroseconds(2);
            digitalWrite(trigPin, HIGH);
            delayMicroseconds(10);
            digitalWrite(trigPin, LOW);
            duration = pulseIn(echoPin, HIGH);
            distance= duration*0.034/2;
            return distance;
        }
}