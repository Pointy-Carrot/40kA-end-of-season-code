#pragma once

#include "pros/adi.hpp"

class SafePneumatics{
    public:

        pros::adi::Pneumatics* piston;

        /**
         * @brief Safe Pneumatics Constructor
         * 
         * @param piston 
         */
        SafePneumatics(pros::adi::Pneumatics* piston);

        /**
         * @brief extends the piston
         * 
         */
        void extend();

        /**
         * @brief retracts the piston
         * 
         */
        void retract();
        
        /**
         * @brief toggles the piston between extended and retracted
         * 
         */
        void toggle();

        /**
         * @brief sets the value of the pisotn
         * 
         * @param value 0->retracted, 1->extended
         */
        void set_value(int value);

        /**
         * @brief returns whether the piston is extended
         * 
         * @return true 
         * @return false 
         */
        bool is_extended();
};