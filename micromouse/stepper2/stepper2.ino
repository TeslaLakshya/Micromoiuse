int stepPin = 5;
int dirPin = 6;
int trigPin = 10;
int echoPin = 9;
int dValue = 17.5;
long duration, distance; 
void setup() {
  // put your setup code here, to run once:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 400; i++) {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(500);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(500);
      //finding distance
      /*digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      //receive pulse
      duration = pulseIn(echoPin, HIGH);
      //find distance
      distance = (duration/2) * 0.0343;
      //mapping dValue
      dValue = 22000000/(distance%11 * 4000);*/
    }
    //delay(1000);

}
