#pragma once

const int FORWARDS_PRESSED = 1;
const int FORWARDS_RELEASED = 2;
const int BACKWARDS_PRESSED = 131;
const int BACKWARDS_RELEASED = 4;
const int RIGHT_PRESSED = 133;
const int RIGHT_RELEASED = 134;
const int LEFT_PRESSED = 7;
const int LEFT_RELEASED = 8;

enum PINS{

  // DishWasher
  fanPin = 6,
  // TODO change this pin, the gripper already take it
  pumPin = 13,
  drainPin = A2,

  //left wheel

  leftForward = 8,
  leftBackward = 7,

  //right wheel

  rightForward = 11,
  rightBackward = 12,

  //speed

  speedLeft = 10,
  speedRight = 9,

  //ARM

  gripPin = 5,
  rotationPin = 3,
  
  upPin = 4,
  downPin = 2,

  //Ultrasonic
  echoPin = A1,
  trigPin = A0,

  //Vacuum
  vacuumPin = A3

};