#include <Arduino.h>
#include <micro_ros_platformio.h>
#include <WiFi.h>

#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>

#include <geometry_msgs/msg/twist.h>
#include <std_msgs/msg/int16_multi_array.h>

#include <MovementModule.hpp>

// Modules
MovementModule* movement;

// ROS Config
rcl_publisher_t audio_publisher;
rcl_subscription_t twist_subscriber;
geometry_msgs__msg__Twist twist_msg;
std_msgs__msg__Int16MultiArray audio_msg;

rclc_executor_t executor;
rcl_allocator_t allocator;
rclc_support_t support;
rcl_node_t node;

// Callbacks

// Receive Movement Command
void subscription_callback(const void * msgin) {
  const geometry_msgs__msg__Twist * msg = (const geometry_msgs__msg__Twist *)msgin;
  
  float linear = msg->linear.x;
  float angular = msg->angular.z;

  // ROS (-1.0 to 1.0) to PWM (0 to 255)
  if (linear > 0) {
      movement->moveForward(200);
      Serial.println("Moving Forward");
  } else if (linear < 0) {
      movement->moveBackward(200);
      Serial.println("Moving Backward");
  } else {
      movement->stop();
      Serial.println("Stop");
  }
}

// Publish Audio
void publish_audio() {
    // Should send I2S data as audio_msg.data.data
    int16_t dummy_audio[10]; 
    audio_msg.data.data = dummy_audio;
    audio_msg.data.size = 10;
    
    rcl_publish(&audio_publisher, &audio_msg, NULL);
}

void setup() {
  Serial.begin(115200);
  
  WiFi.begin(SSID, PWD);
  while (WiFi.status() != WL_CONNECTED) { delay(500); }

  // Connect to Micro-ROS Agent
  set_microros_wifi_transports(SSID, PWD, AGENT_IP, AGENT_PORT);
  
  allocator = rcl_get_default_allocator();
  rclc_support_init(&support, 0, NULL, &allocator);
  rclc_node_init_default(&node, "esp32_main_controller", "", &support);

  // Init Subscriber (Cmd Vel)
  rclc_subscription_init_default(
    &twist_subscriber, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(geometry_msgs, msg, Twist), "/cmd_vel");

  // Init Publisher (Audio)
  rclc_publisher_init_default(
    &audio_publisher, &node, ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int16MultiArray), "/robot/mic_data");

  // Init Executor
  rclc_executor_init(&executor, &support.context, 1, &allocator);
  rclc_executor_add_subscription(&executor, &twist_subscriber, &twist_msg, &subscription_callback, ON_NEW_DATA);
}

void loop() {
  // Sync time and spin
  rclc_executor_spin_some(&executor, RCL_MS_TO_NS(100));
  
  // Publish audio chunks frequently
  publish_audio(); 
}