const int b0 = 2;
const int b1 = 3;
const int b2 = 4;
const int b3 = 5;
const int b4 = 6;
const int b5 = 7;
const int b6 = 8;
const int b7 = 9;

void writeToB(unsigned char temp)
{

if ((temp>>7) & 0x01){digitalWrite(b7,HIGH);}
if ((temp>>6) & 0x01){digitalWrite(b6,HIGH);}
if ((temp>>5) & 0x01){digitalWrite(b5,HIGH);}
if ((temp>>4) & 0x01){digitalWrite(b4,HIGH);}
if ((temp>>3) & 0x01){digitalWrite(b3,HIGH);}
if ((temp>>2) & 0x01){digitalWrite(b2,HIGH);}
if ((temp>>1) & 0x01){digitalWrite(b1,HIGH);}
if (temp & 0x01){digitalWrite(b0,HIGH);}
}

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(b0, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(b2, OUTPUT);
  pinMode(b3, OUTPUT);
  pinMode(b4, OUTPUT);
  pinMode(b5, OUTPUT);
  pinMode(b6, OUTPUT);
  Serial.begin(9600);
}

int readA(){
  int result = 0;
  if(digitalRead(A0)){
    result += 1;
  }
  if(digitalRead(A1)){
    result += 2;
  }
  if(digitalRead(A2)){
    result += 4;
  }
  if(digitalRead(A3)){
    result += 8;
  }

  return result;

}
//0000
void resetB()
{
digitalWrite(b7,LOW);
digitalWrite(b6,LOW);
digitalWrite(b5,LOW);
digitalWrite(b4,LOW);
digitalWrite(b3,LOW);
digitalWrite(b2,LOW);
digitalWrite(b1,LOW);
digitalWrite(b0,LOW);
}
void loop() {


  resetB();
  if(readA() > 12 && readA() < 16){
      writeToB(63);
  }
  else if(readA() > 9){
      writeToB(62);
  }
  else if(readA() > 6){
    writeToB(60);
  }
  else if(readA() > 4){
    writeToB(56);
  }
  else if(readA() > 2){
    writeToB(112);
  }
  else if(readA() > 0){
    writeToB(96);
  }
  else if(readA() == 0){
   writeToB(64);
   }
  else{
    writeToB(0);
    Serial.print("Error Analog input A produced: ");
    Serial.println(readA());
  }

}
