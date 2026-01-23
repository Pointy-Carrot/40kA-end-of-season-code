#include "misc/distance_reset.h"
#include "pros/distance.hpp"

DistReset::DistReset(pros::Distance* distL, pros::Distance* distR) :
distL(distL), distR(distR) {};

