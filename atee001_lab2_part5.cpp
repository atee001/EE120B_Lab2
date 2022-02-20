const int b0 = 2;
const int b1 = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(b0, OUTPUT);

  pinMode(b1, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1,INPUT);

  Serial.begin(9600);

}

void loop() {

digitalWrite(b0,LOW);
digitalWrite(b1, LOW);

if(digitalRead(A0) == HIGH && digitalRead(A1) == HIGH) {digitalWrite(b1,LOW);  digitalWrite(b0, LOW);}
else if (digitalRead(A1) == HIGH) digitalWrite(b1, HIGH);
else if(digitalRead(A0) == HIGH) digitalWrite(b0, HIGH);
else {digitalWrite(b0, LOW); digitalWrite(b1,LOW);}






}
