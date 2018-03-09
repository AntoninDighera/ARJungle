
/*  Code for testing servo motions for the JungleAR.
    Eventually there will 4 or 5 animated figures in the Jungle, They are:
      A snake on the jungle floor that snaps it's head out and then slowly recoils
      A jaguar peeking out from behind a tree and moving a paw in the understory
      A monkey swinging on a vine in the canopy
      A butterfly flittering beneath the canapy
      A bird toucan or parrot above the emergece
*/

#include <Servo.h>
#include <SoftwareSerial.h>

//SoftwareSerial BT(10, 11);  // bluetooth serial communication will happen on pin 10 and 11
//TX, RX respectively

// define a servo for each figure
Servo ServSnake;
Servo ServJaguar;
Servo ServMonkey;
Servo ServButterfly;
Servo ServBird;

//servo range is actually 30 degrees to 150 degrees
int pos = 0;
int minPos = 30;
int maxPos = 150;

//char variable named ‘state to store incoming message from bluetooth
char  state;

void setup() {
  // put your setup code here, to run once:

  //BT.begin(115200);      // baud rate for RN41 blueTooth chip
  // open the serial port:
  Serial.begin(9600);

  ServSnake.attach(8);
  ServJaguar.attach(9);
  ServMonkey.attach(12);
  ServButterfly.attach(13);

}

void loop() {
  // put your main code here, to run repeatedly:
  /* comment out code to read bluetooth
    while (BT.available())        //Check if there is an available byte to read
    {
      delay(10);                  //Delay added to make thing stable
      state = BT.read();         //Conduct a serial read
      Serial.println(state);      // debugging - see what was read
    }
  */
  // code to read char from serial monitor
  // check for incoming serial data:
  if (Serial.available() > 0) {
    // read incoming serial data: 
    state = Serial.read();
    // Echo the the value you received:
    Serial.println(state);
  }

  switch (state)
  {
    case ('1'):
      snake();
      break;
    case ('2'):
      jaguar();
      break;
    case ('3'):
      monkey();
      break;
    case ('4'):
      butterfly();
      break;
    default:
      Serial.println(state);
  }
}

void snake() {
  // head rises in a strike, then slowly recoils

  for (pos = minPos; pos < maxPos; pos += 1) {
    ServSnake.write(pos);
    delay(7);
  }
  for (pos = maxPos; pos >= minPos; pos -= 1) {
    ServSnake.write(pos);
    delay(30);
  }
}

void jaguar() {
  // slowly peeks out, faster back

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




