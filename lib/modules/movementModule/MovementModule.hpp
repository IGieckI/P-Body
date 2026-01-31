#pragma once
#include <IModule.hpp>

class MovementModule : public IModule
{
public:
    MovementModule();

    /**
     * @brief Movement Module Initialization, with the current wheels setup there is nothing to test.
     *
     * @return true if the module was initialized successfully
     * @return false if the module failed to initialize
     */
    bool init() override;

    /**
     * @brief Move the robot forward.
     * 
     * @param speed the speed of the movement (0-255)
     */
    void moveForward(int speed=255);

    /**
     * @brief Move the robot backward.
     * 
     * @param speed the speed of the movement (0-255)
     */
    void moveBackward(int speed=255);

    /**
     * @brief Turn the robot left while moving forward.
     * 
     * @param speed the speed of the movement (0-255)
     */
    void turnLeftForward(int speed=255);

    /**
     * @brief Turn the robot right while moving forward.
     * 
     * @param speed the speed of the movement (0-255)
     */
    void turnRightForward(int speed=255);

    /**
     * @brief Turn the robot left while moving backward.
     * 
     * @param speed the speed of the movement (0-255)
     */
    void turnLeftBackward(int speed=255);

    /**
     * @brief Turn the robot right while moving backward.
     * 
     * @param speed the speed of the movement (0-255)
     */
    void turnRightBackward(int speed=255);

    /**
     * @brief Stop all movement.
     */
    void stop();
};