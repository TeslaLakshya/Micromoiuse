volatile unsigned long n1 = 0, n2 = 0;
volatile int speedToReach1 = 20, speedToReach2 = 20, currentSpeed1 = 255, currentSpeed2 = 255;
volatile float d1 = 255, d2 = 255;
String rx = "";
volatile int count1 = 0, count2 = 0, accelVal = 100;
int trigPin = 4, echoPin = 2;
#define TIMER1_INTERRUPTS_ON    TIMSK1 |=  (1 << OCIE1A);
#define TIMER1_INTERRUPTS_OFF   TIMSK1 &= ~(1 << OCIE1A);
void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  //pinMode(4, INPUT);//for sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  TCCR2A = _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);
  TCCR2B = _BV(WGM22) | _BV(CS22);
  TCCR0A = _BV(COM0B1) | _BV(WGM01) | _BV(WGM00);
  TCCR0B = _BV(WGM02) | _BV(CS01) | _BV(CS00);
  OCR2A = 255;
  OCR2B = 1;//smoothness
  OCR0A = 255;
  OCR0B = 1;//smoothness
  noInterrupts();
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;
  OCR1A = 100;                             
  TCCR1B |= (1 << WGM12);
  TCCR1B |= ((1 << CS11) | (1 << CS10));
  interrupts();
  /*for(int i = 0; i < 20; i++) {
    digitalWrite(*/
  TIMER1_INTERRUPTS_ON
}

ISR(TIMER1_COMPA_vect)
{
     /*if(digitalRead(4) == HIGH) {
        speedToReach1 = 255;
        speedToReach2 = 255;
        //accelVal = 20;
    }*/
     if(currentSpeed1 != speedToReach1){
      count1++;
     }   
      if(speedToReach1 < currentSpeed1 && count1 == accelVal){
          n1++;
          count1 = 0;
          d1 = d1 - (2 * d1) / (4 * n1 + 1);
          if(d1 < speedToReach1) {d1 = speedToReach1;}
      }
      if(speedToReach1 > currentSpeed1 && count1 == accelVal){
          n1--;
          count1 = 0;
          d1 = (d1 * (4 * n1 + 1)) / (4 * n1 + 1 - 2);
          if(d1 > speedToReach1) {d1 = speedToReach1;} 
      }
      currentSpeed1 = d1;
      OCR0A = d1;
      if(currentSpeed2 != speedToReach2){
      count2++;
     }   
      if(speedToReach2 < currentSpeed2 && count2 == accelVal){
          n2++;
          count2 = 0;
          d2 = d2 - (2 * d2) / (4 * n2 + 1);
          if(d2 < speedToReach2) {d2 = speedToReach2;}
      }
      if(speedToReach2 > currentSpeed2 && count2 == accelVal){
          n2--;
          count2 = 0;
          d2 = (d2 * (4 * n2 + 1)) / (4 * n2 + 1 - 2);
          if(d2 > speedToReach2) {d2 = speedToReach2;} 
      }
      currentSpeed2 = d2;
      OCR2A = d2;
}

void loop() {
  /*if(Serial.available() > 0){
     char r = Serial.read();
     //Serial.println(0);
     if(r == ' '){
        speedToReach1 = rx.toInt();
        //speedToReach2 = speedToReach1;
        Serial.print(speedToReach1);
        Serial.print(" ");
        rx = "";
      }
      else if(r == '\n') {
        speedToReach2 = rx.toInt();
        Serial.println(speedToReach2);
        rx = "";  
      }
      else{
         rx = rx + r;
        }
  }*/
  /*if(currentSpeed1 == 20 && currentSpeed2 == 20) {
      speedToReach1 = 255;
      speedToReach2 = 255;
    }*/
    long duration, distance;
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(5);
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 distance = (duration/2) / 29.1;
 //Serial.println(distance);

 if(distance <= 18) {
  speedToReach1 = 255;
  speedToReach2 = 255;
  accelVal = 5;
  }
}
