int chPin = 10;
int switchPin1 = 2, switchPin2 = 3;
int data;
void setup() {
  // put your setup code here, to run once:
  pinMode(chPin, INPUT);
  pinMode(switchPin1, OUTPUT);
  pinMode(switchPin2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  data = pulseIn(chPin, HIGH);
  if(data == 0) {
    digitalWrite(switchPin1, HIGH);
    digitalWrite(switchPin2, HIGH);
  }
  else {
    digitalWrite(switchPin1, LOW);
    digitalWrite(switchPin2, LOW);  
  }
}
