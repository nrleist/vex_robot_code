using namespace vex;

extern brain Brain;

// VEXcode devices
extern smartdrive Drivetrain;
extern bumper rearBumper;
extern bumper ArmBumper;
extern motor ArmMotor;
extern motor ClawMotor;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );