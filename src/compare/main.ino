#include "DIshWasher.h"
#include "Constants.h"
#include "Crawler.h"
#include "Arm.h"

DishWasher disher(fanPin,pumPin,drainPin);
Crawler crawler(leftForward,leftBackward,speedLeft,rightForward,rightBackward,speedRight);
Arm arm(gripPin,rotationPin,upPin,downPin);
Ultrasonic ultrasonic(echoPin,trigPin);

int incomingByte = 0;

bool forwardsPressed = false;
bool backwardsPressed = false;
bool rightPressed = false;
bool leftPressed = false;
bool lifted = false;


void detectKeyPresses() {
  if (incomingByte == FORWARDS_PRESSED) {
      forwardsPressed = true;
    }
    else if (incomingByte == BACKWARDS_PRESSED) {
      backwardsPressed = true;
    }

    if (incomingByte == FORWARDS_RELEASED) {
      forwardsPressed = false;
    }
    else if (incomingByte == BACKWARDS_RELEASED) {
      backwardsPressed = false;
    }

    if (incomingByte == RIGHT_PRESSED) {
      rightPressed = true;
    }
    else if (incomingByte == LEFT_PRESSED) {
      leftPressed = true;
    }

    if (incomingByte == RIGHT_RELEASED) {
      rightPressed = false;
    }
    else if (incomingByte == LEFT_RELEASED) {
      leftPressed = false;
    }
}

void handlePinOutputs() {
  if (forwardsPressed == true) {
    crawler.forward();
  }
  else {
    crawler.stop();
  }

  if (backwardsPressed == true) {
    crawler.backward();
  }
  else {
    crawler.stop();
  }

  if (rightPressed == true) {
    crawler.right();
  }
  else {
    crawler.stop();
  }

  if (leftPressed == true) {
    crawler.left();
  }
  else {
    crawler.stop();
  }
}



bool bookLifted(){
  return ultrasonic.getDistance() < 5;
}

void navigateToBook()
{
  if(Serial.available()>0){
    char command = Serial.read();
    if (command == 'bw') {
      digitalWrite(LED_BUILTIN,HIGH);
      crawler.forward();
      delay(300);
      crawler.stop();
    }
    if (command == 'bp') {
        crawler.stop();
        arm.booksLiftingRoutine();
        lifted = true;
    }
    if (command == 'bd') {
          crawler.right();
          delay(50);
          crawler.stop();
    }
    if (command == 'ba') {
          crawler.left();
          delay(50);
          crawler.stop();
    }
    Serial.flush();
  }
  
}

void navigateToMouse()
{
  if(Serial.available()>0){
    char command = Serial.read();
    if (command == 'mw') {
      digitalWrite(LED_BUILTIN,HIGH);
      crawler.forward();
      delay(300);
      crawler.stop();
    }
    if (command == 'mp') {
        crawler.stop();
        arm.booksDropRoutine();
        lifted = false;
    }
    if (command == 'md') {
          crawler.right();
          delay(50);
          crawler.stop();
    }
    if (command == 'ma') {
          crawler.left();
          delay(50);
          crawler.stop();
    }
    Serial.flush();
  }
  
}


void setup() {
  crawler.setup();
  disher.setup();
  ultrasonic.setup();
  Serial.begin(9600);
  arm.setup();
}

void loop() {
  // if (Serial.available() > 0) {
    
  //   char c = (char)Serial.read();
  //   Serial.println(c);
  //     digitalWrite(13, HIGH);
  //   if(c == 'U'){
  //     crawler.forward();
  //   }else if(c == 'D'){
  //     crawler.backward();
  //   }else if(c == 'R'){
  //     crawler.right();
  //   }else if(c == 'L'){
  //     crawler.left();
  //   }else{
  //     crawler.stop();
  //     digitalWrite(13, LOW);
  //   }

  //   if(c == 'z'){
  //     arm.up();
  //   }else if(c == 'x'){
  //     arm.down();
  //   }else arm.stopLifting();

  //   if(c == 'r'){
  //     arm.rotateDown();
  //   }else if(c == 't'){
  //     arm.rotateUp();
  //   }



  // }
  // delay(100);

  if(lifted){
    navigateToMouse();
  }else{
    navigateToBook();
  }

}