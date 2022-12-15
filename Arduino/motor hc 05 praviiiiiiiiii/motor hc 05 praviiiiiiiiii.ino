#include <Stepper.h>
#include <Servo.h>
Servo myservo;
char incoming_value=0;
int stepsPerRevolituon=2048;
int motSpeed=10;
char o;
int servowrite;
Stepper myStepper(stepsPerRevolituon, 9, 10, 11, 12);
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
myStepper.setSpeed(motSpeed);
myservo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available()>0){
  incoming_value= Serial.read();
  Serial.print(incoming_value);
  Serial.print("\n");
  while (incoming_value=='m'){
    o= Serial.read();    
    myStepper.step(stepsPerRevolituon);
    Serial.println(o);
    if (o =='s')
      incoming_value=o;
  
  }
  if (incoming_value=='s')
    myStepper.step(0);
  else if (incoming_value=='x'){
    servowrite=incoming_value;
    myservo.write(servowrite);

  }
}
}
