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
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

const float TURN_VALUE = 90;
const float TURN_180_VALE = 180; 

void setVelocity(float driveVelo, float turnVelo){
  Drivetrain.setDriveVelocity(driveVelo, percent);
  Drivetrain.setTurnVelocity(turnVelo, percent);
}

void doDelivery(bool turnRight, float XInches, float YInches, float head){
  Drivetrain.driveFor(forward, XInches, inches);
  if(turnRight) {
    Drivetrain.turnToHeading(90, degrees);
    Drivetrain.driveFor(forward, YInches, inches);
    wait(2, seconds);
    Drivetrain.driveFor(reverse, YInches, inches);
    Drivetrain.turnToHeading(head, degrees);
  } else{
    Drivetrain.turnToHeading(270, degrees);
    Drivetrain.driveFor(forward, YInches, inches);
    wait(2, seconds);
    Drivetrain.driveFor(reverse, YInches, inches);
    Drivetrain.turnToHeading(head, degrees);
  }
  Drivetrain.driveFor(reverse, XInches, inches);
  wait(2, seconds);
}

void flipTurn(){
  Drivetrain.turnToHeading(TURN_180_VALE, degrees);
  wait(2, seconds);
}

void deliverySet(float X1, float Y1, float X2, float Y2, float head){
  doDelivery(true, X1, Y1, head);
  doDelivery(false, X2, Y2, head);
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  //setVelocity(10, 5);
  deliverySet(12*5, 12, 12*4, 12*4, 0);
  flipTurn();
  deliverySet(12*3, 12, 24, 12*5, 180);
  
  
}
