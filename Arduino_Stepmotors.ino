#include <NewPing.h>
NewPing sonar (6, 7, 20);
#define A 2
#define B 3
#define C 4
#define D 5
 
#define NUMBER_OF_STEPS_PER_REV 512

int TOP = 6;
int BOTTOM= 7;

void setup(){
pinMode(A,OUTPUT);
pinMode(B,OUTPUT);
pinMode(C,OUTPUT);
pinMode(D,OUTPUT);
pinMode(BOTTOM, INPUT);
pinMode(TOP, INPUT);
Serial.begin(9600);
}

void write(int a,int b,int c,int d){
digitalWrite(A,a);
digitalWrite(B,b);
digitalWrite(C,c);
digitalWrite(D,d);
}

void stepforward(){
write(1,0,0,0);
delay(5);
write(1,1,0,0);
delay(5);
write(0,1,0,0);
delay(5);
write(0,1,1,0);
delay(5);
write(0,0,1,0);
delay(5);
write(0,0,1,1);
delay(5);
write(0,0,0,1);
delay(5);
write(1,0,0,1);
delay(5);
}

void stepbackward() {
write(1,0,0,1);
delay(5);
write(0,0,0,1);
delay(5);
write(0,0,1,1);
delay(5);
write(0,0,1,0);
delay(5);
write(0,1,1,0);
delay(5);
write(0,1,0,0);
delay(5);
write(1,1,0,0);
delay(5);
write(1,0,0,0);
delay(5);
}



void loop(){
while (int(sonar.ping_cm()) < 10 & int(sonar.ping_cm()) != 0) {
  stepforward();
}
}


