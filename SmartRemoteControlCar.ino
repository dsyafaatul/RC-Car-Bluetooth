/*
 * created by dsyafaatul
 * dikisyafaatul@gmail.com
 * */
int IN1 = 2;
int IN2 = 3;
int IN3 = 4;
int IN4 = 5;
int ENA = 6;
int ENB = 9;
int LED = 7;
int pinTrigger1 = 8;
int pinEcho1 = 9;
int minimumRange = 30;
long duration, distance;
int speedRX = 180;
int speedValue[10] = {0,100,120,140,160,180,200,220,240,255};
char btRX;
boolean statusLED = HIGH;
boolean autoMode = false;
void setup() {
Serial.begin(38400);
Serial.println("Smart Remote Control Car Bluetooth");
Serial.println("Kelompok 1 : 12RPL - PUI Majalengka");
pinMode(IN1,OUTPUT);
pinMode(IN2,OUTPUT);
pinMode(IN3,OUTPUT);
pinMode(IN4,OUTPUT);
pinMode(ENA,OUTPUT);
pinMode(ENB,OUTPUT);
pinMode(LED,OUTPUT);
pinMode(pinTrigger1,OUTPUT);
pinMode(pinEcho1,INPUT);
digitalWrite(LED,statusLED);
}

void loop() {
digitalWrite(pinTrigger1, LOW);
if(Serial.available()){
while(Serial.available() > 0){
  btRX = Serial.read();
}
Serial.println(btRX);
Serial.println(speedRX);
  switch(btRX){
  case 'W':
      digitalWrite(IN1,HIGH);
      digitalWrite(IN2,LOW);
    break;
  case 'S':
      digitalWrite(IN1,LOW);
      digitalWrite(IN2,HIGH);
    break;
  case 'Q':
      digitalWrite(IN1,LOW);
      digitalWrite(IN2,LOW);
    break;
  case 'A':
      digitalWrite(IN3,HIGH);
      digitalWrite(IN4,LOW);
    break;
  case 'D':
      digitalWrite(IN3,LOW);
      digitalWrite(IN4,HIGH);
    break;
  case 'E':
      digitalWrite(IN3,LOW);
      digitalWrite(IN4,LOW);
    break;
  case 'Z':
      statusLED = !statusLED;
      digitalWrite(LED,statusLED);
    break;
  case 'X':
      statusLED = !statusLED;
      digitalWrite(LED,statusLED);
      delay(500);
      statusLED = !statusLED;
      digitalWrite(LED,statusLED);
    break;
  case 'C':
      autoMode = !autoMode;
      if(!autoMode){
        digitalWrite(IN1,LOW);
        digitalWrite(IN2,LOW);
        digitalWrite(IN3,LOW);
        digitalWrite(IN4,LOW);
      }
  break;
  case '0':
      speedRX = speedValue[0];
  break;
  case '1':
      speedRX = speedValue[1];
  break;
  case '2':
      speedRX = speedValue[2];
  break;
  case '3':
      speedRX = speedValue[3];
  break;
  case '4':
      speedRX = speedValue[4];
  break;
  case '5':
      speedRX = speedValue[5];
  break;
  case '6':
      speedRX = speedValue[6];
  break;
  case '7':
      speedRX = speedValue[7];
  break;
  case '8':
      speedRX = speedValue[8];
  break;
  case '9':
      speedRX = speedValue[9];
  break;
  }
}
delay(100);
if(autoMode){
    digitalWrite(pinTrigger1, LOW); delayMicroseconds(2);
  digitalWrite(pinTrigger1, HIGH); delayMicroseconds(10);
  digitalWrite(pinTrigger1, LOW);
  duration = pulseIn(pinEcho1, HIGH);
  distance = duration*0.034/2;
  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.println("cm");
  if (distance <= minimumRange)
  {
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
    delay(1500);
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);
    delay(1500);
  }else{
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,LOW);
  }
}
//for(speedValue = 0; speedValue < 255; speedValue+=51){
//  analogWrite(ENA, speedValue);
//  Serial.println(speedValue);
//  delay(500);
//}
analogWrite(ENA, speedRX);
delay(10);
}
