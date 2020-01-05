#define DIR_PIN1          2
#define STEP_PIN1         3
//#define ENABLE_PIN       4
#define DIR_PIN2          7
#define STEP_PIN2         4

#define STEP_HIGH1        PORTD |=  0b00001000;
#define STEP_LOW1         PORTD &= ~0b00001000;

#define STEP_HIGH2        PORTD |=  0b00010000;
#define STEP_LOW2         PORTD &= ~0b00010000;

#define TIMER1_INTERRUPTS_ON    TIMSK1 |=  (1 << OCIE1A);
#define TIMER1_INTERRUPTS_OFF   TIMSK1 &= ~(1 << OCIE1A);

unsigned int c0;
String rx = "";
volatile int count1 = 0, count2 = 0;
int trigPin = 8;
int echoPin = 12;
long duration, distance;
int x;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(STEP_PIN1,   OUTPUT);
  pinMode(DIR_PIN1,    OUTPUT);
  //pinMode(ENABLE_PIN, OUTPUT);
  pinMode(STEP_PIN2,   OUTPUT);
  pinMode(DIR_PIN2,    OUTPUT);
  digitalWrite(DIR_PIN1, HIGH);

  noInterrupts();
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;
  OCR1A = 1000;                             
  TCCR1B |= (1 << WGM12);
  TCCR1B |= ((1 << CS11) | (1 << CS10));
  interrupts();
  TIMER1_INTERRUPTS_ON

  c0 = 1600; // was 2000 * sqrt( 2 * angle / accel )
}
volatile unsigned long n1 = 173, n2 = 0;
volatile int flag1 = 0, flag2 = 0;
volatile int speedToReach1 = 400, speedToReach2 = 100, currentSpeed1 = 100, currentSpeed2 = 100, d1copy = 100, d2copy = 100;
volatile float d1 = 100, d2 = 100;
ISR(TIMER1_COMPA_vect)
{
   //Serial.println(flag);
   if(flag1 == 0){
     if(currentSpeed1 != speedToReach1){
      count1++;
      //Serial.println(count1);
     }
      //Serial.println(count1);
      STEP_HIGH1
      STEP_LOW1
      //Serial.println(micros());
      //Serial.println(micros());
      /*if(speedToReach == currentSpeed){
          n = 0;
      }*/
      //Ramp up phase   
      if(speedToReach1 < currentSpeed1){
          n1++;
          count1 = 0;
          d1 = d1 - (2 * d1) / (4 * n1 + 1);
          if(d1 < speedToReach1) {d1 = speedToReach1;}//avoiding overflow
          //d1copy = d1;
          //Serial.println(d);
      }
      //Ramp down phase
      //Serial.println(speedToReach + currentSpeed);
      if(speedToReach1 > currentSpeed1){
          n1--;
          count1 = 0;
          //Serial.println(d);
          d1 = (d1 * (4 * n1 + 1)) / (4 * n1 + 1 - 2);
          if(d1 > speedToReach1) {d1 = speedToReach1;}//avoiding overflow
          //d1copy = d1; 
           //Serial.println(d1); 
      }
      currentSpeed1 = d1;
      d1copy = d1;
      //Serial.println(millis());
      //Serial.print(" ");
      //Serial.println(22000000/(currentSpeed * 400));
      //yet to be coded
   }
   if(flag2 == 0){
      //Serial.println(micros());
      if(currentSpeed2 != speedToReach2){
      count2++;
     }
      //Serial.println(count2);
      STEP_HIGH2
      STEP_LOW2
      /*Serial.print("*");
      Serial.println(micros());*/
      /*if(speedToReach == currentSpeed){
          n = 0;
      }*/
      //Ramp up phase   
      if(speedToReach2 < currentSpeed2){
          n2++;
          count2 = 0;
          d2 = d2 - (2 * d2) / (4 * n2 + 1);
          if(d2 < speedToReach2) {d2 = speedToReach2;}//avoiding overflow
          //d2copy = d2;
          //Serial.println(d);
      }
      //Ramp down phase
      //Serial.println(speedToReach + currentSpeed);
      if(speedToReach2 > currentSpeed2){
          n2--;
          count2 = 0;
          //Serial.println(d);
          d2 = (d2 * (4 * n2 + 1)) / (4 * n2 + 1 - 2);
          if(d2 > speedToReach2) {d2 = speedToReach2;}//avoiding overflow
          //d2copy = d2; 
           //Serial.println(d); 
      }
      currentSpeed2 = d2;
      d2copy = d2;
      //Serial.println(millis());
      //Serial.print(" ");
      //Serial.println(22000000/(currentSpeed * 400));
      //yet to be coded
    }
    /*if(d1 < d2){
      //Serial.println(0);
      if(flag1 == 0 && flag2 == 1) {
        OCR1A = d1;
        flag2 = 1;
      }
      else {
        OCR1A = d2 - d1;
        flag1 = 0;
        flag2 = 1;
      }
    }
    else if(d1 > d2){
      if(flag2 == 0 && flag1 == 1) {
        OCR1A = d2;
        flag1 = 1;
      }
      else {
        OCR1A = d1 - d2;
        flag2 = 0;
        flag1 = 1;
      }
    }
    else {
        OCR1A = d1;
        flag1 = 0;
        flag2 = 0;
    }*/
    if(d1copy < d2copy) {
      OCR1A = d1copy;//Execute smallest d
      //flagging for smallest d
      flag1 = 0;
      flag2 = 1;
      d2copy = d2copy - d1copy;//restoring time algorithm
      //Serial.print(d2);
      //Serial.println(d2copy);
      //Serial.print(" ");  
    }
    else if(d2copy < d1copy) {
      OCR1A = d2copy;//Execute smallest d
      //flagging for smallest d
      flag2 = 0;
      flag1 = 1;
      d1copy = d1copy - d2copy;//restoring time algorithm
      //Serial.println(d1copy);
      //Serial.println(d1);  
    }
    else {
      //Serial.println(0);
      OCR1A = d1copy;//execute both
      //flagging
      flag1 = 0;
      flag2 = 0;
      //Serial.println(1);  
    }
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(0);
  if(Serial.available() > 0){
     char r = Serial.read();
     //Serial.println(0);
     if(r == '\n'){
        speedToReach1 = rx.toInt();
        //speedToReach2 = rx.toInt();
        //speedToReach2 = speedToReach1;
        //Serial.print(speedToReach1);
        rx = "";
      }
      else{
         rx = rx + r;
        }
  }
  Serial.print(currentSpeed1);
  Serial.print(" ");
  /*Serial.print(currentSpeed2);
  Serial.print(" ");*/
  Serial.println(currentSpeed2);
  //delay(1000);
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
  x = map(distance, 2, 400, 1600, 1);
  if(!(x < 0))
    speedToReach = x;
  if(x < 4)
    TIMER1_INTERRUPTS_OFF
  else
    TIMER1_INTERRUPTS_ON*/
  //Serial.println(n);
  //speedToReach = 1600;
}
