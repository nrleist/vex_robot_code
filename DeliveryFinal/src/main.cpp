/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\nrlei                                            */
/*    Created:      Fri Sep 10 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 10, 9        
// armMotor             motor         8               
// clawMotor            motor         3               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

const float TURN_VALUE = 90;
const float TURN_180_VALE = 180; 

const float ONE_BLOCK_DEG = 255;
const float TWO_BLOCK_DEG = 430;

//Set drive and turn velocity
void setVelocity(float driveVelo, float turnVelo){
  Drivetrain.setDriveVelocity(driveVelo, percent);
  Drivetrain.setTurnVelocity(turnVelo, percent);
}

//Move arm to pos
void moveArm(float pos) {
  armMotor.spinToPosition(pos, degrees);
}

//Open the claw
void openClaw() {
  clawMotor.spinToPosition(-180, degrees);
}

//Close the claw
void closeClaw() {
  clawMotor.spinToPosition(-10, degrees);
}

//Grab a can
void grabCan(){
  openClaw();
  wait(2, seconds);
  closeClaw();
}

//Make a delivery and go bach to start
void doDelivery(bool turnRight, float XInches, float YInches, float head, int deg){
  grabCan();
  moveArm(deg);
  wait(1, seconds);
  Drivetrain.driveFor(forward, XInches, inches);
  if(turnRight) {
    Drivetrain.turnToHeading(90, degrees);
    Drivetrain.driveFor(forward, YInches, inches);
    wait(2, seconds);
    openClaw();
    wait(1, seconds);
    Drivetrain.driveFor(reverse, YInches, inches);
    Drivetrain.turnToHeading(head, degrees);
  } else{
    Drivetrain.turnToHeading(270, degrees);
    Drivetrain.driveFor(forward, YInches, inches);
    wait(2, seconds);
    openClaw();
    wait(1, seconds);
    Drivetrain.driveFor(reverse, YInches, inches);
    Drivetrain.turnToHeading(head, degrees);
  }
  Drivetrain.driveFor(reverse, XInches, inches);
  moveArm(0);
  wait(3, seconds);
}

//Turn robot 180 degrees
void flipTurn(float head){
  Drivetrain.turnToHeading(head, degrees);
  wait(2, seconds);
}

//Do one side of the delivery
void deliverySet(float X1, float Y1, float X2, float Y2, float head){
  doDelivery(true, X1, Y1, head, ONE_BLOCK_DEG);
  doDelivery(false, X2, Y2, head, TWO_BLOCK_DEG);
}

//Set up the arm 
void initArm() {
  armMotor.setStopping(hold);
  armMotor.setTimeout(5, seconds);
}

//Set up the claw
void initClaw() {
  clawMotor.setStopping(hold);
  clawMotor.setMaxTorque(30, percent);
  clawMotor.setTimeout(1, seconds);
}

//Main control loop(repeat 6 times)
void mainLoop(float inches_travel) {
  for(int i=0; i<6; i++) {
    moveArm(0);
    grabCan();
    moveArm(ONE_BLOCK_DEG);
    Drivetrain.turnToHeading(i*7.5, degrees);
    Drivetrain.driveFor(forward, inches_travel, inches);
    openClaw();
    Drivetrain.driveFor(reverse, 8, inches);
    flipTurn((i*10)+180);
    Drivetrain.driveFor(forward, inches_travel-8, inches);
    //Drivetrain.turnToHeading(0, degrees);
    wait(1, seconds);
  }
}



int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  initArm();
  initClaw();
  //setVelocity(10, 5);
  mainLoop(3*12);
  
  
  
}


