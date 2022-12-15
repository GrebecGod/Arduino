/*
#include <SoftwareSerial.h> 
SoftwareSerial MyBlue(2, 3); // RX | TX 
int flag = 0; 
int LED = 8; 
void setup() 
{   
 Serial.begin(9600); 
 MyBlue.begin(9600); 
 pinMode(LED, OUTPUT); 
 Serial.println("Ready to connect\nDefualt password is 1234 or 000"); 
} 
void loop() 
{ 
 if (MyBlue.available()) 
   flag = MyBlue.read(); 
 if (flag == 1) 
 { 
   digitalWrite(LED, HIGH); 
   Serial.println("LED On"); 
 } 
 else if (flag == 0) 
 { 
   digitalWrite(LED, HIGH); 
   Serial.println("LED Off"); 
 } 
} 
*/
#include "SoftwareSerial.h"
SoftwareSerial MyBlue(2, 3); // RX | TX 
void setup() 
{ 
 Serial.begin(9600); 
 MyBlue.begin(38400);  //Baud Rate for AT-command Mode.  
 Serial.println("***AT commands mode***"); 
} 
void loop() 
{ 
 //from bluetooth to Terminal. 
 if (MyBlue.available()) 
   Serial.write(MyBlue.read()); 
 //from termial to bluetooth 
 if (Serial.available()) 
   MyBlue.write(Serial.read());
}