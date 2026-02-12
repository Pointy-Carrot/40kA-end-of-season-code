#include "misc/robot_init.h"
#include "lemlib/chassis/chassis.hpp"
#include "lemlib/chassis/trackingWheel.hpp"
#include "misc/subsystems/pneumatics.h"
#include "pros/abstract_motor.hpp"
#include "pros/adi.hpp"
#include "pros/distance.hpp"
#include "pros/motor_group.hpp"
#include "pros/rotation.hpp"


// pros controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);

// pros intake motors
pros::MotorGroup intake_motors({-4, 7}, pros::MotorGearset::blue);

// pros drivetrain motor groups
pros::MotorGroup left_drivetrain({-1, 2, -3}, pros::MotorGearset::blue);
pros::MotorGroup right_drivetrain({10, -9, 8}, pros::MotorGearset::blue);

// pros pistons
pros::adi::Pneumatics matchloader_piston('C', false);
pros::adi::Pneumatics wing_piston('D', false);
pros::adi::Pneumatics gate_piston('B', false);
pros::adi::Pneumatics undergoal_piston('A', false);
pros::adi::Pneumatics wing_extender_piston('E', false);

// SafePneumatics pistons
SafePneumatics loader(&matchloader_piston);
SafePneumatics wing(&wing_piston);
SafePneumatics gate(&gate_piston);
SafePneumatics undergoal(&undergoal_piston);
SafePneumatics wing_extender(&wing_extender_piston);

// pros sensors
pros::Rotation horizontal_tracking_wheel(-12);
pros::Rotation vertical_tracking_wheel(-20);
pros::Distance left_distance(5);
pros::Distance right_distance(6);
pros::Imu imu(11);

// Intake intake
Intake intake(&intake_motors);

// lemlib constructors
lemlib::TrackingWheel horiz_tracker(&horizontal_tracking_wheel, lemlib::Omniwheel::OLD_275_HALF, -5);
lemlib::TrackingWheel vert_tracker(&vertical_tracking_wheel, lemlib::Omniwheel::OLD_275_HALF, -.25);
lemlib::OdomSensors sensors(&vert_tracker, nullptr, &horiz_tracker, nullptr, &imu);
lemlib::ControllerSettings lateral_controller(16, 0, 700, 3, 1, 100, 3, 500, 20);
lemlib::ControllerSettings angular_controller(4, 0, 36, 1, 1, 100, 3, 500, 0);
lemlib::Drivetrain drivetrain(&left_drivetrain, &right_drivetrain, 10, lemlib::Omniwheel::NEW_4, 400, 2);
lemlib::Chassis chassis(drivetrain, lateral_controller, angular_controller, sensors);


// DistMove distance
DistMove distance(&left_distance, 7, &right_distance, 7, &chassis);