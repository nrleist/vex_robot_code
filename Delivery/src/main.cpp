/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\nrlei                                            */
/*    Created:      Tue Sep 07 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 10           
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  Drivetrain.driveFor(forward, 36, inches, 10, velocityUnits::pct);
  wait(2, seconds);
  Drivetrain.driveFor(reverse, 36, inches, 10, velocityUnits::pct);
  wait(2, seconds);
  Drivetrain.driveFor(forward, 60, inches, 10, velocityUnits::pct);
  wait(2, seconds);
  Drivetrain.driveFor(reverse, 60, inches, 10, velocityUnits::pct);
  wait(2, seconds);
  Drivetrain.driveFor(reverse, 24, inches, 10, velocityUnits::pct);
  wait(2, seconds);
  Drivetrain.driveFor(forward, 24, inches, 10, velocityUnits::pct);
  wait(2, seconds);
  Drivetrain.driveFor(reverse, 60, inches, 10, velocityUnits::pct);
  wait(2, seconds);
  Drivetrain.driveFor(forward, 60, inches, 10, velocityUnits::pct);
}
