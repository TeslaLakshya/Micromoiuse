void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  //forward
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  for(int i = 0; i < 2000; i++) {
    digitalWrite(3, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    delayMicroseconds(100);
  }
  delay(1000);
  //20 steps backward
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  for(int i = 0; i < 2000; i++) {
    digitalWrite(3, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    delayMicroseconds(100);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
}
