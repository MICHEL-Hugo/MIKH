#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver mikhServo = Adafruit_PWMServoDriver();

#define OFFSET  0
#define SERVOMIN  200 
#define SERVOMAX  380 
#define SERVO_FREQ 50

const int pinCapt_BP(2);
const int pinCapt_End(3);
const int pinCapt_Start(4);
const int pinVFD_Run(5);
const int pinVFD_Rev(6);

const int pin_pltAvG(0);
const int pin_pltAvD(1);
const int pin_pltArG(2);
const int pin_pltArD(3);

uint16_t pulselen = 0;

bool plt_flag(1);

void setup() {
Serial.begin(9600);
pinMode(pinVFD_Run,OUTPUT);
pinMode(pinVFD_Rev,OUTPUT);
pinMode(pinCapt_BP,INPUT_PULLUP);
pinMode(pinCapt_End,INPUT_PULLUP);
pinMode(pinCapt_Start,INPUT_PULLUP);

digitalWrite(pinVFD_Run,LOW);
digitalWrite(pinVFD_Rev,LOW);

mikhServo.begin();
mikhServo.setOscillatorFrequency(27000000);
mikhServo.setPWMFreq(SERVO_FREQ);
}

void plt_Switch(int alight_t) {
  if(plt_flag)
  {
    for (pulselen ; pulselen < SERVOMAX ; pulselen++) {
      mikhServo.setPWM(pin_pltAvG, 0, pulselen);
      mikhServo.setPWM(pin_pltAvD, 0, pulselen);
      mikhServo.setPWM(pin_pltArG, 0, pulselen);
      mikhServo.setPWM(pin_pltArD, 0, pulselen);    
      delay(alight_t/(SERVOMAX-SERVOMIN));  
   }
   for (pulselen ; pulselen > SERVOMAX - OFFSET ; pulselen--) {
      mikhServo.setPWM(pin_pltAvG, 0, pulselen);
      mikhServo.setPWM(pin_pltAvD, 0, pulselen);
      mikhServo.setPWM(pin_pltArG, 0, pulselen);
      mikhServo.setPWM(pin_pltArD, 0, pulselen);  
    }
   plt_flag = false;
   delay(1);
  }
 else
 {
    for (pulselen ; pulselen > SERVOMIN ; pulselen--) {
      mikhServo.setPWM(pin_pltAvG, 0, pulselen);
      mikhServo.setPWM(pin_pltAvD, 0, pulselen);
      mikhServo.setPWM(pin_pltArG, 0, pulselen);
      mikhServo.setPWM(pin_pltArD, 0, pulselen);  
      delay(alight_t/(SERVOMAX-SERVOMIN));  
    }
   plt_flag = true;
  delay(1);
 }
}

void loop() {
while(digitalRead(pinCapt_BP)) { 
  delay(1);
}
  plt_Switch(1000); //bas
  delay(20);
  digitalWrite(pinVFD_Rev,HIGH);
  delay(750);
  digitalWrite(pinVFD_Rev,LOW);
while(digitalRead(pinCapt_End)) {
  delay(1);
}
  digitalWrite(pinVFD_Run,HIGH);
  delay(750);
  digitalWrite(pinVFD_Run,LOW);
while(digitalRead(pinCapt_Start)) {
  delay(1);
}
  plt_Switch(10); //haut
}
