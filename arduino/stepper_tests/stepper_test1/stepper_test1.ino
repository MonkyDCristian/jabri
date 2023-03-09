// program to control the X stepper motor by digital write system, usiung ardunio CNC shield V.3 and a A4988 driver module
// https://lastminuteengineers.com/a4988-stepper-motor-driver-arduino-tutorial/

// Define some steppers and the pins the will use

#define X_STEP 2
#define X_DIR  5
#define ENABLE 8

#define SPR  200 // steps per revolution
    
void setup()
{  
    pinMode(ENABLE,OUTPUT);
    pinMode(X_STEP,OUTPUT);
    pinMode(X_DIR,OUTPUT);

    //Enable the driver active low input pin 
    digitalWrite(ENABLE,LOW);
    
    Serial.begin(9600);
    Serial.println("Start");
}

void loop()
{
  Serial.println("running");

  // Set motor direction clockwise
  digitalWrite(X_DIR, HIGH);

  // Spin motor slowly
  for(int x = 0; x < SPR; x++)
  {
    digitalWrite(X_STEP, HIGH);
    delay(2);
    digitalWrite(X_STEP, LOW);
    delay(2);
  }
  delay(1000); // Wait a second

  // Set motor direction counterclockwise
  digitalWrite(X_DIR, LOW);

  // Spin motor quickly
  for(int x = 0; x < SPR; x++)
  {
    digitalWrite(X_STEP, HIGH);
    delayMicroseconds(1000);
    digitalWrite(X_STEP, LOW);
    delayMicroseconds(1000);
  }

  delay(1000); // Wait a second
}
