#include "misc/subsystems/intake.h"
#include "pros/motors.hpp"
#include "pros/optical.hpp"

Intake::Intake(pros::Motor* intakeL, pros::Motor* intakeR, pros::Optical* sorter) :
intakeL(intakeL), intakeR(intakeR), sorter(sorter) {};