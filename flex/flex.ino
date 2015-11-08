#include <Servo.h>

int servo3out = 2;
Servo servo3;
const int flexsensor = 0;


void setup()
{
  Serial.begin(9600);
  servo3.attach(servo3out);
}

void loop()
{
  //servo3.write((160-analogRead(flexsensor))*180/100);
  //servo3.write(analogRead(-1*flexsensor) * 2 - 140);
  
  servo3.write(map(analogRead(flexsensor), 120, 260, 180, 0));
  Serial.println(analogRead(flexsensor));
  
  //delay(1);
}

