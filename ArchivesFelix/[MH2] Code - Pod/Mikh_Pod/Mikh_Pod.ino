#include <Servo.h>
#include <String.h>

#define ESC_MIN 5

const int v_offset_m(45);
const int motor_KV(1200);
const int Bat_Level_Value(18.6);

const int pin_BP(13); //Push Button
const int pin_PS(A0); //Power Supply
const int pinESC_AvD(6); 
const int pinESC_AvG(5); 
const int pinESC_ArD(9); 
const int pinESC_ArG(10); 

int v_set_m(0); // Speed Value (1000ms - 2000ms)
int v_set_input(0); // Speed Value (0% - 100%)
int v_rise_delay(5000); // Speed Up Time 
int v_load_delay(2000); // Top speed Time
int v_preLoad_delay(2000); // Time before Load
int Batt_Level(0);
int Batt_Level_m(0);
bool State_AvD(1);
bool State_AvG(1);
bool State_ArD(1);
bool State_ArG(1);
int set_input(1);
bool BP_Flag(false);

Servo ESC_AvD;
Servo ESC_AvG;
Servo ESC_ArD;
Servo ESC_ArG;

void setup_ESC()
{
  ESC_AvD.attach(pinESC_AvD,1000,2000);
  ESC_AvG.attach(pinESC_AvG,1000,2000);
  ESC_ArD.attach(pinESC_ArD,1000,2000);
  ESC_ArG.attach(pinESC_ArG,1000,2000);
  ESC_AvD.writeMicroseconds(2000);
  ESC_AvG.writeMicroseconds(2000);
  ESC_ArD.writeMicroseconds(2000);
  ESC_ArG.writeMicroseconds(2000);
  delay(3000);
  ESC_AvD.writeMicroseconds(1000);
  ESC_AvG.writeMicroseconds(1000);
  ESC_ArD.writeMicroseconds(1000);
  ESC_ArG.writeMicroseconds(1000);
  delay(3000);
}

void setup() 
{
pinMode(pin_BP,INPUT_PULLUP);
pinMode(pin_PS,INPUT);
setup_ESC();
}

void load_BP()
{
  if(!digitalRead(pin_BP)){
    ESC_AvD.writeMicroseconds(2000);
    ESC_AvG.writeMicroseconds(2000);
    ESC_ArD.writeMicroseconds(2000);
    ESC_ArG.writeMicroseconds(2000);
    }
  else {
    ESC_AvD.writeMicroseconds(1000);
    ESC_AvG.writeMicroseconds(1000);
    ESC_ArD.writeMicroseconds(1000);
    ESC_ArG.writeMicroseconds(1000);
  }
}

void unload()
{
    ESC_AvD.writeMicroseconds(1000);
    ESC_AvG.writeMicroseconds(1000);
    ESC_ArD.writeMicroseconds(1000);
    ESC_ArG.writeMicroseconds(1000);
    Serial.println("Stop");
    v_set_input = 0;
}


void unlimited_load(int v_set,int t_set, int t_set_preLoad)
{
  delay(t_set_preLoad);
  v_set_m = map(v_set,0,100,1000,2000);
  int i = 1000+v_offset_m;
  if(v_set!=0)
  {
    Serial.print("Load (");
    Serial.print(v_set);
    Serial.print("%) (RPM:");
    Serial.print((v_set*motor_KV*Bat_Level_Value)/100);
    Serial.println(") (Unlimited)");
  }  
  while(i<=v_set_m) {
    //Serial.println(i);
    if(State_AvD==1) ESC_AvD.writeMicroseconds(i); 
    if(State_AvG==1) ESC_AvG.writeMicroseconds(i); 
    if(State_ArD==1) ESC_ArD.writeMicroseconds(i); 
    if(State_ArG==1) ESC_ArG.writeMicroseconds(i); 
    delay(t_set/(v_set_m-(1000+v_offset_m)));
    i++;
  }
  Serial.println("Top Speed");
}

void load(int v_set,int t_set,int t_set_load, int t_set_preLoad)
{
  delay(t_set_preLoad);
  v_set_m = map(v_set,0,100,1000,2000);
  int i = 1000+v_offset_m;
  if(v_set!=0)
  {
    Serial.print("Load (");
    Serial.print(v_set);
    Serial.print("%) (RPM:");
    Serial.print((v_set*motor_KV*Bat_Level_Value)/100);
    Serial.println(")");
  }  
  while(i<=v_set_m) {
    //Serial.println(i);
    if(State_AvD==1) ESC_AvD.writeMicroseconds(i); 
    if(State_AvG==1) ESC_AvG.writeMicroseconds(i); 
    if(State_ArD==1) ESC_ArD.writeMicroseconds(i); 
    if(State_ArG==1) ESC_ArG.writeMicroseconds(i); 
    delay(t_set/(v_set_m-(1000+v_offset_m)));
    i++;
  }
  Serial.println("Top Speed");
  delay(t_set_load);
  unload();
}

void set_Motor()
{
  Serial.println("Motor AvD 0/1 : ");
  set_input = 1;
  delay(4000);
  set_input = Serial.parseInt();
  if(set_input==0) State_AvD = 0;
  else State_AvD = 1;
  Serial.print("Motor AvD Set : ");
  Serial.println(State_AvD);

  Serial.println("Motor AvG 0/1 : ");
  set_input = 1;
  delay(4000);
  set_input = Serial.parseInt();
  if(set_input==0) State_AvG = 0;
  else State_AvG = 1;
  Serial.print("Motor AvG Set : ");
  Serial.println(State_AvG);

  Serial.println("Motor ArD 0/1 : ");
  set_input = 1;
  delay(4000);
  set_input = Serial.parseInt();
  if(set_input==0) State_ArD = 0;
  else State_ArD = 1;
  Serial.print("Motor ArD Set : ");
  Serial.println(State_ArD);

  Serial.println("Motor ArG 0/1 : ");
  set_input = 1;
  delay(4000);
  set_input = Serial.parseInt();
  if(set_input==0) State_ArG = 0;
  else State_ArG = 1;
  Serial.print("Motor ArG Set : ");
  Serial.println(State_ArG);
}

void wait_BP()
{
  if(!digitalRead(pin_BP)) 
    {
      if(!BP_Flag) 
      {
        BP_Flag = true;
        v_set_input = 100;
        unlimited_load(v_set_input,v_rise_delay,v_preLoad_delay);
      }
      else {
        BP_Flag = false;
        unload();
      }
      delay(500);
    }  
}

void serial_Command()
{
  v_set_input = Serial.parseInt();
  if(v_set_input<=100 && v_set_input>=5) 
  {
    load(v_set_input,v_rise_delay,v_load_delay,v_preLoad_delay);
    Serial.flush();
    v_set_input = 0;
  }  
  else if(v_set_input==101){
    set_Motor();
  }
  else{}
}

void loop() {
  while(!Serial.available()){
    wait_BP();
  }
  serial_Command();
}
