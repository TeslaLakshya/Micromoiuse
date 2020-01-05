#define reading A0
unsigned int value;
int stepPin = 5, delVal;
//int x = 100;
void setup() {
// put your setup code here, to run once:
pinMode(reading,INPUT);
pinMode(stepPin, OUTPUT);
Serial.begin(9600);
}

void loop() {
// put your main code here, to run repeatedly:
value = analogRead(reading);
float raw_voltage = value*0.00488;
delVal = map(raw_voltage, 0, 5, 250, 100);
Serial.println(raw_voltage);
/*value = analogRead(reading);
      float raw_voltage = value*0.00488;
      delVal = map(raw_voltage, 0, 5, 100, 20);*/
      /*value = analogRead(reading) * 0.00488;
      //delVal = map(value, 0, 5, 100, 15);
      int x = 500 - (121.5 * value);
      Serial.println(x);*/
for(int i = 0; i < 400; i++) {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(500);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(500);
      //Serial.print(1);
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
    /*if(x != 14)
        x--;*/
