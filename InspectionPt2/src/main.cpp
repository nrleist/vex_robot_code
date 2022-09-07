/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\nrlei                                            */
/*    Created:      Mon Oct 04 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 10, 9        
// rearBumper           bumper        H               
// ArmBumper            bumper        G               
// ArmMotor             motor         8               
// ClawMotor            motor         3               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

void doInspection() {
  Brain.Screen.drawCircle(255, 125, 90, red);
  ArmMotor.spinToPosition(300, degrees);
  wait(2, seconds);
  Brain.Screen.drawCircle(255, 125, 90, green);
  wait(2, seconds);
  ArmMotor.spin(reverse);
  waitUntil(ArmBumper.pressing());
  Brain.Screen.drawCircle(255, 125, 90, white);
}

void setVelocity(float driveVelo, float turnVelo){
  Drivetrain.setDriveVelocity(driveVelo, percent);
  Drivetrain.setTurnVelocity(turnVelo, percent);
}

void firstRoom(){
  Drivetrain.driveFor(forward, 12*3, inches);
  Drivetrain.turnToHeading(270, degrees); 
  Drivetrain.driveFor(forward, 12*1.5, inches);
  doInspection();
}

void secondRoom(){
  Drivetrain.turnToHeading(0, degrees); 
  Drivetrain.driveFor(forward, 12*3, inches);
  doInspection();
}

void thirdRoom(){
  Drivetrain.turnToHeading(90, degrees); 
  Drivetrain.driveFor(forward, 12*3, inches);
  doInspection();
}

void fourthRoom(){
  Drivetrain.turnToHeading(180, degrees); 
  Drivetrain.driveFor(forward, 12*3, inches);
  doInspection();
}

void initArm() {
  ArmMotor.setStopping(hold);
  ArmMotor.setTimeout(5, seconds);
}

//Set up the claw
void initClaw() {
  ClawMotor.setStopping(hold);
  ClawMotor.setMaxTorque(30, percent);
  ClawMotor.setTimeout(1, seconds);
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  //setVelocity(10, 5);
  firstRoom();
  secondRoom();
  thirdRoom();
  fourthRoom();
  
}