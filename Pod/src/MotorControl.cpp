#include "MotorControl.h"
#include "Config.h"

MotorControl::MotorControl(int pinAvD, int pinAvG, int pinArD, int pinArG) {
    ESC_AvD.attach(pinAvD, 1000, 2000);
    ESC_AvG.attach(pinAvG, 1000, 2000);
    ESC_ArD.attach(pinArD, 1000, 2000);
    ESC_ArG.attach(pinArG, 1000, 2000);
    State_AvD = State_AvG = State_ArD = State_ArG = true;
}

void MotorControl::setupESC() {
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

void MotorControl::unlimitedLoad(int v_set, int t_set, int t_set_preLoad) {
    delay(t_set_preLoad);
    int v_set_m = map(v_set, 0, 100, 1000, 2000);
    int i = 1000 + V_OFFSET_M;
    Serial.println("Top Speed");
    while (i <= v_set_m) {
        if (State_AvD) ESC_AvD.writeMicroseconds(i);
        if (State_AvG) ESC_AvG.writeMicroseconds(i);
        if (State_ArD) ESC_ArD.writeMicroseconds(i);
        if (State_ArG) ESC_ArG.writeMicroseconds(i);
        delay(t_set / (v_set_m - (1000 + V_OFFSET_M)));
        i++;
    }
}

void MotorControl::load(int v_set, int t_set, int t_set_load, int t_set_preLoad) {
    unlimitedLoad(v_set, t_set, t_set_preLoad);
    delay(t_set_load);
    unload();
}

void MotorControl::unload() {
    ESC_AvD.writeMicroseconds(1000);
    ESC_AvG.writeMicroseconds(1000);
    ESC_ArD.writeMicroseconds(1000);
    ESC_ArG.writeMicroseconds(1000);
    Serial.println("Stop");
}

void MotorControl::setMotors() {
    char set_input;
    Serial.println("Motor Setup - Enter 0/1 to enable/disable each motor");

    Serial.print("Motor AvD 0/1 : ");
    while (!Serial.available());
    set_input = Serial.read();
    State_AvD = (set_input == '1');
    Serial.println();

    Serial.print("Motor AvG 0/1 : ");
    while (!Serial.available());
    set_input = Serial.read();
    State_AvG = (set_input == '1');
    Serial.println();

    Serial.print("Motor ArD 0/1 : ");
    while (!Serial.available());
    set_input = Serial.read();
    State_ArD = (set_input == '1');
    Serial.println();

    Serial.print("Motor ArG 0/1 : ");
    while (!Serial.available());
    set_input = Serial.read();
    State_ArG = (set_input == '1');
    Serial.println();

    reportMotorStates();
    Serial.println("Motor Setup - Done");

}

void MotorControl::reportMotorStates() {
    Serial.print("State AvD: ");
    Serial.println(State_AvD);
    Serial.print("State AvG: ");
    Serial.println(State_AvG);
    Serial.print("State ArD: ");
    Serial.println(State_ArD);
    Serial.print("State ArG: ");
    Serial.println(State_ArG);
}



