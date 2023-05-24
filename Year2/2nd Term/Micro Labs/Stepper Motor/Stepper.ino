#include <Stepper.h>
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5
#define DirectionPin 7

Stepper stepper (200, IN1, IN2, IN3, IN4); 
int speed = 0; 

void setup() {
  pinMode(IN1, OUTPUT); 
  pinMode(IN2, OUTPUT); 
  pinMode(IN3, OUTPUT); 
  pinMode(IN4, OUTPUT); 
  pinMode(DirectionPin, INPUT); 
  Serial.begin(9600); 
  while (!Serial.available()) {}
  speed = Serial.parseInt();
}

void loop() {
  int potentiometer = analogRead(A2); 
  int val = map(potentiometer, 0, 1023, 0, 200);
  bool direction = digitalRead(DirectionPin);  
  stepper.setSpeed(speed);
  stepper.step(direction? val : 0 - val); 
  Serial.print("speed : "); 
  Serial.println(speed); 
  Serial.print("direction : "); 
  Serial.println(direction? "CW" : "CCW"); 
  Serial.print("Steps : ");
  Serial.println(val); 
  Serial.println(""); 
  delay(2000); 
}
