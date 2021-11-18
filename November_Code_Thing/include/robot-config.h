using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor BR;
extern motor BL;
extern motor FR;
extern motor FL;
extern controller Controller1;
extern motor GoalLift;
extern motor RingRamp;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );