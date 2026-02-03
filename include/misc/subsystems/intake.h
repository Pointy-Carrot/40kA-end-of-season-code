#pragma once

#include "pros/motor_group.hpp"

enum IntakeState {INTAKE, OUTTAKE, SCORELONG, SCOREMID, STOP};

class Intake{
    private:

        int rpms;

    public:
    
        pros::MotorGroup* intake_motors;

        Intake(pros::MotorGroup* intake_motors);

        /**
         * @brief spin intake helper for control loop
         *
         */
        void spin_intake();
        /**
         * @brief stop intake helper for control loop
         * 
         */
        void stop_intake();
        /**
         * @brief intake
         * 
         * @param rpm 
         */
        void intake(int rpm);
        /**
         * @brief outtake
         * 
         * @param rpm 
         */
        void outtake(int rpm);
        /**
         * @brief score into the long goal
         * 
         * @param rpm 
         */
        void score_long(int rpm);
        /**
         * @brief score into the upper mid goal
         * 
         * @param rpm 
         */
        void score_mid(int rpm);
        /**
         * @brief stop the intake
         * 
         */
        void brake();
        /**
         * @brief returns current rpm of intake
         * 
         * @return int rpms
         */
        int get_rpms();
        /**
         * @brief set the current rpm of the intake
         * 
         * @param rpm 
         */
        void set_rpms(int rpm);
};

extern IntakeState intake_state;
