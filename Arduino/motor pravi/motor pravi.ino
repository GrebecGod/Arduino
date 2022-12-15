#include <Stepper.h>
int stepsPerRevolituon=2048;
int motSpeed=10;
Stepper myStepper(stepsPerRevolituon, 9, 10, 11, 12);
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
myStepper.setSpeed(motSpeed);
}

void loop() {
  // put your main code here, to run repeatedly:
myStepper.step(stepsPerRevolituon);
delay(500);
myStepper.step(-stepsPerRevolituon);
delay(500);
}
