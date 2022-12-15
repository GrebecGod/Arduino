#include <IRremote.hpp>
// #define one F30CFF00;

int pinl=13, in=7, read;

      const int one = 4077715200;
void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
IrReceiver.begin(7, 9);


// pinMode(13, OUTPUT);
pinMode(9, OUTPUT);
pinMode(4, OUTPUT);
pinMode(7, INPUT);
// pinMode(in, INPUT);
}

void loop() {
// #define one F30CFF00;
if (IrReceiver.decode()) {
      Serial.println(IrReceiver.decodedIRData.decodedRawData);
      // IrReceiver.printIRResultShort(&Serial); // optional use new print version
      switch(IrReceiver.decodedIRData.decodedRawData) {
        case 4077715200: //1
        digitalWrite(9, HIGH);
        delay(750);
        digitalWrite(9, LOW);
        break;
        case 3877175040: //2
        digitalWrite(3, HIGH);
        delay(750);
        digitalWrite(3, LOW);        
        break;
        case 2707357440: //3
        digitalWrite(4, HIGH);
        delay(750);
        digitalWrite(4, LOW);        
        break;
      }

      IrReceiver.resume();

      // delay(1000);
    
    
    
    // switch(results.value, DEC) {
    //   case 16724175:
    //   Serial.println(69);
    //   break;
    // }





  }
// read=digitalRead(7);
// digitalWrite(13,LOW);

}