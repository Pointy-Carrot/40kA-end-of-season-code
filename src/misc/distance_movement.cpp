#include "misc/distance_movement.h"
#include "pros/distance.hpp"

DistMove::DistMove(pros::Distance* distL, float left_offset, pros::Distance* distR, float right_offset, lemlib::Chassis* chassis) :
distL(distL), left_sensor_offset(left_offset), distR(distR), right_sensor_offset(right_offset), chassis(chassis) {};

float DistMove::reset_for_long_goal(SensorSide sensor_side, Color color){
    if(sensor_side == LEFT){
        if(color == RED){
            return -72+left_sensor_offset+red_left_offset+(distL->get_distance())/25.4;
            // chassis->setPose(chassis->getPose().x, -72+left_sensor_offset+red_left_offset, chassis->getPose().theta);
        } else{
            return 72-left_sensor_offset-red_right_offset-(distL->get_distance())/25.4;
            // chassis->setPose(chassis->getPose().x, 72-left_sensor_offset-red_right_offset, chassis->getPose().theta);
        }
    } else{
        if(color == RED){
            return 72-right_sensor_offset-red_right_offset-(distR->get_distance())/25.4;
            // chassis->setPose(chassis->getPose().x, 72-right_sensor_offset-red_right_offset, chassis->getPose().theta);
        } else{
            return -72+right_sensor_offset+blue_right_offset+(distR->get_distance())/25.4;
            // chassis->setPose(chassis->getPose().x, -72+right_sensor_offset+blue_right_offset, chassis->getPose().theta);
        }
    }
}