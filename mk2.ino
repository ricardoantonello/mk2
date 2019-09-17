//AUTOR RICARDO ANTONELLO ricardo@antonello.com.br

#include <Servo.h>
 
#define SERVO1 3 // PONTA DO BRACO : Porta Digital 6 PWM
#define SERVO2 5 // ASTE 1 : Porta Digital 6 PWM
#define SERVO3 6 // ASTE 2 : Porta Digital 6 PWM
#define SERVO4 9 // BASE DO BRACO : Porta Digital 6 PWM
 
Servo s1; // Variável Servo
Servo s2; // Variável Servo
Servo s3; // Variável Servo
Servo s4; // Variável Servo
int pos; // Posição Servo

void vai(Servo s, int a, int b){
  for(pos = a; pos < b; pos++)
  {
    s.write(pos);
    delay(15);
  }
}

void volta(Servo s, int a, int b){
  for(pos = b; pos > a; pos--)
  {
    s.write(pos);
    delay(15);
  }
}

void setup ()
{
  s1.attach(SERVO1);
  s2.attach(SERVO2);
  s3.attach(SERVO3);
  s4.attach(SERVO4);
  //Serial.begin(9600);
  //s1.write(0); // Inicia motor posição zero
}
 
void loop()
{
  for(int i=0; i<2; i++){
    vai(s1, 85, 170); // garra do braco 
    volta(s1, 85, 170);
    vai(s2, 85, 170); // motor lado esquerdo
    volta(s2, 85, 170);
    vai(s3, 60, 150); // motor lado direito
    volta(s3, 60, 150);
    vai(s4, 0, 100); // motor lado direito
    volta(s4, 0, 101.0);
  }
  delay(30000);
}
