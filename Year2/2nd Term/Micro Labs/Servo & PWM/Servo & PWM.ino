#include <Servo.h>
#define ServoPin 6
int bcdPins[] = { 8, 9, 10, 11 };
int segmentPins[] = { 2, 3, 4, 5 };
Servo servo;
void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(bcdPins[i], INPUT);
    pinMode(segmentPins[i], OUTPUT);
  }
  pinMode(ServoPin, OUTPUT);
  servo.attach(ServoPin, 1000, 2000);
  Serial.begin(9600);
}

void loop() {
  int bcdValue = 0;
  for (int i = 0; i < 4; i++) {
    bcdValue += (digitalRead(bcdPins[i]) << i);
  }
  if (bcdValue > 9) {
    bcdValue = 9;
    Serial.println("bcd Value exceeds 9");
  }
  servo.write(bcdValue * 20);
  for (int i = 0; i < 4; i++) {
    digitalWrite(segmentPins[i], ((bcdValue >> i) & 0x01));
  }
  delay(500);
}
