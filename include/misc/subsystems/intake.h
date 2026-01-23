#pragma once

#include "pros/motors.hpp"
#include "pros/optical.hpp"

class Intake{
    private:

    public:
    
        pros::Motor* intakeL;
        pros::Motor* intakeR;
        pros::Optical* sorter;

        Intake(pros::Motor* intakeL, pros::Motor* intakeR, pros::Optical* sorter);

};