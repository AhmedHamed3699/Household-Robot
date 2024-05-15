#include "headers/DishWasher.h"
#include "headers/Constants.h"
#include "headers/Crawler.h"
#include "headers/Arm.h"

DishWasher disher(fanPin, pumPin, drainPin);
Crawler crawler(leftForward, leftBackward, speedLeft, rightForward, rightBackward, speedRight);
Arm arm(gripPin, rotationPin, upPin, downPin);


///============================
// Functions
void booksLiftingRoutine();
void booksDropRoutine();
///============================

void setup()
{
  crawler.setup();
  // disher.setup();
  // arm.setup();
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(vacuumPin, OUTPUT);
  analogWrite(9,210);
  analogWrite(10,210);
}

void loop()
{
  delay(10000);
  snakePattern();
}

enum State {
  FORWARD,
  STOP,
  TURN_RIGHT,
  FORWARD_SHORT,
  TURN_LEFT,
};

State currentState = FORWARD;

void snakePattern()
{

  crawler.setSpeed(230, 233);
  bool firstTurn = true;
  bool turnRight = true;
  bool turnLeft = true;
  // int delays[] = {}
  for(int i = 0; i < 1000; i++)
  {
    // if(serialAvailable())
    // {
    //   char c = (char)Serial.read();p

    //   if(c == 'S')
    //   {
    //     break;
    //   }
    // }
    switch (currentState)
    {
      case FORWARD:
        digitalWrite(vacuumPin, HIGH);
        crawler.forward();
        delay(4000);
        crawler.backward();
        delay(4000);
        crawler.forward();
        delay(4000);
        crawler.stop();
        delay(400);
        if(firstTurn){
          currentState = TURN_RIGHT;
        }
        else{
          currentState = TURN_LEFT;
        }
        break;

      case TURN_RIGHT:
        digitalWrite(vacuumPin, LOW);
        crawler.right();
        delay(860+ ((i<3) ? i*85: 250));
        crawler.stop();
        delay(400);
        if(turnRight){
          currentState = FORWARD_SHORT;
        }
        else{
          currentState = FORWARD;
        }
        turnRight = !turnRight;
        break;

      case FORWARD_SHORT:
        crawler.forward();
        delay(1000);
        crawler.stop();
        delay(400);
        if(firstTurn){
          currentState = TURN_RIGHT;
        }
        else{
          currentState = TURN_LEFT;
        }
        firstTurn = !firstTurn;
        break;

      case TURN_LEFT:
        digitalWrite(vacuumPin, LOW);
        crawler.left();
        delay(860+ ((i<3) ? i*85: 250));
        crawler.stop();
        delay(400);
        if(turnLeft){
          currentState = FORWARD_SHORT;
        }
        else{
          currentState = FORWARD;
        }
        turnLeft = !turnLeft;
        break;
    }
  }
}

void booksLiftingRoutine()
{

  //Todo:  Make the lifting discrete levels





  //Todo:  Check book is lifted during forwarding
  //Todo:  

  arm.down();
  delay(800);
  arm.stopLifting();
  delay(200);
  arm.rotateForward();
  delay(300);
  crawler.forward();
  delay(1500);
  crawler.stop();
  delay(500);
  arm.rotateBackward();
  delay(500);
  arm.up();
  delay(900);
  arm.stopLifting();

  

  // arm.rotateForward();
  // arm.down();
  // crawler.forward();
  // // while (1)
  // // {
  // //   delay(50);
  // //   if (bookLifted())
  // //   {
  // //     break;
  // //   }
  // // }
  // delay(2000);
  // crawler.stop();
  // arm.rotateBackward();
  // arm.up();
}

void booksDropRoutine()
{
  arm.down();
  arm.rotateForward();
  crawler.backward();
  delay(1000);
}