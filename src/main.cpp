#include "main.h"
#include "lemlib/api.hpp"

void initialize() {
	pros::lcd::initialize();

}


void disabled() {}


void competition_initialize() {}


void autonomous() {}


void opcontrol() {
	
	while (true) {
		pros::delay(20); 
	}
}