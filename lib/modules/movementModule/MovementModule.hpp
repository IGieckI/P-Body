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
     * @brief Spin the top left wheel forward.
     * 
     * @param speed the speed of the wheel (0-255)
     */
    void topLeftWheelForward(int speed=255);
    
    
    /**
     * @brief Spin the top left wheel backward.
     * 
     * @param speed the speed of the wheel (0-255)
     */
    void topLeftWheelBackward(int speed=255);
    
    /**
     * @brief Spin the top right wheel forward.
     * 
     * @param speed the speed of the wheel (0-255)
     */
    void topRightWheelForward(int speed=255);

    /**
     * @brief Spin the top right wheel backward.
     * 
     * @param speed the speed of the wheel (0-255)
     */
    void topRightWheelBackward(int speed=255);

    /**
     * @brief Spin the bottom left wheel forward.
     * 
     * @param speed the speed of the wheel (0-255)
     */
    void bottomLeftWheelForward(int speed=255);
    
    /**
     * @brief Spin the bottom left wheel backward.
     * 
     * @param speed the speed of the wheel (0-255)
     */
    void bottomLeftWheelBackward(int speed=255);
    
    /**
     * @brief Spin the bottom right wheel forward.
     * 
     * @param speed the speed of the wheel (0-255)
     */
    void bottomRightWheelForward(int speed=255);

    /**
     * @brief Spin the bottom right wheel backward.
     * 
     * @param speed the speed of the wheel (0-255)
     */
    void bottomRightWheelBackward(int speed=255);

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
    void turnLeft(int speed=255);

    /**
     * @brief Turn the robot right while moving forward.
     * 
     * @param speed the speed of the movement (0-255)
     */
    void turnRight(int speed=255);

    /**
     * @brief Stop all movement.
     */
    void stop();
};