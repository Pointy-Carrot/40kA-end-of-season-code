#pragma once
#include "lemlib/chassis/chassis.hpp"
#include "pros/distance.hpp"

class DistReset{
    private:

    public:

        pros::Distance* distL;
        pros::Distance* distR;

        DistReset(pros::Distance* distL, pros::Distance* distR);

};