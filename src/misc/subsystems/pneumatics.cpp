#include "misc/subsystems/pneumatics.h"
#include "pros/adi.hpp"

SafePneumatics::SafePneumatics(pros::adi::Pneumatics* piston) :
piston(piston) {};

void SafePneumatics::extend(){
    piston->extend();
}

void SafePneumatics::retract(){
    piston->retract();
}

void SafePneumatics::toggle(){
    piston->toggle();
}

void SafePneumatics::set_value(int value){
    piston->set_value(value);
}

bool SafePneumatics::is_extended(){
    return piston->is_extended();
}