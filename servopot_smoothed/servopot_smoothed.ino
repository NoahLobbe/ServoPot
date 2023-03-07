#include <Servo.h> //import servo library

//Set pin definitions
#define SERVO_PIN 2
#define POT_PIN A0

//Make Servo Object
Servo MyServo;

//setup a variable for pot value
uint16_t pot_value;

//setup variable for motion smoothing
float prev_smoothed_angle;

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

  //calculate smoothed servo angle. Automatically casts to int, rounding down, when passed to Servo
  float smoothed_angle = (servo_angle * 0.05) + (prev_smoothed_angle * 0.95);
  
  //update prev_smoothed_angle
  prev_smoothed_angle = smoothed_angle;

  //Tell the servo to move to the new smoothed angle
  MyServo.write(smoothed_angle); 
}
