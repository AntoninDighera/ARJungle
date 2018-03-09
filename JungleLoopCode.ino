// code to run continous motions
#include <Servo.h>
Servo ServSloth;

//servo range is actually 30 degrees to 150 degrees
int pos = 0;
int minPos = 30;
int maxPos = 150;

void setup() {
  // put your setup code here, to run once:

  ServSloth.attach(9);

}

void loop() {
  // put your main code here, to run repeatedly:
  sloth();
  delay(1000);
  // Could add others here
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
