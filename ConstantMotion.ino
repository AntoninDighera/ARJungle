/* code to run 3 leaf servos and one sloth in a continuious loop */
#include <Servo.h>
#include <SoftwareSerial.h>
Servo ServSloth;  // on Pin 8
Servo ServLeaf1;  // on Pin 9
Servo ServLeaf2;  // on Pin 10
Servo ServLeaf3;  // on Pin 11
//servo range is actually 30 degrees to 150 degrees
int pos = 0;
int minPos = 30;
int maxPos = 150;
int slothMax = 20;  //time delay between sloth moves
int slothTimer = 0; //  count up to slothMax;
int spos = minPos;
int forward = 0;  // direction of sloth servo

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ServSloth.attach(8);
  ServLeaf1.attach(9);
  ServLeaf2.attach(10);
  ServLeaf3.attach(11);
}

void loop() {
  int delta = 10; //leaf delay: bigger number means slower motion
  int forward = 1;

  for (pos = minPos; pos < maxPos; pos += 1) {
    // move leaves
    ServLeaf1.write(pos);
    delay(delta);
    ServLeaf2.write(pos);
    delay(delta);
    ServLeaf3.write(pos);
    delay(delta);
          // Check to see if it is time to move sloth
    sloth();
  }
    // reverse direction
  for (pos = maxPos; pos > minPos; pos -= 1) {
    ServLeaf1.write(pos);
    delay(delta);
    ServLeaf2.write(pos);
    delay(delta);
    ServLeaf3.write(pos);
    delay(delta);
    // Check to see if it is time to move sloth
    sloth();
  }
}

void sloth () {
  
  slothTimer += 1; 
  if (slothTimer == slothMax) {
    ServSloth.write(spos);
    if (spos == maxPos ) {
      forward = 0;    //go back
    }
    if (spos == minPos) {   // go forward
      forward = 1;
    }
    if (forward == 1) {
      spos += 1;
    } else {
      spos -= 1;
    }
    slothTimer = 0;     // reset delay
  }
}





