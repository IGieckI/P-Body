#include <unity.h>
#include <MovementModule.hpp>

// To run the test "platformio test --environment esp32-s3-n16r8"

MovementModule* movement;

void setUp(void) {
    movement = new MovementModule();

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
    movement->moveForward();
    delay(2000);
    movement->stop();
}

void test_move_backward(void) {
    // Move Backward for 2 seconds
    movement->moveBackward();
    delay(2000);
    movement->stop();
}

void test_turn_left(void) {
    // Turn Left Forward for 2 seconds
    movement->turnLeft();
    delay(2000);
    movement->stop();
}

void test_turn_right(void) {
    // Turn Right Forward for 2 seconds
    movement->turnRight();
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

    RUN_TEST(test_turn_left);
    delay(1000);
    
    RUN_TEST(test_turn_right);
    delay(1000);

    UNITY_END();
}

void loop() { }
