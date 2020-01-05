/*int trigPin = 8;
int echoPin = 12;
long duration, distance;*/
String rx = "";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  /*pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);*/
  TCCR1A = 0;
  TCCR2A = 0;
  TCCR1B = 0;
  TCCR2B = 0;
  TCCR1A |= (1 << WGM10)|(1 << COM1A1)|(1 << COM1B1);
  TCCR1B |= (1 << WGM12)|(1 << CS11) | (1 << CS10);
  OCR1A = 50;
  OCR1B = 50;
}

/*ISR(TIMER1_COMPA_vect){
  Serial.println(millis());
}

ISR(TIMER1_COMPB_vect){
  Serial.println(millis());
}*/

void loop() {
  if(Serial.available() > 0){
     char r = Serial.read();
     if(r == '\n'){
        int i = rx.toInt();
        Serial.println(i);
        OCR1A = i;
        OCR1B = i;
        rx = "";
      }
      else{
         rx = rx + r;
        }
  }
  // put your main code here, to run repeatedly:
  //clean
  /*digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  //send pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  //receive pulse
  duration = pulseIn(echoPin, HIGH);
  //find distance
  distance = (duration/2) * 0.0343;
  OCR1A = map(distance, 2, 10, 1, 254);
  OCR1B = map(distance, 2, 10, 1, 254);
  Serial.println(OCR1A);
  //delay(100);
  // put your main code here, to run repeatedly:*/

}
