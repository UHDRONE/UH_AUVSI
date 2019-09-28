/*
Ground Robot Software

LI INDUSTRIAL TECHNOLOGIES
Software Division
GroundRobot Type S MARK 1.1 SOFTWARE 1.2
*/
#include "L298Driver.h" // adds the controller to the file 
//#include "RobotControlClass.h" //adds the easy commands to the file CURRENTLY NONFUNCTIONAL

L298Driver MC1(5,6,7,8,9,10); //sets up the controller
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  MC1.StartMotorController(); //this needs to be called in order to start motor controller
  MC1.MovePrintSet(true);
}

void loop() {
  // put your main code here, to run repeatedly:
  MC1.BothMove(false,200); //moves both motors
  delay(800);
  MC1.LmotorMove(false,200); //moves left motor
  delay(800);
  MC1.RmotorMove(false,200); //moves right motor
  delay(800);
  MC1.TurnMove(false, 200); //turns clockwise
  delay(800);
  }
