/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\nrlei                                            */
/*    Created:      Fri Sep 17 2021                                           */
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

const float ONE_BLOCK_DEG = 228;
const float TWO_BLOCK_DEG = 430;

void initArm() {
  armMotor.setStopping(hold);
  armMotor.setTimeout(5, seconds);
}

void moveArm(float pos) {
  armMotor.spinToPosition(pos, degrees);
}

void initClaw() {
  clawMotor.setStopping(hold);
  clawMotor.setMaxTorque(30, percent);
  clawMotor.setTimeout(1, seconds);
}

void openClaw() {
  clawMotor.spinToPosition(-180, degrees);
}

void closeClaw() {
  clawMotor.spinToPosition(-10, degrees);
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  initArm();
  initClaw();
  openClaw();
  wait(2, seconds);
  closeClaw();
  wait(1, seconds);
  moveArm(TWO_BLOCK_DEG);
  wait(1, seconds);
  openClaw();



  
  
}
