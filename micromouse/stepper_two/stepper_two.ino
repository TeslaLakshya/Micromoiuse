int stepPin1 = 5;
int stepPin2 = 6;
int dirPin1 = 7;
int dirPin2 = 9;
void setup() {
  // put your setup code here, to run once:
  pinMode(stepPin1, OUTPUT);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  digitalWrite(dirPin1, LOW);
  digitalWrite(dirPin2, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 400; i++) {
      digitalWrite(stepPin1, HIGH);
      digitalWrite(stepPin2, HIGH);
      //delayMicroseconds(50);
      digitalWrite(stepPin1, LOW);
      digitalWrite(stepPin2, LOW);
      delayMicroseconds(90);
    }
}
