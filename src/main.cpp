#include "main.h"
#include "lemlib/api.hpp"

// ===== MOTOR AND SENSOR DECLARATIONS =====
pros::Controller controller(pros::E_CONTROLLER_MASTER);
pros::Motor front_left_motor(1, pros::MotorGearset::blue); // port 1 for front left motor
pros::Motor front_right_motor(2, pros::MotorGearset::blue); // port 2 for front right motor
pros::MotorGroup back_left_mg({3, 4}, pros::MotorGearset::blue); // port 3 and 4 for back motors
pros::MotorGroup back_right_mg({5, 6}, pros::MotorGearset::blue); // port 5 and 6 for back motor



// init function runs when code runs
void initialize() {
	pros::lcd::initialize();
	chassis.calibrate();
	chassis.setPose(0, 0, 0);


	back_left_mg.tare_position_all();
	back_right_mg.tare_position_all();
	front_left_motor.tare_position();
	front_right_motor.tare_position();

	pros::Task screen_task([&]() {
        while (true) {
            pros::lcd::print(5, "X: %f", chassis.getPose().x);
            pros::lcd::print(6, "Y: %f", chassis.getPose().y);
            pros::lcd::print(7, "Theta: %f", chassis.getPose().theta);
            pros::delay(50);
        }
    });


	
}


void disabled() {}


void competition_initialize() {}


void autonomous() {}


void opcontrol() {
	while (true) {
		int forward = master.get_analog(ANALOG_LEFT_Y); // forward / backward
		int strafe = master.get_analog(ANALOG_LEFT_X); // strafe left / right (x-drive)
		int turn = master.get_analog(ANALOG_RIGHT_X); // turn left / right


		// X-Drive Kinematics
		// Front Left = forward - strafe + turn
		int front_left_power = forward - strafe + turn;
		
		// Front Right = forward + strafe - turn
		int front_right_power = forward + strafe - turn;
		
		// Back Left = forward + strafe + turn
		int back_left_power = forward + strafe + turn;
		
		// Back Right = forward - strafe - turn
		int back_right_power = forward - strafe - turn;

		// Set motor powers
		front_left_motor.move(front_left_power);
		front_right_motor.move(front_right_power);
		back_left_mg.move(back_left_power);
		back_right_mg.move(back_right_power);
		
		pros::delay(20);
	}
}