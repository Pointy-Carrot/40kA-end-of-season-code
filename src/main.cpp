#include "main.h"
#include "misc/robot_init.h"
#include "pros/misc.h"
#include "misc/control_loop.h"


void initialize() {
	pros::lcd::initialize();
	chassis.calibrate();
	intake_control_loop();
}


void disabled() {}


void competition_initialize() {}


void autonomous() {}


void opcontrol() {
	
	while (true) {
		int leftY = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
		int rightX = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);

		chassis.arcade(leftY, rightX);
		driver_wing();
		driver_intake();
		driver_loader();
		driver_undergoal();
		pros::delay(20); 
	}
}