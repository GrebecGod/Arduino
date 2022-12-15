#define REC 2 // pin 2 is used for recording
#define PLAY_E 3
#define playTime 5000 // playback time 5 seconds
#define recordTime 3000 // recording time 3 seconds
#define playLTime 900
void setup() {
  // put your setup code here, to run once:
pinMode(13,OUTPUT);

Serial.begin(9600);
pinMode(REC,OUTPUT);// set the REC pin as output
//pinMode(PLAY_L,OUTPUT);// set the PLAY_L pin as output
pinMode(PLAY_E,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(13,LOW);
       char inChar = (char)Serial.read();
            if(inChar =='p' || inChar =='P'){
            digitalWrite(PLAY_E, HIGH);
            delay(50);
            digitalWrite(PLAY_E, LOW);  
              Serial.println("Playbak Started");  
            delay(playTime);
            
              Serial.println("Playbak Ended");
            
            }// if          
            else if(inChar =='r' || inChar =='R'){
              digitalWrite(REC, HIGH);
              Serial.println("Recording started");
              delay(recordTime);
              digitalWrite(REC, LOW);
              Serial.println("Recording Stopped ");              
            } 
                 
                        
    
Serial.println("**** Enter r to record, p to play");

  delay(500);
}
