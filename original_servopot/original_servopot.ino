#include <Servo.h> //import servo library

//Set pin definitions
#define SERVO_PIN 2
#define POT_PIN A0 //pot is short for ‘potentiometer’

//Make Servo Object
Servo MyServo;

//setup a variable for pot value
uint16_t pot_value;

void setup()
{
  //tell the Arduino what is connected to it
  //eg. output on SERVO_PIN, and input on POT_PIN
  MyServo.attach(SERVO_PIN);
  pinMode(POT_PIN, INPUT);
}

void loop()
{
  //read the potentiometer
  pot_value = analogRead(POT_PIN);

  //convert the pot_value into the servo's max and min
  uint16_t servo_angle = map(pot_value, 0, 1023, 0, 180);

  //Tell the servo to move to the angle
  MyServo.write(servo_angle); 
}
