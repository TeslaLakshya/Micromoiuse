int trigPin = 10;
int echoPin = 9;
int initDistance;
long duration, distance;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  //send pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  //receive pulse
  duration = pulseIn(echoPin, HIGH);
  //find distance
  distance = (duration/2) * 0.0343;
  Serial.print(distance);
  Serial.println("cm");
  initDistance = distance;
}

void loop() {
  // put your main code here, to run repeatedly:
  //clean
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  //send pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  //receive pulse
  duration = pulseIn(echoPin, HIGH);
  //find distance
  distance = (duration/2) * 0.0343;
  Serial.print(distance);
  Serial.println("cm");
  delay(10);
}
