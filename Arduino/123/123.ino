char incoming_value = 0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(10, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available()>0){
  incoming_value= Serial.read();
  Serial.print(incoming_value);
  Serial.print("\n");
  if (incoming_value=='1'){
    digitalWrite(10, HIGH);
    delay(500);
  }
  else if (incoming_value == '0')
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);
}
  else if (incoming_value=='2'){
    digitalWrite(9, HIGH);
    delay(500);
    }
  else if (incoming_value == '3'){
    digitalWrite(8, HIGH);
    delay(500);
}
  else if (incoming_value == '$'){
    exit(0);
}
}