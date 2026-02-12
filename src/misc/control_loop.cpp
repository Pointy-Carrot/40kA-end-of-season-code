#include "misc/control_loop.h"
#include "misc/robot_init.h"
#include "misc/subsystems/intake.h"
#include "pros/misc.h"

bool initial_intaking = false;
bool currently_intaking = false;

void driver_wing(){
    if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)){ // press Y -> toggle wing
        if(!undergoal.is_extended()){
            wing.toggle();
        }
    } else{
        if(undergoal.is_extended()){
            wing.retract();
        }
    }
    if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)){ // press B -> toggle full
        if(!undergoal.is_extended()){
            if(wing_extender.is_extended()){
                wing_extender.retract();
                wing.retract();
            } else{
                wing_extender.extend();
                wing.extend();
            }
        }
    }
}

void driver_loader(){
    if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)){ // press RIGHT -> toggle loader
        if(!undergoal.is_extended()){
            loader.toggle();
        }
    }
}

void driver_undergoal(){
    if(controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)){ // press L2 -> toggle undergoal
        if(undergoal.is_extended()){
            undergoal.retract();
            wing_extender.extend();
            wing.extend();
        } else{
            undergoal.extend();
            wing_extender.retract();
            wing.retract();
        }
    }
}

void driver_intake(){
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){ // hold L1 -> score long
        intake.score_long(600);
    } else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){ // hold R2 -> intake
        intake.intake(600);
    } else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){ // hold R1 -> outtake
        intake.outtake(600);
    } else{
        intake.brake();
    }
}

void intake_control_loop(){
    pros::Task intake_control_loop_task([]{
        while(1){
        // switch intake controls
        switch(intake_state){
            case INTAKE:
                currently_intaking = false;
                initial_intaking = false;
                gate.retract();
                intake.spin_intake();
            break;
            case OUTTAKE:
                currently_intaking = false;
                initial_intaking = false;
                gate.retract();
                intake.spin_intake();
            break;
            case SCORELONG:
                if(abs(intake.get_velocity()) == 0 && !currently_intaking){
                    initial_intaking = true;
                }
                if(initial_intaking){
                    intake.set_rpms(-600);
                    intake.spin_intake();
                    pros::delay(125);
                    intake.stop_intake();
                    initial_intaking = false;
                }
                currently_intaking = true;
                gate.extend();
                intake.spin_intake();
            break;
            case SCOREMID:
                currently_intaking = false;
                initial_intaking = false;
                gate.retract();
                intake.spin_intake();
            break;
            case STOP:
                currently_intaking = false;
                initial_intaking = false;
                intake.stop_intake();
            break;
        }

        pros::delay(20);
    }
    });
}