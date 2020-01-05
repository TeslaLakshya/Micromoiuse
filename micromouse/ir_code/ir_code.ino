int stepPin = 5;
void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  pinMode(stepPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 400; i++) {
    if(analogRead(A0) > 10) {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(17.5);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(17.5);
    }
  }
}
