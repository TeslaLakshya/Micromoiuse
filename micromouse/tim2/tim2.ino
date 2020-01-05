volatile unsigned int n1 = 0;
volatile unsigned int speedToReach1 = 50, currentSpeed1 = 255;
volatile float d1 = 255;
String rx = "";
volatile int count1 = 0;
#define TIMER1_INTERRUPTS_ON    TIMSK1 |=  (1 << OCIE1A);
#define TIMER1_INTERRUPTS_OFF   TIMSK1 &= ~(1 << OCIE1A);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  TCCR2A = _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);
  TCCR2B = _BV(WGM22) | _BV(CS22);
  TCCR0A = _BV(COM0B1) | _BV(WGM01) | _BV(WGM00);
  TCCR0B = _BV(WGM02) | _BV(CS01) | _BV(CS00);
  OCR2A = 255;
  OCR2B = 1;//smoothness
  OCR0A = 50;
  OCR0B = 1;//smoothness
  noInterrupts();
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;
  OCR1A = 100;                             
  TCCR1B |= (1 << WGM12);
  TCCR1B |= ((1 << CS11) | (1 << CS10));
  interrupts();
  TIMER1_INTERRUPTS_ON
}

ISR(TIMER1_COMPA_vect)
{
   //Serial.println(flag);
     if(currentSpeed1 != speedToReach1){
      count1++;
      //Serial.println(count1);
     }
      //Serial.println(count1);
      //Serial.println(micros());
      /*if(speedToReach == currentSpeed){
          n = 0;
      }*/
      //Ramp up phase   
      if(speedToReach1 < currentSpeed1 && count1 == 400){
          n1++;
          count1 = 0;
          d1 = d1 - (2 * d1) / (4 * n1 + 1);
          /*Serial.print(d1);
          Serial.print(" ");
          Serial.println(n1);*/
          if(d1 < speedToReach1) {d1 = speedToReach1;}//avoiding overflow
          //n1++;
          //d1copy = d1;
          //Serial.println(d);
      }
      //Ramp down phase
      //Serial.println(speedToReach + currentSpeed);
      if(speedToReach1 > currentSpeed1 && count1 == 400){
          n1--;
          count1 = 0;
          //Serial.println(d);
          d1 = (d1 * (4 * n1 + 1)) / (4 * n1 + 1 - 2);
          if(d1 > speedToReach1) {d1 = speedToReach1;}//avoiding overflow
          //n1--;
          //d1copy = d1; 
           //Serial.println(d); 
      }
      //Serial.println(d1);
      //Serial.print(" ");
      currentSpeed1 = d1;
      //OCR1A = d1;
      OCR2A = d1;
      //Serial.println(OCR2A);
      //Serial.println(millis());
      //Serial.print(" ");
      //Serial.println(22000000/(currentSpeed * 400));
      //yet to be coded
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
     char r = Serial.read();
     //Serial.println(0);
     if(r == '\n'){
        speedToReach1 = rx.toInt();
        //speedToReach2 = speedToReach1;
        Serial.print(speedToReach1);
        Serial.println(":");
        rx = "";
      }
      else{
         rx = rx + r;
        }
  }
  /*Serial.print(currentSpeed1);
  Serial.print(" ");
  Serial.print(speedToReach1);
  Serial.print(" ");
  Serial.println(n1);*/

  //previous isr
  //Serial.println(flag);
     /*if(currentSpeed1 != speedToReach1){
      count1++;
      //Serial.println(count1);
     }
      //Serial.println(count1);
      //STEP_HIGH1
      //STEP_LOW1
      //Serial.println(micros());
      /*if(speedToReach == currentSpeed){
          n = 0;
      }***
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
          //Serial.println(d1);
          d1 = (d1 * (4 * n1 + 1)) / (4 * n1 + 1 - 2);
          //d1copy = d1; 
           //Serial.println(d); 
      }
      currentSpeed1 = d1;
      OCR2A = d1;
      Serial.println(OCR2A);*/
}
