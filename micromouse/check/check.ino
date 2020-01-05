void setup() {
  // put your setup code here, to run once:
  /*for(int i = 2; i <= 7; i++)
    pinMode(i, OUTPUT);*/
  pinMode(10, OUTPUT);
  pinMode(3, OUTPUT);
  digitalWrite(10, HIGH);
  analogWrite(3, 60);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*for(int i = 0; i < 256; i++) {
    analogWrite(5, i);
    delay(100);  
  }*/
}
