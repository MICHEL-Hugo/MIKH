#include <Arduino.h>
#include "MotorControl.h"
#include "ButtonControl.h"
#include "Config.h"

MotorControl motor(PIN_ESC_AVD, PIN_ESC_AVG, PIN_ESC_ARD, PIN_ESC_ARG);
ButtonControl button(PIN_BP, motor);

String inputString = "";  

void serialCommand() {
    while (Serial.available()) {
        char inChar = (char)Serial.read();
        inputString += inChar;
        if (inChar == '\n') {
            inputString.trim(); 
            int v_set_input = inputString.toInt();
            if (v_set_input >= 5 && v_set_input <= 100) {
                motor.load(v_set_input, 5000, 2000, 2000);
            } else if (v_set_input == 101) {
                motor.setMotors();
            } else if (v_set_input == 0) {
                motor.reportMotorStates();
                Serial.println("test");
            } else {
                Serial.println("Invalid input");
            }
            inputString = ""; 
        }
    }
}

void setup() {
    Serial.begin(115200);
    pinMode(PIN_PS, INPUT);
    motor.setupESC();
}

void loop() {
    while (!Serial.available()) {
        button.checkButton();
    }
    serialCommand();
}
