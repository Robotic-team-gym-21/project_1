
#include<Servo.h>
int IN3=7;
int IN4=6;


int IN1=9;
int IN2=8;
int SPEED=210;
int trigPin=11;
int echoPin=12;
int duration;
int distance;

int servoPin1=2;
Servo s1;
int servoPin2=3;
Servo s2;

void setup() {
  // put your setup code here, to run once:
  s1.attach(servoPin1);
  s2.attach(servoPin2);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);


  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  Serial.begin(9600);
  s2.write(0);
  s1.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delay(20);
  digitalWrite(trigPin, HIGH);
  delay(50);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance=duration*0.034/2;
  s2.write(2);
  s1.write(2);
 
 
  
  if (distance>=49){
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    s2.write(2);
    s1.write(2);

    }
  if (distance<49){

  
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    delay(300);
    
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    s1.write(150);
    delay(2000);
 
    s2.write(150);
    
    delay(300);
    s1.write(0);
    
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);

    delay(1000);
    
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);

    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    
    delay(300);
  
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    
  
  }

}

