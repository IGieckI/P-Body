#include <MovementModule.hpp>

MovementModule::MovementModule() : IModule("MovementModule") {}

bool MovementModule::init() {
    pinMode(WHEEL_TOP_LEFT_PIN_1, OUTPUT);
    pinMode(WHEEL_TOP_LEFT_PIN_2, OUTPUT);

    pinMode(WHEEL_TOP_RIGHT_PIN_1, OUTPUT);
    pinMode(WHEEL_TOP_RIGHT_PIN_2, OUTPUT);

    pinMode(WHEEL_BOTTOM_LEFT_PIN_1, OUTPUT);
    pinMode(WHEEL_BOTTOM_LEFT_PIN_2, OUTPUT);

    pinMode(WHEEL_BOTTOM_RIGHT_PIN_1, OUTPUT);
    pinMode(WHEEL_BOTTOM_RIGHT_PIN_2, OUTPUT);
    
    return true;
}

void MovementModule::moveForward(int speed) {
    digitalWrite(WHEEL_TOP_LEFT_PIN_1, speed);
    digitalWrite(WHEEL_TOP_LEFT_PIN_2, LOW);

    digitalWrite(WHEEL_TOP_RIGHT_PIN_1, speed);
    digitalWrite(WHEEL_TOP_RIGHT_PIN_2, LOW);

    digitalWrite(WHEEL_BOTTOM_LEFT_PIN_1, LOW);
    digitalWrite(WHEEL_BOTTOM_LEFT_PIN_2, speed);

    digitalWrite(WHEEL_BOTTOM_RIGHT_PIN_1, LOW);
    digitalWrite(WHEEL_BOTTOM_RIGHT_PIN_2, speed);
}

void MovementModule::moveBackward(int speed) {
    digitalWrite(WHEEL_TOP_LEFT_PIN_1, LOW);
    digitalWrite(WHEEL_TOP_LEFT_PIN_2, speed);

    digitalWrite(WHEEL_TOP_RIGHT_PIN_1, LOW);
    digitalWrite(WHEEL_TOP_RIGHT_PIN_2, speed);

    digitalWrite(WHEEL_BOTTOM_LEFT_PIN_1, speed);
    digitalWrite(WHEEL_BOTTOM_LEFT_PIN_2, LOW);

    digitalWrite(WHEEL_BOTTOM_RIGHT_PIN_1, speed);
    digitalWrite(WHEEL_BOTTOM_RIGHT_PIN_2, LOW);
}

void MovementModule::turnLeftForward(int speed) {
    digitalWrite(WHEEL_TOP_LEFT_PIN_1, LOW);
    digitalWrite(WHEEL_TOP_LEFT_PIN_2, LOW);

    digitalWrite(WHEEL_TOP_RIGHT_PIN_1, speed);
    digitalWrite(WHEEL_TOP_RIGHT_PIN_2, LOW);

    digitalWrite(WHEEL_BOTTOM_LEFT_PIN_1, LOW);
    digitalWrite(WHEEL_BOTTOM_LEFT_PIN_2, speed);

    digitalWrite(WHEEL_BOTTOM_RIGHT_PIN_1, LOW);
    digitalWrite(WHEEL_BOTTOM_RIGHT_PIN_2, speed);
}

void MovementModule::turnRightForward(int speed) {
    digitalWrite(WHEEL_TOP_LEFT_PIN_1, speed);
    digitalWrite(WHEEL_TOP_LEFT_PIN_2, LOW);

    digitalWrite(WHEEL_TOP_RIGHT_PIN_1, LOW);
    digitalWrite(WHEEL_TOP_RIGHT_PIN_2, LOW);

    digitalWrite(WHEEL_BOTTOM_LEFT_PIN_1, LOW);
    digitalWrite(WHEEL_BOTTOM_LEFT_PIN_2, speed);

    digitalWrite(WHEEL_BOTTOM_RIGHT_PIN_1, LOW);
    digitalWrite(WHEEL_BOTTOM_RIGHT_PIN_2, speed);
}

void MovementModule::turnLeftBackward(int speed) {
    digitalWrite(WHEEL_TOP_LEFT_PIN_1, LOW);
    digitalWrite(WHEEL_TOP_LEFT_PIN_2, LOW);

    digitalWrite(WHEEL_TOP_RIGHT_PIN_1, LOW);
    digitalWrite(WHEEL_TOP_RIGHT_PIN_2, speed);

    digitalWrite(WHEEL_BOTTOM_LEFT_PIN_1, speed);
    digitalWrite(WHEEL_BOTTOM_LEFT_PIN_2, LOW);

    digitalWrite(WHEEL_BOTTOM_RIGHT_PIN_1, LOW);
    digitalWrite(WHEEL_BOTTOM_RIGHT_PIN_2, speed);
}

void MovementModule::turnRightBackward(int speed) {
    digitalWrite(WHEEL_TOP_LEFT_PIN_1, LOW);
    digitalWrite(WHEEL_TOP_LEFT_PIN_2, speed);

    digitalWrite(WHEEL_TOP_RIGHT_PIN_1, LOW);
    digitalWrite(WHEEL_TOP_RIGHT_PIN_2, LOW);

    digitalWrite(WHEEL_BOTTOM_LEFT_PIN_1, speed);
    digitalWrite(WHEEL_BOTTOM_LEFT_PIN_2, LOW);

    digitalWrite(WHEEL_BOTTOM_RIGHT_PIN_1, speed);
    digitalWrite(WHEEL_BOTTOM_RIGHT_PIN_2, LOW);
}

void MovementModule::stop() {
    digitalWrite(WHEEL_TOP_LEFT_PIN_1, LOW);
    digitalWrite(WHEEL_TOP_LEFT_PIN_2, LOW);

    digitalWrite(WHEEL_TOP_RIGHT_PIN_1, LOW);
    digitalWrite(WHEEL_TOP_RIGHT_PIN_2, LOW);

    digitalWrite(WHEEL_BOTTOM_LEFT_PIN_1, LOW);
    digitalWrite(WHEEL_BOTTOM_LEFT_PIN_2, LOW);

    digitalWrite(WHEEL_BOTTOM_RIGHT_PIN_1, LOW);
    digitalWrite(WHEEL_BOTTOM_RIGHT_PIN_2, LOW);
}