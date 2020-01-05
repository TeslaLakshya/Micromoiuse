#include <SPI.h>
volatile unsigned int Slavereceived;
volatile bool process;
volatile byte x = 0, high, low;
#define DIR_PIN1          2
#define STEP_PIN1         3
//#define ENABLE_PIN       4

#define STEP_HIGH1        PORTD |=  0b00001000;
#define STEP_LOW1         PORTD &= ~0b00001000;

#define TIMER1_INTERRUPTS_ON    TIMSK1 |=  (1 << OCIE1A);
#define TIMER1_INTERRUPTS_OFF   TIMSK1 &= ~(1 << OCIE1A);

unsigned int c0;
//String rx = "";
volatile int count1 = 0;
/*int trigPin = 8;
int echoPin = 12;
long duration, distance;*/
//int x;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
   pinMode(MISO, OUTPUT); // have to send on master in so it set as output
   SPCR |= _BV(SPE); // turn on SPI in slave mode
   //indx = 0; // buffer empty
   process = false;
   SPI.attachInterrupt(); // turn on interrupt;
   pinMode(STEP_PIN1,   OUTPUT);
  pinMode(DIR_PIN1,    OUTPUT);
  //pinMode(ENABLE_PIN, OUTPUT);

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

ISR (SPI_STC_vect)
{
  //Serial.println(micros());
  if(x == 0) {
    high = SPDR;
    //Serial.println(high);
    x = 1;
  }
  else {
    x = 0;
    low = SPDR;
    //Serial.println(low);
    Slavereceived = high*256 + low;
    //Serial.println(Slavereceived);
    process = true;
    //Serial.println(micros());
  }
  //Serial.println(micros());
  //Serial.println(0);                                         
}
volatile unsigned long n1 = 0;
volatile unsigned int speedToReach1 = 100, currentSpeed1 = 1600;
volatile float d1 = 1600;
ISR(TIMER1_COMPA_vect)
{
   //Serial.println(flag);
     if(currentSpeed1 != speedToReach1){
      count1++;
      //Serial.println(count1);
     }
      //Serial.println(count1);
      STEP_HIGH1
      STEP_LOW1
      //Serial.println(micros());
      /*if(speedToReach == currentSpeed){
          n = 0;
      }*/
      //Ramp up phase   
      if(speedToReach1 < currentSpeed1 && count1 == 20){
          n1++;
          count1 = 0;
          d1 = d1 - (2 * d1) / (4 * n1 + 1);
          //d1copy = d1;
          //Serial.println(d);
      }
      //Ramp down phase
      //Serial.println(speedToReach + currentSpeed);
      if(speedToReach1 > currentSpeed1 && count1 == 20){
          n1--;
          count1 = 0;
          //Serial.println(d);
          d1 = (d1 * (4 * n1 + 1)) / (4 * n1 + 1 - 2);
          //d1copy = d1; 
           //Serial.println(d); 
      }
      currentSpeed1 = d1;
      OCR1A = d1;
      //Serial.println(millis());
      //Serial.print(" ");
      //Serial.println(22000000/(currentSpeed * 400));
      //yet to be coded
      //Serial.println(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(process) {
    speedToReach1 = Slavereceived;
    process = false;
    Serial.println(speedToReach1);
  }

}
