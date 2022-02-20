const int b0 = 2;

void setup() {
   put your setup code here, to run once
  pinMode(b0, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);

}

void loop() {

  digitalWrite(b0, LOW);


  if(digitalRead(A0) == HIGH){

    Serial.print(HIGH);
    digitalWrite(b0, HIGH);

   }

   else {
    Serial.print(LOW);
    digitalWrite(b0, LOW);
   }



}
