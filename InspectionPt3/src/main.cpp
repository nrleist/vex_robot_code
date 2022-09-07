/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\nrlei                                            */
/*    Created:      Tue Oct 12 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 10, 9        
// ArmMotor             motor         8               
// CenterLineTracker    line          H               
// ArmBumper            bumper        B               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

const int THRESHOLD = 60;

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

void driveToRoom(bool leftTurn, double heading) {
    Drivetrain.drive(forward);
    wait(750, msec);
    waitUntil(CenterLineTracker.value(pct)>THRESHOLD);
    Drivetrain.stop(brake);
    doInspection();
    if(leftTurn) {
      Drivetrain.turnToHeading(heading, degrees);
    }
}


int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
 
  driveToRoom(false, 0);
  driveToRoom(true, 270);
  driveToRoom(true, 180);
  driveToRoom(false, 0);
  
}
