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
  motorX.setMaxSpeed(200);
  motorY.setMaxSpeed(200);
  motorZ.setMaxSpeed(200);
  motorA.setMaxSpeed(200);
  
  motorX.setAcceleration(50);
  motorY.setAcceleration(50);
  motorZ.setAcceleration(50);
  motorA.setAcceleration(50);
  
  motorX.moveTo(200);
  motorY.moveTo(200);
  motorZ.moveTo(200);
  motorA.moveTo(200);
}

void loop() {
  // Change direction once the motor reaches target position
  if (motorX.distanceToGo() == 0) 
    motorX.moveTo(-motorX.currentPosition());
  
  if (motorY.distanceToGo() == 0) 
    motorY.moveTo(-motorY.currentPosition());

  if (motorZ.distanceToGo() == 0) 
    motorZ.moveTo(-motorZ.currentPosition());

  if (motorA.distanceToGo() == 0) 
    motorA.moveTo(-motorA.currentPosition());

  // Move the motor one step
  motorX.run();
  motorY.run();
  motorZ.run();
  motorA.run();
}
