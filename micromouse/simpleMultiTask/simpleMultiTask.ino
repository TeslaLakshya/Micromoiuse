#include <Metro.h> 

const int trigPin = 10;
const int echoPin = 9;
int stepPin = 5;
int dirPin = 6;
long duration, distance;

boolean trigPinState = false;
boolean echoPinState = false;
boolean stepPinState = false;

Metro ultrasonic_Metro = Metro(0.01);
Metro stepper_Metro = Metro(0.0175);


void setup(){
  Serial.begin(9600);
  pinMode(trigPin , OUTPUT);
  pinMode(echoPin , INPUT);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
}


void loop(){

  if(ultrasonic_Metro.check()){
    trigPinState = !trigPinState;
    digitalWrite(trigPin, trigPinState);
    if(trigPinState == false) {
      long duration = pulseIn(echoPin, HIGH);
      distance = (duration/2) * 0.0343;
      Serial.print(distance);
      Serial.println("cm");
    }
  }

  stepper_Metro = Metro(22000/ (distance%11 * 4000));
  if(stepper_Metro.check()){
    stepPinState = !stepPinState;
    digitalWrite(stepPin, stepPinState);
  }
  
}
