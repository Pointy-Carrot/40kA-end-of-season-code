#include "misc/autons.h"
#include "distance_movement.h"
#include "misc/robot_init.h"

void tuning_prog(){
    chassis.setPose(0, 0, 0);
    chassis.moveToPoint(0, 24, 1000000);
}

void full_sawp(){
    chassis.setPose(-47, -9, 0);

    // clear loader 1
    chassis.moveToPoint(-47, -49, 1250, {.forwards = false});
    loader.extend();
    intake.intake(600);
    chassis.turnToHeading(270, 500);
    chassis.waitUntilDone();
    chassis.setPose(-48, distance.reset_for_long_goal(LEFT, RED), chassis.getPose().theta);
    chassis.moveToPoint(-66, -48, 850, {.maxSpeed = 60});
    chassis.turnToHeading(270, 250);
    chassis.waitUntilDone();
    chassis.setPose(chassis.getPose().x, distance.reset_for_long_goal(LEFT, RED), chassis.getPose().theta);
    // score long goal 1
    chassis.moveToPoint(-30, -49, 750, {.forwards = false, .minSpeed = 70});
    pros::delay(500);
    intake.outtake(450);
    pros::delay(100);
    intake.stop_intake();
    chassis.moveToPoint(0, chassis.getPose().y, 1000, {.forwards = false, .maxSpeed = 50});
    intake.score_long(600);
    pros::delay(1500);
    chassis.setPose(-30, -48, chassis.getPose().theta);
    loader.retract();
    // pick up block pile 1
    chassis.swingToPoint(-26, -24, lemlib::DriveSide::RIGHT, 750);
    chassis.moveToPoint(-26, -24, 1000);
    intake.intake(600);
    chassis.turnToPoint(-24, 24, 250);
    // pick up block pile 2
    chassis.moveToPoint(-24, 20, 1000);
    loader.retract();
    pros::delay(850);
    loader.extend();
    // score mid goal
    chassis.turnToPoint(0, 0, 500, {.forwards = false});
    chassis.moveToPoint(0, 0, 1000, {.forwards = false, .maxSpeed = 70});
    intake.intake(450);
    chassis.moveToPoint(0, 0, 250, {.forwards = false, .maxSpeed = 20});
    chassis.waitUntilDone();
    chassis.setPose(-9, 8, chassis.getPose().theta);
    // clear loader 2

    chassis.moveToPoint(-48, 44, 1250);
    intake.stop_intake();
    chassis.turnToHeading(270, 500);
    intake.intake(600);
    chassis.waitUntilDone();
    chassis.setPose(chassis.getPose().x, distance.reset_for_long_goal(RIGHT, RED), chassis.getPose().theta);
    chassis.moveToPoint(-90, 48, 750, {.maxSpeed = 70});
    chassis.turnToHeading(270, 250);
    chassis.waitUntilDone();
    chassis.setPose(chassis.getPose().x, distance.reset_for_long_goal(RIGHT, RED), chassis.getPose().theta);
    // score long goal 1
    chassis.moveToPoint(-20, 45, 750, {.forwards = false, .minSpeed = 70});
    pros::delay(500);
    intake.outtake(450);
    pros::delay(100);
    intake.stop_intake();
    chassis.moveToPoint(0, chassis.getPose().y, 1000, {.forwards = false, .maxSpeed = 50});
    intake.score_long(600);
}

void right_4block(){}

void left_4block(){}

void right_split_mid(){
    chassis.setPose(-47, -9, 0);
    wing_extender.extend();
    wing.extend();

    // clear loader 1
    chassis.moveToPoint(-47, -49, 1250, {.forwards = false});
    loader.extend();
    intake.intake(600);
    chassis.turnToHeading(270, 500);
    chassis.waitUntilDone();
    chassis.setPose(-48, distance.reset_for_long_goal(LEFT, RED), chassis.getPose().theta);
    chassis.moveToPoint(-66, -48, 850, {.maxSpeed = 60});
    chassis.turnToHeading(270, 250);
    chassis.waitUntilDone();
    chassis.setPose(chassis.getPose().x, distance.reset_for_long_goal(LEFT, RED), chassis.getPose().theta);
    // score long goal 1
    chassis.moveToPoint(-30, -49, 750, {.forwards = false, .minSpeed = 70});
    pros::delay(500);
    intake.outtake(450);
    pros::delay(100);
    intake.stop_intake();
    chassis.moveToPoint(0, chassis.getPose().y, 1000, {.forwards = false, .maxSpeed = 50});
    intake.score_long(600);
    pros::delay(1500);
    chassis.setPose(-30, -48, chassis.getPose().theta);
    loader.retract();
    // pick up block pile 1
    chassis.swingToPoint(-26, -22, lemlib::DriveSide::RIGHT, 750);
    chassis.moveToPoint(-26, -22, 1000);
    intake.intake(600);
    chassis.waitUntilDone();
    // score low mid
    chassis.moveToPoint(-14, -8, 1000);
    chassis.turnToHeading(45, 250);
    intake.outtake(300);
    pros::delay(1000);
    // wing push
    chassis.moveToPoint(-30, -38, 1000, {.forwards = false});
    chassis.turnToPoint(-12, -38, 500);
    chassis.waitUntilDone();
    wing.retract();
    chassis.moveToPoint(-12, -38, 1000);
    chassis.turnToHeading(45, 500);
}

void left_split_mid(){
    chassis.setPose(-47, 9, 180);
    wing.extend();
    wing_extender.extend();

    // clear loader
    chassis.moveToPoint(-47, 49, 1250, {.forwards = false});
    loader.extend();
    intake.intake(600);
    chassis.turnToHeading(270, 500);
    chassis.waitUntilDone();
    chassis.setPose(-48, distance.reset_for_long_goal(RIGHT, RED), chassis.getPose().theta);
    // score long goal 1
    chassis.moveToPoint(-66, 48, 750, {.maxSpeed = 60});
    chassis.turnToHeading(270, 250);
    chassis.waitUntilDone();
    chassis.setPose(chassis.getPose().x, distance.reset_for_long_goal(RIGHT, RED), chassis.getPose().theta);
    chassis.moveToPoint(-30, 48, 750, {.forwards = false, .minSpeed = 70});
    pros::delay(500);
    intake.outtake(450);
    pros::delay(100);
    intake.stop_intake();
    chassis.moveToPoint(0, chassis.getPose().y, 1000, {.forwards = false, .maxSpeed = 50});
    intake.score_long(600);
    pros::delay(1500);
    chassis.setPose(-30, 48, chassis.getPose().theta);
    loader.retract();
    // pick up block pile 1
    chassis.swingToPoint(-24, 24, lemlib::DriveSide::LEFT, 750);
    chassis.moveToPoint(-24, 24, 1000);
    intake.intake(600);
    pros::delay(650);
    loader.extend();
    chassis.waitUntilDone();
    // score upper mid
    chassis.turnToPoint(0, 0, 750, {.forwards = false});
    chassis.moveToPoint(0, 0, 750, {.forwards = false});
    intake.intake(450);
    chassis.moveToPoint(0, 0, 1000, {.forwards = false, .maxSpeed = 20});
    chassis.waitUntilDone();
    chassis.setPose(-9, 8, chassis.getPose().theta);
    // wing push
    chassis.moveToPoint(-34, 36, 1000);
    loader.retract();
    chassis.turnToPoint(-8, 38, 500, {.forwards = false});
    chassis.moveToPoint(-8, 38, 1000, {.forwards = false});
    wing.retract();
    chassis.turnToHeading(315, 500);
}

void right_7block(){}

void left_7block(){}

void prog_skills(){
    chassis.setPose(-47, 9, 180);
    wing.extend();
    wing_extender.extend();

    // clear loader
    chassis.moveToPoint(-47, 49, 1250, {.forwards = false});
    loader.extend();
    intake.intake(600);
    chassis.turnToHeading(270, 500);
    chassis.waitUntilDone();
    chassis.setPose(-48, distance.reset_for_long_goal(RIGHT, RED), chassis.getPose().theta);
    chassis.moveToPoint(-66, 48, 2000, {.maxSpeed = 60});
    chassis.turnToHeading(270, 250);
    chassis.waitUntilDone();
    intake.intake(0);
    chassis.setPose(chassis.getPose().x, distance.reset_for_long_goal(RIGHT, RED), chassis.getPose().theta);
    // move across field
    chassis.moveToPoint(-24, 62, 1000, {.forwards = false});
    chassis.moveToPoint(24, 62, 1000, {.forwards = false});
    chassis.moveToPoint(40, 46, 1000, {.forwards = false});
    chassis.turnToHeading(90, 750);
    chassis.waitUntilDone();
    // score long
    chassis.setPose(chassis.getPose().x, distance.reset_for_long_goal(LEFT, BLUE), chassis.getPose().theta);
    chassis.moveToPoint(20, 48, 750, {.forwards = false, .maxSpeed = 70});
    chassis.moveToPoint(0, chassis.getPose().y, 1000, {.forwards = false, .maxSpeed = 50});
    pros::delay(500);
    intake.outtake(450);
    pros::delay(100);
    intake.score_long(600);
    pros::delay(4000);
    chassis.setPose(30, 48, chassis.getPose().theta);
    chassis.moveToPoint(36, 48, 500);
    chassis.moveToPoint(20, 48, 750, {.forwards = false});
    intake.intake(0);
    chassis.waitUntilDone();
    intake.score_long(600);
    pros::delay(750);
    chassis.setPose(30, 48, chassis.getPose().theta);
    // clear matchloader 2
    chassis.moveToPoint(90, 48, 2500, {.maxSpeed = 50});
    intake.intake(600);
    chassis.turnToHeading(90, 250);
    chassis.waitUntilDone();
    chassis.setPose(chassis.getPose().x, distance.reset_for_long_goal(LEFT, BLUE), chassis.getPose().theta);
    // score long
    chassis.moveToPoint(20, 48, 750, {.forwards = false, .minSpeed = 70});
    pros::delay(500);
    intake.outtake(450);
    pros::delay(100);
    intake.stop_intake();
    chassis.moveToPoint(0, chassis.getPose().y, 1000, {.forwards = false, .maxSpeed = 50});
    intake.score_long(600);
    pros::delay(4000);
    chassis.setPose(30, 48, chassis.getPose().theta);
    chassis.moveToPoint(36, 48, 500);
    chassis.moveToPoint(20, 48, 750, {.forwards = false});
    intake.intake(0);
    chassis.waitUntilDone();
    intake.score_long(600);
    pros::delay(750);
    chassis.setPose(30, 48, chassis.getPose().theta);
    // move across field
    chassis.moveToPoint(40, 48, 1000);
    chassis.turnToPoint(40, -48, 500);
    chassis.moveToPoint(40, -48, 3000);
    intake.intake(0);
    chassis.turnToHeading(90, 500);
    chassis.waitUntilDone();
    chassis.setPose(chassis.getPose().x, distance.reset_for_long_goal(RIGHT, BLUE), chassis.getPose().theta);
    // clear loader
    chassis.moveToPoint(66, -48, 3000, {.maxSpeed = 50});
    intake.intake(600);
    chassis.turnToHeading(90, 250);
    chassis.waitUntilDone();
    chassis.setPose(chassis.getPose().x, distance.reset_for_long_goal(RIGHT, BLUE), chassis.getPose().theta);
    // move across field
    chassis.moveToPoint(24, -62, 1000, {.forwards = false});
    intake.intake(0);
    chassis.moveToPoint(-24, -62, 1000, {.forwards = false});
    chassis.moveToPoint(-40, -46, 1000, {.forwards = false});
    chassis.turnToHeading(270, 750);
    chassis.waitUntilDone();
    chassis.setPose(chassis.getPose().x, distance.reset_for_long_goal(LEFT, RED), chassis.getPose().theta);
    // score long
    chassis.moveToPoint(-20, -48, 750, {.forwards = false, .maxSpeed = 70});
    chassis.moveToPoint(0, chassis.getPose().y, 1000, {.forwards = false, .maxSpeed = 50});
    pros::delay(500);
    intake.outtake(450);
    pros::delay(100);
    intake.score_long(600);
    pros::delay(4000);
    chassis.setPose(-30, -48, chassis.getPose().theta);
    chassis.moveToPoint(-36, -48, 500);
    chassis.moveToPoint(-20, -48, 750, {.forwards = false});
    intake.intake(0);
    chassis.waitUntilDone();
    intake.score_long(600);
    pros::delay(750);
    chassis.setPose(-30, -48, chassis.getPose().theta);
    // clear loader
    chassis.moveToPoint(-90, -48, 2500, {.maxSpeed = 50});
    intake.intake(600);
    chassis.turnToHeading(270, 250);
    chassis.waitUntilDone();
    chassis.setPose(chassis.getPose().x, distance.reset_for_long_goal(LEFT, RED), chassis.getPose().theta);
    // score long
    chassis.moveToPoint(-20, -48, 750, {.forwards = false, .minSpeed = 70});
    pros::delay(500);
    intake.outtake(450);
    pros::delay(100);
    intake.stop_intake();
    chassis.moveToPoint(0, chassis.getPose().y, 1000, {.forwards = false, .maxSpeed = 50});
    intake.score_long(600);
    pros::delay(4000);
    chassis.setPose(-30, -48, chassis.getPose().theta);
    chassis.moveToPoint(-36, -48, 500);
    chassis.moveToPoint(-20, -48, 750, {.forwards = false});
    intake.intake(0);
    chassis.waitUntilDone();
    intake.score_long(600);
    pros::delay(750);
    chassis.setPose(-30, -48, chassis.getPose().theta);
    // park
    chassis.moveToPoint(-62, -30, 1250);
    chassis.swingToPoint(-62, 4, lemlib::DriveSide::RIGHT, 500);
    chassis.moveToPoint(-62, 4, 2000, {.maxSpeed = 60});
    intake.outtake(600);
}