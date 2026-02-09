#include "misc/subsystems/intake.h"
#include "pros/motor_group.hpp"
#include "pros/optical.hpp"

IntakeState intake_state = STOP;

Intake::Intake(pros::MotorGroup* intake_motors) :
intake_motors(intake_motors) {};

void Intake::spin_intake(){
    intake_motors->move_velocity(rpms);
}

void Intake::stop_intake(){
    intake_motors->brake();
}

void Intake::intake(int rpm){
    set_rpms(abs(rpm));
    intake_state = INTAKE;
}

void Intake::outtake(int rpm){
    set_rpms(-abs(rpm));
    intake_state = OUTTAKE;
}

void Intake::score_long(int rpm){
    set_rpms(abs(rpm));
    intake_state = SCORELONG;
}

void Intake::score_mid(int rpm){
    
    set_rpms(abs(rpm));
    intake_state = SCOREMID;
}

void Intake::brake(){
    set_rpms(0);
    intake_state = STOP;
}

void Intake::set_rpms(int rpm){
    rpms = rpm;
}

int Intake::get_rpms(){
    return rpms;
}