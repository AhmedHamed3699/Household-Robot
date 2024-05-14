#include "headers/DishWasher.h"
#include "headers/Constants.h"
#include "headers/Crawler.h"
#include "headers/Arm.h"
DishWasher disher(fanPin, pumPin, drainPin);
Crawler crawler(leftForward, leftBackward, speedLeft, rightForward, rightBackward, speedRight);
Arm arm(gripPin, rotationPin, upPin, downPin);

int incomingByte = 0;

bool forwardsPressed = false;
bool backwardsPressed = false;
bool rightPressed = false;
bool leftPressed = false;
bool release = false; 

///============================
// Functions
void booksLiftingRoutine();
void booksDropRoutine();
///============================

void setup()
{
  crawler.setup();
  disher.setup();
  Serial.begin(9600);
  arm.setup();
  pinMode(13, OUTPUT);
}

void loop()
{

  //  if (Serial.available() > 0)
  {
    char c = (char)Serial.read();
    
    if (c == 'U')
    {
      crawler.forward();
    }
    else if (c == 'D')
    {
      crawler.backward();
    }
    else if (c == 'R')
    {
      crawler.right();
    }
    else if (c == 'L')
    {
      crawler.left();
    }
    else
    {
      crawler.stop();
      // digitalWrite(13, LOW);
    }

    if (c == 'Z')
    {
      arm.up();
    }
    else if (c == 'X')
    {
      arm.down();
    }
    else
    {
      arm.stopLifting();
    }

    if (c == 'E')
    {
      arm.rotateForward();
    }
    else if (c == 'T')
    {
      arm.rotateBackward();
    }
    if (c == 'G')
    {
      arm.grip();
      digitalWrite(13, HIGH);
    }
    else if (c == 'H')
    {
      arm.release();
      digitalWrite(13, LOW);
    }

    if (c == 'A')
    {
      arm.handleObject(!release);
      release = !release;
    }

    if (c == 'B') booksLiftingRoutine();
    else if (c == 'C') booksDropRoutine();
  }
  delay(100);
}

bool checkBook(){
  return true;
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