#include<Servo.h>
Servo servo_9;
int l=13,p=11;
int pos=0,i=0,c=0,data;

void setup(){
  pinMode(l,OUTPUT);
  pinMode(p,INPUT);
  servo_9.attach(9, 500, 2500);
  servo_9.write(pos);
  Serial.begin(9600);
    run();
}
void run()
{
  while(1)
  {
    while (Serial.available()){
  data = Serial.read();
    }
  servo_9.write(pos);
  if(data=='1')
  {
    digitalWrite(l,1);
    for (pos = 0; pos <= 90; pos += 1) 
        {
           servo_9.write(pos);delay(15);
         }
         delay(5000);
         for (pos = 90; pos >= 0; pos -= 1)
         {
    
        servo_9.write(pos);
           delay(15);
          }
    data='0';
    digitalWrite(l,0);
    break;
  }
  }
}
void loop(){}
