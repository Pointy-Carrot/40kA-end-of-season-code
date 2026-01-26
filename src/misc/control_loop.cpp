#include "misc/control_loop.h"
#include "misc/robot_init.h"
#include "misc/subsystems/intake.h"


void driver_wing(){
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y)){ // hold Y -> wing down
        wing.retract();
    } else{
        wing.extend();
    }
}

void driver_loader(){
    if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)){ // press B -> toggle loader
        loader.toggle();
    }
}

void driver_undergoal(){
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)){ // hold RIGHT -> undergoal down
        undergoal.extend();
    } else{
        undergoal.retract();
    }
}

void driver_intake(){
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){ // hold R1 -> score long
        intake.score_long(127);
    } else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){ // hold R2 -> score mid
        intake.score_mid(127);
    } else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){ // hold L1 -> intake
        intake.intake(127);
    } else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){ // hold L2 -> outtake
        intake.outtake(127);
    }
}

void intake_control_loop(){
    pros::Task intake_control_loop_task([]{
        while(1){
        // switch intake controls
        switch(intake_state){
            case INTAKE:
                gate.retract();
                intake.spin_intake();
            break;
            case OUTTAKE:
                gate.retract();
                intake.spin_intake();
            break;
            case SCORELONG:
                gate.extend();
                intake.spin_intake();
            break;
            case SCOREMID:
                gate.retract();
                intake.spin_intake();
            case STOP:
                intake.stop_intake();
            break;
        }

        pros::delay(20);
    }
    });
}