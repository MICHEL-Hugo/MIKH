#include "ButtonControl.h"

ButtonControl::ButtonControl(int pinButton, MotorControl& motorControl)
    : pinBP(pinButton), BP_Flag(false), motor(motorControl) {
    pinMode(pinBP, INPUT_PULLUP);
}

void ButtonControl::checkButton() {
    if (!digitalRead(pinBP)) {
        if (!BP_Flag) {
            BP_Flag = true;
            motor.unlimitedLoad(100, 5000, 2000);
        } else {
            BP_Flag = false;
            motor.unload();
        }
        delay(500);
    }
}
