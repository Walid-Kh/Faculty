#define M0 2
#define M1 3
#define MSpeed 5
#define TempPort A2


void setup() {
  pinMode(M0, OUTPUT);
  pinMode(M1, OUTPUT);
  pinMode(MSpeed, OUTPUT);
  Serial.begin(9600); 
}

void loop() {
  int Vout = analogRead(TempPort);
  float R2 = 10000*((1023.0f/Vout)-1); 
  float T = 1/((1.0092e-03) + (2.3784e-04)*log(R2) + (2.0192e-07)*pow(log(R2), 3));
  T -= 273; 
  if (T >= 0 && T < 50)
  {
    digitalWrite(M0, LOW);
    digitalWrite(M1, LOW);
  }
  else if (T >= 51 && T < 100)
  {
    digitalWrite(M0, LOW); 
    digitalWrite(M1, HIGH); 
    analogWrite(MSpeed, 255*0.5); 
  } 
  else if (T > 100) {
    digitalWrite(M0, HIGH); 
    digitalWrite(M1, LOW); 
    analogWrite(MSpeed, 254); 
  }

  Serial.println(Vout); 
  Serial.println(R2);
  Serial.println(T);
  delay(500);
}
