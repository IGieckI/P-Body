#include <unity.h>
#include <MovementModule.hpp>

// To run the test "platformio test --environment esp32-s3-n16r8"

MovementModule* movement;

void setUp(void) {
    movement = new MovementModule();
    
    // Ensure pins are set to output
    pinMode(WHEEL_TOP_LEFT_PIN_1, OUTPUT);
    pinMode(WHEEL_TOP_LEFT_PIN_2, OUTPUT);
    pinMode(WHEEL_TOP_RIGHT_PIN_1, OUTPUT);
    pinMode(WHEEL_TOP_RIGHT_PIN_2, OUTPUT);
    pinMode(WHEEL_BOTTOM_LEFT_PIN_1, OUTPUT);
    pinMode(WHEEL_BOTTOM_LEFT_PIN_2, OUTPUT);
    pinMode(WHEEL_BOTTOM_RIGHT_PIN_1, OUTPUT);
    pinMode(WHEEL_BOTTOM_RIGHT_PIN_2, OUTPUT);

    movement->init();
}

void tearDown(void) {
    if (movement) {
        movement->stop();
        delete movement;
        movement = nullptr;
    }
}

void test_move_forward(void) {
    // Move Forward for 2 seconds
    movement->moveForward(255);
    delay(2000);
    movement->stop();
}

void test_move_backward(void) {
    // Move Backward for 2 seconds
    movement->moveBackward(255);
    delay(2000);
    movement->stop();
}

void test_turn_left_forward(void) {
    // Turn Left Forward for 2 seconds
    movement->turnLeftForward(255);
    delay(2000);
    movement->stop();
}

void test_turn_right_forward(void) {
    // Turn Right Forward for 2 seconds
    movement->turnRightForward(255);
    delay(2000);
    movement->stop();
}

void test_turn_left_backward(void) {
    // Turn Left Backward for 2 seconds
    movement->turnLeftBackward(255);
    delay(2000);
    movement->stop();
}

void test_turn_right_backward(void) {
    // Turn Right Backward for 2 seconds
    movement->turnRightBackward(255);
    delay(2000);
    movement->stop();
}

void setup() {
    // Wait for >2 secs if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);

    UNITY_BEGIN();

    // Run each movement test with a delay in between for visual inspection
    RUN_TEST(test_move_forward);
    delay(1000);

    RUN_TEST(test_move_backward);
    delay(1000);

    RUN_TEST(test_turn_left_forward);
    delay(1000);

    RUN_TEST(test_turn_left_backward);
    delay(1000);

    
    RUN_TEST(test_turn_right_forward);
    delay(1000);

    RUN_TEST(test_turn_right_backward);
    
    UNITY_END();
}

void loop() {
    // Nothing to do here
}
