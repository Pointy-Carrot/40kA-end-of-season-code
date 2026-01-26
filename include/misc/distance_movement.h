#pragma once
#include "lemlib/chassis/chassis.hpp"
#include "pros/distance.hpp"

enum SensorSide {LEFT, RIGHT};
enum Color {RED, BLUE};

class DistMove{
    private:
        float left_sensor_offset;
        float right_sensor_offset;
        const float red_left_offset = 0;
        const float red_right_offset = 0;
        const float blue_left_offset = 0;
        const float blue_right_offset = 0;

    public:

        pros::Distance* distL;
        pros::Distance* distR;
        lemlib::Chassis* chassis;

        /**
         * @brief DistMove constructor
         * 
         * @param distL left distance sensor
         * @param left_offset distance between left sensor and middle of bot
         * @param distR right distance sensor
         * @param right_offset distance between right sensor and middle of bot
         * @param chassis chassis object
         */
        DistMove(pros::Distance* distL, float left_offset, pros::Distance* distR, float right_offset, lemlib::Chassis* chassis);
        /**
         * @brief align to a long goal using distance sensor correction
         * 
         * @param side what side sensor to use
         * @param color color of park zone closest to bot
         */
        void reset_for_long_goal(SensorSide sensor_side, Color color);
};