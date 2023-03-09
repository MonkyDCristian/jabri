//Program to control the X, Y, Z and A steppers motor by AccelStepper library, usiung ardunio CNC shield V.3 and a A4988 driver module

// https://www.airspayce.com/mikem/arduino/AccelStepper/ AccelStepper
// https://lastminuteengineers.com/a4988-stepper-motor-driver-arduino-tutorial/ Basic
// https://github.com/AntoBrandi/Dextro-Bot/tree/master/Arduino/wheel_speed_control_ros ROS

// Include the AccelStepper Library
#include <AccelStepper.h>

// Define pin connections
#define X_STEP 2
#define X_DIR  5

#define Y_STEP 3
#define Y_DIR  6

#define Z_STEP 4
#define Z_DIR  7

#define A_STEP 12
#define A_DIR  13


#define MAX_SPEED 800
#define ACCELERATION 50
#define SPEED  500

#define ENABLE 8

// Creates an instance
AccelStepper motorX(AccelStepper::DRIVER, X_STEP, X_DIR);
AccelStepper motorY(AccelStepper::DRIVER, Y_STEP, Y_DIR);
AccelStepper motorZ(AccelStepper::DRIVER, Z_STEP, Z_DIR);
AccelStepper motorA(AccelStepper::DRIVER, A_STEP, A_DIR);

void setup() {
  //Enable the driver active low input pin 
  pinMode(ENABLE,OUTPUT);
  digitalWrite(ENABLE,LOW);
  
  // set the maximum speed, acceleration factor,
  // initial speed and the target position
  motorX.setMaxSpeed(MAX_SPEED);
  motorY.setMaxSpeed(MAX_SPEED);
  motorZ.setMaxSpeed(MAX_SPEED);
  motorA.setMaxSpeed(MAX_SPEED);

  motorX.setAcceleration(ACCELERATION);
  motorY.setAcceleration(ACCELERATION);
  motorZ.setAcceleration(ACCELERATION);
  motorA.setAcceleration(ACCELERATION);
  
  motorX.setAcceleration(ACCELERATION);
  motorY.setAcceleration(ACCELERATION);
  motorZ.setAcceleration(ACCELERATION);
  motorA.setAcceleration(ACCELERATION);
  
  motorX.setSpeed(SPEED);
  motorY.setSpeed(SPEED);
  motorZ.setSpeed(SPEED);
  motorA.setSpeed(SPEED);
}

void loop() {
  motorX.runSpeed();
  motorY.runSpeed();
  motorZ.runSpeed();
  motorA.runSpeed();
}
