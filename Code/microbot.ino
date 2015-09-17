
//Build Your Own Robot: MicroBot Version2


#include <AFMotor.h> //import your motor shield library
#include <NewPing.h> //import your ultrasonic sensor library 

#define TRIG_PIN A4 // define trigPin to A3 on the Motor Shield
#define ECHO_PIN A5 // define echoPin to A5 on the motor shield
#define MAX_DISTANCE 200 //sets maximum useable sensor measuring distance to 200cm
AF_DCMotor motor2(2,MOTOR12_1KHZ); // set up motor 1 
AF_DCMotor motor3(3, MOTOR12_1KHZ); // set up motor 2
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);

long duration, distance;

void setup() {
  Serial.begin(9600); // begin serial communitication  
  pinMode(TRIG_PIN, OUTPUT);// set the trig pin to output (Send sound waves)
  pinMode(ECHO_PIN, INPUT);// set the echo pin to input (recieve sound waves)
  motor2.setSpeed(200); //set the speed of the motors, between 0-255
  motor3.setSpeed (200);  
}
 
void loop() {

  long duration, distance; // start the scan
  digitalWrite(TRIG_PIN, LOW);  
  delayMicroseconds(2); // delays are required for a succesful sensor operation.
  
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10); //this delay is required as well!
  
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  
  distance = duration / 58.2;// convert the distance to centimeters.
  
  //if there's an obstacle 25 centimers, ahead, do the following:
  if (distance > 25){  
    
    // Turn as long as there's an obstacle ahead
    motor2.run(FORWARD);  
    motor3.run (BACKWARD);

}
  else {
   //if there's no object in front, Go Forward! 
   delay (15);
   motor2.run(FORWARD); 
   motor3.run(FORWARD);  
  }  
  
}
