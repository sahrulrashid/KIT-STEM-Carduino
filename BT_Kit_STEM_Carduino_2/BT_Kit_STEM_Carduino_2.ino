
#include<stdio.h>
#include<SoftwareSerial.h>
// BTSerial (Rx, Tx); Based on the Aduno board
SoftwareSerial bt(2, 3);

//left wheel
int pwm1 = 6;
int in1 = 7;
int in2 = 8;

//right wheel
int pwm2 = 9;
int in3 = 10;
int in4 = 11;

char data = 'S';
char prevdata = 'A';
int manmode(char data);
int vel = 255;


void setup() {
  //left wheel
  pinMode(pwm1, OUTPUT); //PWM-Pin
  pinMode(in1, OUTPUT); //IN1-Pin
  pinMode(in2, OUTPUT); //IN2-Pin
  //right wheel
  pinMode(pwm2, OUTPUT); //PWM-Pin
  pinMode(in3, OUTPUT); //IN1-Pin
  pinMode(in4, OUTPUT); //IN2-Pin
  //bluetooth
  bt.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
  char data;
  data = bt.read();
  manmode(data);
}

int manmode(char data)
{
  switch (data)
  {
    case 'F': front(); break;
    case 'B': rear(); break;
    case 'L': left(); break;
    case 'R': right(); break;
    case 'S' : brake(); break;
    case 'I' : rightfwd(); break;
    case 'J' : rightback(); break;
    case 'G' : leftfwd(); break;
    case 'H' : leftback(); break;
  }
}

void rightfwd()
{
  nav(vel, vel/2);

  return ;
}
void rightback()
{
  rev(vel, vel/2);
  return ;
}
void leftfwd()
{
  nav(vel/2, vel);
  return ;
}
void leftback()
{
  rev(vel/2, vel);
  return ;
}
void right()
{
  
  kanan();
  return ;
}
void left()
{
  kiri();
  return ;
}
void front()
{
  nav(vel, vel);
  return;
}
void rear()
{
  rev(vel, vel);
  return;
}
void brake()
{
  //nav(0, 0);
  brake(0, 0);
  return;
}

void nav(int spd, int spd2)
{
  analogWrite(pwm1, spd);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(pwm2, spd2);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void kanan()
{
  analogWrite(pwm1, vel);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(pwm2, vel);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void kiri()
{
  analogWrite(pwm1, vel);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(pwm2, vel);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void rev(int spd, int spd2)
{
  analogWrite(pwm1, spd);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(pwm2, spd2);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}


void brake(int spd, int spd2)
{
  analogWrite(pwm1, spd2);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, HIGH);
  analogWrite(pwm2, spd);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
