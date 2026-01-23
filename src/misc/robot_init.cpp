#include "misc/robot_init.h"
#include "lemlib/chassis/chassis.hpp"
#include "lemlib/chassis/trackingWheel.hpp"
#include "misc/subsystems/pneumatics.h"
#include "pros/adi.hpp"
#include "pros/device.hpp"
#include "pros/distance.hpp"
#include "pros/motor_group.hpp"
#include "pros/optical.hpp"
#include "pros/rotation.hpp"

// pros controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);
// pros intake motors
pros::Motor left_intake_motor(1);
pros::Motor right_intake_motor(2);
// pros drivetrain motor groups
pros::MotorGroup left_drivetrain({3, 4, 5}, pros::MotorGearset::blue);
pros::MotorGroup right_drivetrain({6, 7, 8}, pros::MotorGearset::blue);
// pros pistons
pros::adi::Pneumatics matchloader_piston('A', false);
pros::adi::Pneumatics wing_piston('B', false);
pros::adi::Pneumatics gate_piston('C', false);
pros::adi::Pneumatics undergoal_piston('D', false);
// SafePneumatics pistons
SafePneumatics loader(&matchloader_piston);
SafePneumatics wing(&wing_piston);
SafePneumatics gate(&gate_piston);
SafePneumatics undergoal(&undergoal_piston);
// pros sensors
pros::Rotation horizontal_tracking_wheel(9);
pros::Rotation vertical_tracking_wheel(10);
pros::Optical colorsort_op(11);
pros::Distance left_distance(12);
pros::Distance right_distance(13);
pros::Imu imu(14);
// Intake intake
Intake intake(&left_intake_motor, &right_intake_motor, &colorsort_op);
// lemlib constructors
lemlib::TrackingWheel horiz_tracker(&horizontal_tracking_wheel, lemlib::Omniwheel::OLD_275_HALF, 0);
lemlib::TrackingWheel vert_tracker(&vertical_tracking_wheel, lemlib::Omniwheel::NEW_2, 0);
lemlib::OdomSensors sensors(&vert_tracker, nullptr, &horiz_tracker, nullptr, &imu);
lemlib::ControllerSettings lateral_controller(0, 0, 0, 3, 1, 100, 3, 500, 20);
lemlib::ControllerSettings angular_controller(0, 0, 0, 1, 1, 100, 3, 500, 0);
lemlib::Drivetrain drivetrain(&left_drivetrain, &right_drivetrain, 10, lemlib::Omniwheel::NEW_4, 400, 2);
lemlib::Chassis chassis(drivetrain, lateral_controller, angular_controller, sensors);