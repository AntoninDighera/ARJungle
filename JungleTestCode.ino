
/*  Code for testing servo motions for the JungleAR.
    Eventually there will 4 or 5 animated figures in the Jungle, They are:
      A snake on the jungle floor that snaps it's head out and then slowly recoils
      A jaguar peeking out from behind a tree and moving a paw in the understory
      A sloth in the understory moving veerryy slowly
      A monkey swinging on a vine in the canopy
      A butterfly flittering beneath the canapy
      A bird toucan or parrot above the emergece
*/

#include <Servo.h>
// define a servo for each figure
Servo ServSnake;
Servo ServSloth;
Servo ServJaguar;
Servo ServMonkey;
Servo ServButterfly;
Servo ServBird;

//servo range is actually 30 degrees to 150 degrees

int pos = 0;
int minPos = 30;
int maxPos = 150;


void setup() {
  // put your setup code here, to run once:

  /* for testing purposes we attach 1 servo to pin 9 and then uncomment
      the declaration for the motion we wish to test
      In the final code each servo will be attached to its own pin
  */

  //ServSnake.attach(9);
  //ServSloth.attach(9);
  //ServJaguar.attach(9)
  //ServMonkey.attach(9);
  //ServButterfly.attach(9);

}

void loop() {
  // put your main code here, to run repeatedly:
  /* For testing uncomment the motion you wnat test
   * The final code will read a character from the blueTooth chip and execute  
   * the code for the animal that was requested. e.g if a 1 is read, snake() is executed, 
   * if 2, then sloth(), etc.
   * The character is sent by the controling phone app when a button with the picture of desired 
   * animal is clicked on,
   */
  //snake();
  //sloth();
  //jaguar();
  //monkey();
  //butterfly();

}

void snake() {
  // head snaps out in a strike, then slowly recoils
  
  for (pos = minPos; pos < maxPos; pos += 1) {
    ServJaguar.write(pos);
    delay(2);
  }
  for (pos = maxPos; pos >= minPos; pos -= 1) {
    ServJaguar.write(pos);
    delay(20);
  }
}
void sloth() {
  // the sloth moves slowly so the delay time is long
  for (pos = 100; pos < maxPos; pos += 1) {
    ServSloth.write(pos);
    delay(100);
  }

  for (pos = maxPos; pos >= 100; pos -= 1) {
    ServSloth.write(pos);
    delay(100);
  }
}

void jaguar() {
  // slowly peeks out, faster back
  // Do we want to move the head and paw together?
  
  for (pos = minPos; pos < maxPos; pos += 1) {
    ServJaguar.write(pos);
    delay(30);
  }
  for (pos = maxPos; pos >= minPos; pos -= 1) {
    ServJaguar.write(pos);
    delay(10);
  }
}

void monkey() {
  for (pos = minPos; pos < maxPos; pos += 1) {
    ServMonkey.write(pos);
    delay(20);
  }
  for (pos = maxPos; pos >= minPos; pos -= 1) {
    ServMonkey.write(pos);
    delay(20);
  }
}
void butterfly() {
  // We want a fluttery (fast and jerkey) motion
  // TODO let's try increasing the increment on pos and see what happens
  
  for (pos = minPos; pos < maxPos; pos += 1) {
    ServButterfly.write(pos);
    delay(3);
  }
  for (pos = maxPos; pos >= minPos; pos -= 1) {
    ServButterfly.write(pos);
    delay(3);
  }
}




