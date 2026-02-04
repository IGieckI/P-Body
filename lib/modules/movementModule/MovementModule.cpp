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

void MovementModule::topLeftWheelForward(int speed) {
    digitalWrite(WHEEL_TOP_LEFT_PIN_1, speed);
    digitalWrite(WHEEL_TOP_LEFT_PIN_2, LOW);
}

void MovementModule::topLeftWheelBackward(int speed) {
    digitalWrite(WHEEL_TOP_LEFT_PIN_1, LOW);
    digitalWrite(WHEEL_TOP_LEFT_PIN_2, speed);
}

void MovementModule::topRightWheelForward(int speed) {
    digitalWrite(WHEEL_TOP_RIGHT_PIN_1, speed);
    digitalWrite(WHEEL_TOP_RIGHT_PIN_2, LOW);
}

void MovementModule::topRightWheelBackward(int speed) {
    digitalWrite(WHEEL_TOP_RIGHT_PIN_1, LOW);
    digitalWrite(WHEEL_TOP_RIGHT_PIN_2, speed);
}

void MovementModule::bottomLeftWheelForward(int speed) {
    digitalWrite(WHEEL_BOTTOM_LEFT_PIN_1, speed);
    digitalWrite(WHEEL_BOTTOM_LEFT_PIN_2, LOW);
}

void MovementModule::bottomLeftWheelBackward(int speed) {
    digitalWrite(WHEEL_BOTTOM_LEFT_PIN_1, LOW);
    digitalWrite(WHEEL_BOTTOM_LEFT_PIN_2, speed);
}

void MovementModule::bottomRightWheelForward(int speed) {
    digitalWrite(WHEEL_BOTTOM_RIGHT_PIN_1, speed);
    digitalWrite(WHEEL_BOTTOM_RIGHT_PIN_2, LOW);
}

void MovementModule::bottomRightWheelBackward(int speed) {
    digitalWrite(WHEEL_BOTTOM_RIGHT_PIN_1, LOW);
    digitalWrite(WHEEL_BOTTOM_RIGHT_PIN_2, speed);
}


void MovementModule::moveForward(int speed) {
    topLeftWheelForward(speed);
    topRightWheelForward(speed);
    bottomLeftWheelForward(speed);
    bottomRightWheelForward(speed);
}

void MovementModule::moveBackward(int speed) {
    topLeftWheelBackward(speed);
    topRightWheelBackward(speed);
    bottomLeftWheelBackward(speed);
    bottomRightWheelBackward(speed);
}

void MovementModule::turnLeft(int speed) {
    topLeftWheelBackward(speed);
    topRightWheelForward(speed);
    bottomLeftWheelBackward(speed);
    bottomRightWheelForward(speed);
}

void MovementModule::turnRight(int speed) {
    topLeftWheelForward(speed);
    topRightWheelBackward(speed);
    bottomLeftWheelForward(speed);
    bottomRightWheelBackward(speed);
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