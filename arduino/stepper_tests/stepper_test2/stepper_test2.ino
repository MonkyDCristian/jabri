// Program to control the X stepper motor by AccelStepper library, usiung ardunio CNC shield V.3 and A4988 driver module
// https://lastminuteengineers.com/a4988-stepper-motor-driver-arduino-tutorial/

// Include the AccelStepper Library
#include <AccelStepper.h>

// Define pin connections
#define X_STEP 2
#define X_DIR  5
#define ENABLE 8

// Creates an instance
AccelStepper myStepper(AccelStepper::DRIVER, X_STEP, X_DIR);

void setup() {
  //Enable the driver active low input pin 
  pinMode(ENABLE,OUTPUT);
  digitalWrite(ENABLE,LOW);
  
  // set the maximum speed, acceleration factor,
  // initial speed and the target position
  myStepper.setMaxSpeed(1000);
  myStepper.setAcceleration(50);
  myStepper.setSpeed(200);
  myStepper.moveTo(200);
}

void loop() {
  // Change direction once the motor reaches target position
  if (myStepper.distanceToGo() == 0) 
    myStepper.moveTo(-myStepper.currentPosition());

  // Move the motor one step
  myStepper.run();
}
