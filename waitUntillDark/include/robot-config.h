using namespace vex;

extern brain Brain;

// VEXcode devices
extern smartdrive Drivetrain;
extern line CenterLineTracker;
extern motor ArmMotor;
extern bumper ArmBumper;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );