#pragma once

#include "lemlib/chassis/chassis.hpp"
#include "lemlib/chassis/trackingWheel.hpp"
#include "pros/adi.hpp"
#include "pros/misc.hpp"
#include "pros/motors.hpp"
#include "pros/motor_group.hpp"
#include "pros/distance.hpp"
#include "pros/rotation.hpp"
#include "pros/optical.hpp"
#include "lemlib/api.hpp"
#include "misc/subsystems/pneumatics.h"
#include "misc/subsystems/intake.h"
#include "misc/distance_movement.h"


extern pros::Controller controller;

extern pros::MotorGroup intake_motors;

extern pros::MotorGroup left_drivetrain;
extern pros::MotorGroup right_drivetrain;

extern pros::adi::Pneumatics matchloader_piston;
extern pros::adi::Pneumatics wing_piston;
extern pros::adi::Pneumatics gate_piston;
extern pros::adi::Pneumatics undergoal_piston;
extern pros::adi::Pneumatics wing_extender_piston;

extern SafePneumatics loader;
extern SafePneumatics wing;
extern SafePneumatics gate;
extern SafePneumatics undergoal;
extern SafePneumatics wing_extender;

extern pros::Rotation horizontal_tracking_wheel;
extern pros::Rotation vertical_tracking_wheel;
extern pros::Distance left_distance;
extern pros::Distance right_distance;
extern pros::Imu imu;

extern Intake intake;

extern lemlib::TrackingWheel horiz_tracker;
extern lemlib::TrackingWheel vert_tracker;
extern lemlib::OdomSensors sensors;
extern lemlib::ControllerSettings lateral_controller;
extern lemlib::ControllerSettings angular_controller;
extern lemlib::Drivetrain drivetrain;
extern lemlib::Chassis chassis;
extern lemlib::ExpoDriveCurve throttle_curve;
extern lemlib::ExpoDriveCurve steer_curve;

extern DistMove distance;