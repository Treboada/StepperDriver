
#include <Arduino.h>
#include "StepperDriver.h"
#include "Motor28YBJ.h"
#include "config.h"

const Motor28YBJ::Config motor_config = {
    pin_in1: PIN_IN1,
    pin_in2: PIN_IN2,
    pin_in3: PIN_IN3,
    pin_in4: PIN_IN4,
};


// stepper motor to drive
Motor28YBJ motor = Motor28YBJ(&motor_config);

// stepper driver controlling the motor
StepperDriver driver = StepperDriver(&motor);


void setup() {

    // stepper initialization
    motor.init();

    // motor driver setup
    driver.setStepMillis(50);
    driver.start(Stepper::DIRECTION_CW);
}


void loop() {

    // time control using 64 bits to avoid 70 minuts overflow
    uint32_t now = micros();
    static uint64_t microseconds = 0;
    if ((microseconds & 0xffffffff) > now) microseconds += 0x100000000;
    microseconds = (microseconds & 0xffffffff00000000) | now;

    // update components
    driver.tick(microseconds);

}

