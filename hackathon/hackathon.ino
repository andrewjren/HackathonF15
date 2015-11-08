
/**
   JoystickShield - Arduino Library for JoystickShield (http://hardwarefun.com/projects/joystick-shield)
   Copyright 2011  Sudar Muthu  (email : sudar@sudarmuthu.com)
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <sudar@sudarmuthu.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer or coffee in return - Sudar
 * ----------------------------------------------------------------------------
 * Rest of this code was designed by Dan Witman, Andrew Ren, and Mark Frederick for HackPSU F15. 
 * All of it was written way to early in the morning.
 * Written for a robot arm powered by servos.
 */


#include <Servo.h> // include Servo library
#include <JoystickShield.h> // include JoystickShield Library

JoystickShield joystickShield; // create an instance of JoystickShield object

Servo servo1;
int servo1out = 3;
Servo servo2;
int servo2out = 5;
Servo servo4;
int servo4out = 6;

void setup() {
    Serial.begin(9600);
    
    servo1.attach(servo1out);
    servo2.attach(servo2out); 
    servo4.attach(servo4out); 
    
  
    delay(100);
    // new calibration function
    joystickShield.calibrateJoystick();
}

void loop() {
  
  joystickShield.processEvents();
  
  int dx = -1*joystickShield.xAmplitude();
  int dy = -1*joystickShield.yAmplitude();
    
  servo1.write(servo1.read() + (dx*180)/10000);
  servo2.write(servo2.read() + (dy*180)/15000);
  
  if(joystickShield.isUpButton())
    servo4.write(50);
  else
    servo4.write(90);
    
  if(joystickShield.isDownButton())
    whip();
  
  
  //Serial.println(dx);
  //Serial.println(dy);
  Serial.print(servo1.read());
  Serial.print(", ");
  Serial.println(servo2.read());
  
}

void whip() {
  
  servo1.write(88); // now watch me
  servo2.write(80);
  delay(492);
  
  for(int i = 0; i < 2; i++) {
  servo1.write(100); // whip
  servo2.write(55);
  delay(1714);
  
  servo1.write(80); // nae nae
  servo2.write(80);
  delay(492);
  
  servo1.write(110);
  servo2.write(80);
  delay(492);
  
  servo1.write(80);
  servo2.write(80);
  delay(492);
  
  servo1.write(110);
  servo2.write(80);
  delay(492);
  
  servo1.write(100); // whip
  servo2.write(55);
  delay(644);
  
  servo1.write(80); // whip
  servo2.write(55);
  delay(1073);
  
  servo1.write(80); // nae nae
  servo2.write(80);
  delay(492);
  
  servo1.write(110);
  servo2.write(80);
  delay(492);
  
  servo1.write(80);
  servo2.write(80);
  delay(492);
  
  servo1.write(110);
  servo2.write(80);
  delay(492);
  }
}
