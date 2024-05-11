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
  arm.setup();
}

void loop() {
  if (Serial.available() > 0) {
    
    char c = (char)Serial.read();
    Serial.println(c);
      digitalWrite(13, HIGH);
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
      digitalWrite(13, LOW);
    }

    if(c == 'z'){
      arm.up();
    }else if(c == 'x'){
      arm.down();
    }else arm.stopLifting();

    if(c == 'r'){
      arm.rotateDown();
    }else if(c == 't'){
      arm.rotateUp();
    }


  }
  delay(100);
}
