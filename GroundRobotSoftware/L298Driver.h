/*
LI INDUSTRIAL TECHNOLOGIES
Software Division
L298 Driver SOFTWARE 1.2

notes for each command are stationed in each section

*/

class L298Driver
{
  //variables for the pins
 int EnA; 
 int EnB;
 int In1;
 int In2;
 int In3;
 int In4;
 bool textprintchecker = true;
 
 public: L298Driver(int enable1, int Input1, int Input2, int Input3, int Input4, int enable2){ //constructor
   EnA = enable1;
   EnB = enable2;
   In1 = Input1;
   In2 = Input2;
   In3 = Input3;
   In4 = Input4;

 }
 public: void StartMotorController() { //call this in setup loop to start the controller
   pinMode(EnA, OUTPUT);
   pinMode(EnB, OUTPUT);
   pinMode(In1, OUTPUT);
   pinMode(In2, OUTPUT);
   pinMode(In3, OUTPUT);
   pinMode(In4, OUTPUT);
   Serial.println("L298N boot ok");
 }
 public: void LmotorMove(boolean Movedirection, int movespeed){ //Moves left motor. Syntax Motorcontrollername.LmotorMove(direction, speed); FALSE = forward TRUE = backwards
  String type ="Left Motor Moving";
  String movementdirection = "";
  if(Movedirection = false){
    digitalWrite(In1, HIGH); // left motor move
    digitalWrite(In2, LOW);
    movementdirection = "Forward";
  }
  else if(Movedirection = true){
    digitalWrite(In1, LOW); // left motor move
    digitalWrite(In2, HIGH);
    movementdirection = "Backward";
  }
  analogWrite(EnA, movespeed); //leftmovespeed
  MovePrinter(type,movementdirection,movespeed);
 }
 public: void RmotorMove(boolean Movedirection, int movespeed){ // Moves right motor. Syntax Motorcontrollername.RmotorMove(direction,speed); FALSE = forward TRUE = backwards
  String type ="Right Motor Moving";
  String movementdirection = "";
  if(Movedirection = false){
    digitalWrite(In3, HIGH); // right motor move
    digitalWrite(In4, LOW);
    movementdirection = "Forward";
  }
  else if(Movedirection = true){
    digitalWrite(In3, LOW); // right motor move
    digitalWrite(In4, HIGH);
    movementdirection = "Backward";
  }
  analogWrite(EnB, movespeed); //rightmovespeed 
  MovePrinter(type,movementdirection,movespeed);
 }
 public: void BothMove(boolean Movedirection, int movespeed){ //Moves both motors. Syntax Motorcontrollername.BothMove(direction,speed); FALSE = forward TRUE = backwards
  String type ="Both Motors Moving";
  String movementdirection = "";
  if(Movedirection = false){
    digitalWrite(In1, HIGH); // left motor move
    digitalWrite(In2, LOW);
    digitalWrite(In3, HIGH); // right motor move
    digitalWrite(In4, LOW);
    movementdirection = "Forward";
  }
  else if(Movedirection = true){
    digitalWrite(In1, LOW); // left motor move
    digitalWrite(In2, HIGH);
    digitalWrite(In3, LOW); // right motor move
    digitalWrite(In4, HIGH);
    movementdirection = "Backward";
  }
  analogWrite(EnA, movespeed); //leftmovespeed
  analogWrite(EnB, movespeed); //rightmovespeed 
  MovePrinter(type,movementdirection,movespeed);
 }
 public: void MovePrinter(String type, String movementdirection, int movespeed) { //prints the movement text. Can be disabled
  if(textprintchecker == true || Serial.read() != -1) {
  Serial.print("Move Type---"); Serial.println(type);
  Serial.print("move direction---"); Serial.println(movementdirection);
  Serial.print("move speed---");  Serial.println(movespeed);
  }
 }
 public: void TurnMove(boolean Movedirection, int movespeed) { // Turns the robot. Syntax Motorcontrollername.TurnMove(turndirection, speed); TRUE = clockwise FALSE = counterclockwise
  String type ="Turning";
  String movementdirection = "";
  if(Movedirection = false){
    digitalWrite(In1, HIGH); // left motor move
    digitalWrite(In2, LOW);
    digitalWrite(In3, LOW); // right motor move
    digitalWrite(In4, HIGH);
    movementdirection = "Clockwise";
  }
  else if(Movedirection = true){
    digitalWrite(In1, LOW); // left motor move
    digitalWrite(In2, HIGH);
    digitalWrite(In3, HIGH); // right motor move
    digitalWrite(In4, LOW);
    movementdirection = "Counterclockwise";
  }
  analogWrite(EnA, movespeed); //leftmovespeed
  analogWrite(EnB, movespeed); //rightmovespeed 
  MovePrinter(type,movementdirection,movespeed);
 }
 public: void MovePrintSet(boolean Onoroff){ //sets the text display for serial control. Syntac Motorcontrollername.MovePrintSet(boolean). TRUE = on, FALSE = off
  textprintchecker = Onoroff;
 }
};
