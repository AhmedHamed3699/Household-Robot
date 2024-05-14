#pragma once
#include "Arduino.h"
#include "Crawler.h"
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

  setup()
  {
    pinMode(upPin, OUTPUT);
    pinMode(downPin, OUTPUT);
    digitalWrite(13, HIGH);
    delay(3000);
    digitalWrite(13, LOW);
    rotationServo.attach(rotationPin);
    delay(1000);
    digitalWrite(13, HIGH);
    delay(3000);
    digitalWrite(13, LOW);
    // gripServo.attach(gripPin);
  }

  void up()
  {
    digitalWrite(upPin, HIGH);
    digitalWrite(downPin, LOW);
  }

  void down()
  {
    digitalWrite(upPin, LOW);
    digitalWrite(downPin, HIGH);
  }

  void stopLifting()
  {
    digitalWrite(upPin, LOW);
    digitalWrite(downPin, LOW);
  }

  void rotateBackward()
  {
    rotationServo.write(90);
  }

  void rotateForward()
  {
    rotationServo.write(180);
  }

  void grip()
  {
    gripServo.write(0);
  }

  void release()
  {
    gripServo.write(180);
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

  void booksLiftingRoutine(Crawler &crawler)
  {
    rotateForward();
    down();
    crawler.forward();
    // while (1)
    // {
    //   delay(50);
    //   if (bookLifted())
    //   {
    //     break;
    //   }
    // }
    delay(2000);
    crawler.stop();
    rotateBackward();
    up();
  }

  void booksDropRoutine(Crawler &crawler)
  {
    down();
    rotateForward();
    crawler.backward();
    delay(1000);
  }
};