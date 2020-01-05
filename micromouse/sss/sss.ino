int trigPin = 9; 
int echoPin = 10; 

void setup()
{  
pinMode(trigPin, OUTPUT); //Sensor
pinMode(echoPin, INPUT); //Sensor  
pinMode(6,OUTPUT); // Enable
pinMode(13,OUTPUT); // Step
pinMode(12,OUTPUT); // Dir
digitalWrite(6,LOW); // Set Enable low
digitalWrite(5,LOW); // Set Step low
Serial.begin(9600);
} 

void loop()
{  
//rotateleft();
//Serial.println("ik draai nu exact een rotatie linksom");
//delay(1000);
//rotateright();
//Serial.println("ik draai nu exact een rotatie rechtsom");
//delay(1000);
//velocity();

 //sensor
 long duration, distance;
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(5);
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 distance = (duration/2) / 29.1;
 Serial.print ("cm ");
 Serial.print (distance);

//eigen creatie

if (distance > 30) 
{
  digitalWrite(6,HIGH); // Output high   
  delayMicroseconds(500); // Wait   
  digitalWrite(6,LOW); // Output low   
  delayMicroseconds(500); // Wait 
}

if (distance > 20 && distance < 30)
{
  digitalWrite(6,HIGH); // Output high   
  delayMicroseconds(2000); // Wait   
  digitalWrite(6,LOW); // Output low   
  delayMicroseconds(2000); // Wait
}

if (distance > 10 && distance < 20)
{
  digitalWrite(6,HIGH); // Output high   
  delayMicroseconds(10000); // Wait   
  digitalWrite(6,LOW); // Output low   
  delayMicroseconds(10000); // Wait
}

if (distance > 1 && distance < 10)
{
  //digitalWrite(6,HIGH); // Output high   
  //delayMicroseconds(1000); // Wait   
  digitalWrite(6,LOW); // Output low   
}
}
