#include "main.h"
#include "misc/robot_init.h"
#include "pros/misc.h"

void initialize() {
	pros::lcd::initialize();
	chassis.calibrate();
}


void disabled() {}


void competition_initialize() {}


void autonomous() {}


void opcontrol() {
	
	while (true) {
		int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
		int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

		chassis.arcade(leftY, rightX);
		
		pros::delay(20); 
	}
}