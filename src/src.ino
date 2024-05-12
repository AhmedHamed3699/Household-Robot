#include "headers/DishWasher.h"
#include "headers/Constants.h"
#include "headers/Crawler.h"
#include "headers/Arm.h"
DishWasher disher(fanPin,pumPin);
Crawler crawler(leftForward,leftBackward,speedLeft,rightForward,rightBackward,speedRight);
Arm arm(gripPin,rotationPin,upPin,downPin);


int incomingByte = 0;

bool forwardsPressed = false;
bool backwardsPressed = false;
bool rightPressed = false;
bool leftPressed = false;

void setup() {
  crawler.setup();
  disher.setup();
  Serial.begin(9600);
  arm.Init();
  pinMode(13, OUTPUT);
}

void loop() {
    
 // if (Serial.available() > 0)
   {
    char c = (char)Serial.read();
    Serial.println(c);
    if(c == 'U'){
      crawler.forward();
    }else if(c == 'D'){
      crawler.backward();
    }else if(c == 'R'){
      crawler.right();
    }else if(c == 'L'){
      crawler.left();
    }else{
      crawler.stop();
     // digitalWrite(13, LOW);
    }

     if(c == 'Z'){
       arm.up();
     }else if(c == 'X'){
       arm.down();
     }else{ 
      arm.stopLifting();}

     if(c == 'E'){
       arm.rotateDown();
     }else if(c == 'T'){
       arm.rotateUp();
      }
    if(c == 'G'){
      arm.grip();
      digitalWrite(13, HIGH);
    }else if(c == 'H'){
      arm.release();
      digitalWrite(13, LOW);
    }
 


  }
  delay(100);
}
