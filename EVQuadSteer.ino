#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Define the I2C address for the PCA9685
#define PCA9685_ADDRESS 0x40

// Create an instance of the Adafruit_PWMServoDriver class
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(PCA9685_ADDRESS);

// Define the servo motor parameters
#define SERVO_MIN_PULSE_WIDTH 200
#define SERVO_MAX_PULSE_WIDTH 400
#define SERVO_MAX_DEGREE 180

// Define the servo motor channels
const int FrontRight = 0; // Channel number for servoMotor1
const int FrontLeft = 3;
const int BackRight = 1; // Channel number for servoMotor1
const int BackLeft = 2;

// Stepper motor pins
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

// Define the number of steps for stepper motor
int step_number = 5;

// Variables for timing
unsigned long previousMillis = 0;
const long interval = 1000; // Interval for servo movement in milliseconds

bool moveTo45Degrees = true;
bool moveTo90Degrees = false;
bool moveTo0Degrees = false;

// Enum for states
enum State {
  MOVE_TO_45,
  MOVE_TO_180,
  MOVE_TO_0,
  STOP_CAR
};

State state = MOVE_TO_45;

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);

  // Initialize the PCA9685
  pwm.begin();
  
  // Set PWM frequency to 50 Hz
  pwm.setPWMFreq(50);

  setServoAngle(FrontRight, 0);
  setServoAngle(FrontLeft, 0);
  setServoAngle(BackRight, 0);
  setServoAngle(BackLeft, 0);
  
  // Set stepper motor pins as outputs
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



void loop() 
{
  // Get the current time
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    // Update the timing for the next interval
    previousMillis = currentMillis;

    switch (state) {
      case MOVE_TO_45:
        setServoAngle(FrontRight, 90);
        setServoAngle(FrontLeft, 90);
        setServoAngle(BackRight, 0);
        setServoAngle(BackLeft, 0);

        state = MOVE_TO_0;
        break;

      case MOVE_TO_0:
        setServoAngle(FrontRight, 0);
        setServoAngle(FrontLeft, 0);
        setServoAngle(BackRight, 0);
        setServoAngle(BackLeft, 0);

        state = MOVE_TO_180;
        break;

      case MOVE_TO_180:
        setServoAngle(FrontRight, 180);
        setServoAngle(FrontLeft, 180);
        setServoAngle(BackRight, 180);
        setServoAngle(BackLeft, 180);

        state = STOP_CAR;//state = MOVE_TO_0;
        break;

      case STOP_CAR:
        setServoAngle(FrontRight, 0);
        setServoAngle(FrontLeft, 0);
        setServoAngle(BackRight, 0);
        setServoAngle(BackLeft, 0);
        state = MOVE_TO_45;
        break;

      default:
        setServoAngle(FrontRight, 0);
        setServoAngle(FrontLeft, 0);
        setServoAngle(BackRight, 0);
        setServoAngle(BackLeft, 0);
        break;
    }

    //Stop the car
    //setServoAngle(FrontRight, 0);
    //setServoAngle(FrontLeft, 0);
    //setServoAngle(BackRight, 0);
    //setServoAngle(BackLeft, 0);
  }


  // Run stepper motor code
  for (int a = 0; a < 4000; a++) { // the 4000 is the number of steps for a full rotation
    OneStep(true);
    delay(2); // Minimum divide between steps. Higher the number, slower the motor will go.
  }
}

// Function to set the angle of a servo motor
void setServoAngle(uint8_t channel, int angle) {
  uint16_t pulse_width = map(angle, 0, SERVO_MAX_DEGREE, SERVO_MIN_PULSE_WIDTH, SERVO_MAX_PULSE_WIDTH);
  pwm.setPWM(channel, 0, pulse_width);
}

// Function to perform one step for the stepper motor
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
  
  
step_number++;
  if(step_number > 4){
    step_number = 0;
  }
}