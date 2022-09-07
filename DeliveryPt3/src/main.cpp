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

const float ONE_BLOCK_DEG = 234;
const float TWO_BLOCK_DEG = 430;

void setVelocity(float driveVelo, float turnVelo){
  Drivetrain.setDriveVelocity(driveVelo, percent);
  Drivetrain.setTurnVelocity(turnVelo, percent);
}

void moveArm(float pos) {
  armMotor.spinToPosition(pos, degrees);
}

void openClaw() {
  clawMotor.spinToPosition(-180, degrees);
}

void closeClaw() {
  clawMotor.spinToPosition(-10, degrees);
}

void grabCan(){
  openClaw();
  wait(2, seconds);
  closeClaw();
}

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

void flipTurn(){
  Drivetrain.turnToHeading(TURN_180_VALE, degrees);
  wait(2, seconds);
}

void deliverySet(float X1, float Y1, float X2, float Y2, float head){
  doDelivery(true, X1, Y1, head, ONE_BLOCK_DEG);
  doDelivery(false, X2, Y2, head, TWO_BLOCK_DEG);
}

void initArm() {
  armMotor.setStopping(hold);
  armMotor.setTimeout(5, seconds);
}

void initClaw() {
  clawMotor.setStopping(hold);
  clawMotor.setMaxTorque(30, percent);
  clawMotor.setTimeout(1, seconds);
}



int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  initArm();
  initClaw();
  //setVelocity(10, 5);
  deliverySet(12*4.8, 4, 12*4, 12*3, 0);
  flipTurn();
  deliverySet(12*2.9, 4, 24, 12*4.33, 180);
  
  
}

