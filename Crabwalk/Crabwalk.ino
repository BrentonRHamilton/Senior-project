#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Define the PCA9685 channel numbers to which the servos are connected
const int servoChannel1 = 0; // Channel number for servoMotor1
const int servoChannel2 = 1; // Channel number for servoMotor2
const int servoChannel3 = 2; // Channel number for servoMotor3
const int servoChannel4 = 3; // Channel number for servoMotor4

#define SERVOMIN  200 // this is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  400 // this is the 'maximum' pulse length count (out of 4096)

#define STEPPER_PIN_1 3
#define STEPPER_PIN_2 4
#define STEPPER_PIN_3 5
#define STEPPER_PIN_4 6

#define STEPPER_PIN_5 8
#define STEPPER_PIN_6 9
#define STEPPER_PIN_7 10
#define STEPPER_PIN_8 11

#define STEPPER_PIN_9  22
#define STEPPER_PIN_10 23
#define STEPPER_PIN_11 24
#define STEPPER_PIN_12 25

#define STEPPER_PIN_13 28
#define STEPPER_PIN_14 29
#define STEPPER_PIN_15 30
#define STEPPER_PIN_16 31

int step_number = 5;

void setup() {
  // Initialize the PCA9685 PWM driver with the default address
  pwm.begin();
  
  // Set PWM frequency to 50 Hz
  pwm.setPWMFreq(50);  // Analog servos run at ~50 Hz updates

  // Set up stepper motor pins
  pinMode(STEPPER_PIN_1, OUTPUT);
  pinMode(STEPPER_PIN_2, OUTPUT);
  pinMode(STEPPER_PIN_3, OUTPUT);
  pinMode(STEPPER_PIN_4, OUTPUT);

  pinMode(STEPPER_PIN_5, OUTPUT);
  pinMode(STEPPER_PIN_6, OUTPUT);
  pinMode(STEPPER_PIN_7, OUTPUT);
  pinMode(STEPPER_PIN_8, OUTPUT);

  pinMode(STEPPER_PIN_9, OUTPUT);
  pinMode(STEPPER_PIN_10, OUTPUT);
  pinMode(STEPPER_PIN_11, OUTPUT);
  pinMode(STEPPER_PIN_12, OUTPUT);

  pinMode(STEPPER_PIN_13, OUTPUT);
  pinMode(STEPPER_PIN_14, OUTPUT);
  pinMode(STEPPER_PIN_15, OUTPUT);
  pinMode(STEPPER_PIN_16, OUTPUT);
}

void loop() {
  // Move all servo motors to a certain angle
  moveServos(0); // Change 0 to the desired angle
  
  // Wait for a moment
  delay(1000); // Wait for 1 second
  
  // Move all servo motors to another angle
  moveServos(180); // Change 90 to the desired angle

  
  // Move stepper motor
  moveStepper();
  
  // Terminate the loop after executing once
  while (true) {
    // Add any additional operations if needed
  }
}

// Function to move all servo motors to a specified angle
void moveServos(int angle) {
  // Ensure the angle is within the servo's limits (0 to 180 degrees)
  angle = constrain(angle, 0, 180);
  
  // Move all servo motors to the specified angle
  pwm.setPWM(servoChannel1, 0, angleToPulse(angle)); // Set PWM for servoMotor1
  pwm.setPWM(servoChannel2, 0, angleToPulse(angle)); // Set PWM for servoMotor2
  pwm.setPWM(servoChannel3, 0, angleToPulse(angle)); // Set PWM for servoMotor3
  pwm.setPWM(servoChannel4, 0, angleToPulse(angle)); // Set PWM for servoMotor4
}

// Function to convert angle to pulse width
uint16_t angleToPulse(int angle) {
  // Convert angle (0 to 180 degrees) to pulse width (typically between 150 and 600)
  return map(angle, 0, 180, SERVOMIN, SERVOMAX);
}

// Function to move the stepper motor
void moveStepper() {
  for (int a = 0; a < 8000; a++) { // 4000 steps for a full rotation
    OneStep(true);
    delay(2); // Minimum divide between steps. Higher the number, slower the motor will go.
  }
}

void OneStep(bool dir){
     // declares rotation direction
if(dir){
switch(step_number){
  case 0:
  digitalWrite(STEPPER_PIN_1, HIGH);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  

  digitalWrite(STEPPER_PIN_5, HIGH);
  digitalWrite(STEPPER_PIN_6, LOW);
  digitalWrite(STEPPER_PIN_7, LOW);
  digitalWrite(STEPPER_PIN_8, LOW);


  digitalWrite(STEPPER_PIN_9, HIGH);
  digitalWrite(STEPPER_PIN_10, LOW);
  digitalWrite(STEPPER_PIN_11, LOW);
  digitalWrite(STEPPER_PIN_12, LOW);


  digitalWrite(STEPPER_PIN_13, HIGH);
  digitalWrite(STEPPER_PIN_14, LOW);
  digitalWrite(STEPPER_PIN_15, LOW);
  digitalWrite(STEPPER_PIN_16, LOW);

  
  break;
  case 1:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, HIGH);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, LOW);
  

  digitalWrite(STEPPER_PIN_5, LOW);
  digitalWrite(STEPPER_PIN_6, HIGH);
  digitalWrite(STEPPER_PIN_7, LOW);
  digitalWrite(STEPPER_PIN_8, LOW);


  digitalWrite(STEPPER_PIN_9, LOW);
  digitalWrite(STEPPER_PIN_10, HIGH);
  digitalWrite(STEPPER_PIN_11, LOW);
  digitalWrite(STEPPER_PIN_12, LOW);


  digitalWrite(STEPPER_PIN_13, LOW);
  digitalWrite(STEPPER_PIN_14, HIGH);
  digitalWrite(STEPPER_PIN_15, LOW);
  digitalWrite(STEPPER_PIN_16, LOW);

  
  break;
  case 2:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, HIGH);
  digitalWrite(STEPPER_PIN_4, LOW);
  

  digitalWrite(STEPPER_PIN_5, LOW);
  digitalWrite(STEPPER_PIN_6, LOW);
  digitalWrite(STEPPER_PIN_7, HIGH);
  digitalWrite(STEPPER_PIN_8, LOW);


  digitalWrite(STEPPER_PIN_9, LOW);
  digitalWrite(STEPPER_PIN_10, LOW);
  digitalWrite(STEPPER_PIN_11, HIGH);
  digitalWrite(STEPPER_PIN_12, LOW);


  digitalWrite(STEPPER_PIN_13, LOW);
  digitalWrite(STEPPER_PIN_14, LOW);
  digitalWrite(STEPPER_PIN_15, HIGH);
  digitalWrite(STEPPER_PIN_16, LOW);

  
  break;
  case 3:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, HIGH);
  

  digitalWrite(STEPPER_PIN_5, LOW);
  digitalWrite(STEPPER_PIN_6, LOW);
  digitalWrite(STEPPER_PIN_7, LOW);
  digitalWrite(STEPPER_PIN_8, HIGH);


  digitalWrite(STEPPER_PIN_9, LOW);
  digitalWrite(STEPPER_PIN_10, LOW);
  digitalWrite(STEPPER_PIN_11, LOW);
  digitalWrite(STEPPER_PIN_12, HIGH);


  digitalWrite(STEPPER_PIN_13, LOW);
  digitalWrite(STEPPER_PIN_14, LOW);
  digitalWrite(STEPPER_PIN_15, LOW);
  digitalWrite(STEPPER_PIN_16, HIGH);

  
  break;
} 

}else{
    switch(step_number){
  case 0:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, HIGH);

  digitalWrite(STEPPER_PIN_5, LOW);
  digitalWrite(STEPPER_PIN_6, LOW);
  digitalWrite(STEPPER_PIN_7, LOW);
  digitalWrite(STEPPER_PIN_8, HIGH);


  digitalWrite(STEPPER_PIN_9, LOW);
  digitalWrite(STEPPER_PIN_10, LOW);
  digitalWrite(STEPPER_PIN_11, LOW);
  digitalWrite(STEPPER_PIN_12, HIGH);


  digitalWrite(STEPPER_PIN_13, LOW);
  digitalWrite(STEPPER_PIN_14, LOW);
  digitalWrite(STEPPER_PIN_15, LOW);
  digitalWrite(STEPPER_PIN_16, HIGH);
  break;
  case 1:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, HIGH);

  digitalWrite(STEPPER_PIN_5, LOW);
  digitalWrite(STEPPER_PIN_6, LOW);
  digitalWrite(STEPPER_PIN_7, LOW);
  digitalWrite(STEPPER_PIN_8, HIGH);



  digitalWrite(STEPPER_PIN_9, LOW);
  digitalWrite(STEPPER_PIN_10, LOW);
  digitalWrite(STEPPER_PIN_11, LOW);
  digitalWrite(STEPPER_PIN_12, HIGH);


  digitalWrite(STEPPER_PIN_13, LOW);
  digitalWrite(STEPPER_PIN_14, LOW);
  digitalWrite(STEPPER_PIN_15, LOW);
  digitalWrite(STEPPER_PIN_16, HIGH);
  break;
  case 2:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, HIGH);

  digitalWrite(STEPPER_PIN_5, LOW);
  digitalWrite(STEPPER_PIN_6, LOW);
  digitalWrite(STEPPER_PIN_7, LOW);
  digitalWrite(STEPPER_PIN_8, HIGH);


  digitalWrite(STEPPER_PIN_9, LOW);
  digitalWrite(STEPPER_PIN_10, LOW);
  digitalWrite(STEPPER_PIN_11, LOW);
  digitalWrite(STEPPER_PIN_12, HIGH);


  digitalWrite(STEPPER_PIN_13, LOW);
  digitalWrite(STEPPER_PIN_14, LOW);
  digitalWrite(STEPPER_PIN_15, LOW);
  digitalWrite(STEPPER_PIN_16, HIGH);
  break;
  case 3:
  digitalWrite(STEPPER_PIN_1, LOW);
  digitalWrite(STEPPER_PIN_2, LOW);
  digitalWrite(STEPPER_PIN_3, LOW);
  digitalWrite(STEPPER_PIN_4, HIGH);
 
  digitalWrite(STEPPER_PIN_5, LOW);
  digitalWrite(STEPPER_PIN_6, LOW);
  digitalWrite(STEPPER_PIN_7, LOW);
  digitalWrite(STEPPER_PIN_8, HIGH); 


  digitalWrite(STEPPER_PIN_9, LOW);
  digitalWrite(STEPPER_PIN_10, LOW);
  digitalWrite(STEPPER_PIN_11, LOW);
  digitalWrite(STEPPER_PIN_12, HIGH);


  digitalWrite(STEPPER_PIN_13, LOW);
  digitalWrite(STEPPER_PIN_14, LOW);
  digitalWrite(STEPPER_PIN_15, LOW);
  digitalWrite(STEPPER_PIN_16, HIGH);
} 
  }
  
  // Increment step_number and handle wrapping around if necessary
  step_number++;
  if (step_number > 4) {
    step_number = 0;
  }
}
