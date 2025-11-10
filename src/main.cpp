#include "main.h"

// ===== MOTOR AND SENSOR DECLARATIONS =====
pros::Controller controller(pros::E_CONTROLLER_MASTER);
pros::Motor front_left_motor(-15, pros::v5::MotorGears::blue); // port 1 for front left motor (blue 600 RPM)
pros::Motor front_right_motor(20, pros::v5::MotorGears::blue); // port 2 for front right motor (blue 600 RPM)
pros::MotorGroup back_left_mg({-1, -2}, pros::v5::MotorGears::blue); // port 3 and 4 for back motors (blue 600 RPM)
pros::MotorGroup back_right_mg({9, 10}, pros::v5::MotorGears::blue); // port 5 and 6 for back motor (blue 600 RPM)
pros::Motor intake_motor1(19, pros::v5::MotorGears::blue);
pros::Motor intake_motor2(-3, pros::v5::MotorGears::blue);

bool intake1 = false;
bool intake2 = false;
bool intake1_forward = false;
bool intake1_reverse = false;
bool intake2_forward = false;
bool intake2_reverse = false;


// init function runs when code runs
void initialize() {
	pros::lcd::initialize();


	//back_left_mg.tare_position_all();
	//back_right_mg.tare_position_all();
	//front_left_motor.tare_position();
	//front_right_motor.tare_position();

	
}


void disabled() {


}


void competition_initialize() {


}


void autonomous() {


}


void opcontrol() {
	while (true) {

		if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
            intake1_reverse = !intake1_reverse;
            intake1_forward = false;
            if (intake1_reverse) {
                intake_motor1.move_voltage(-12000);
            } else {
                intake_motor1.move_voltage(0);
            }
            pros::delay(200);
        }
		if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
            intake2_reverse = !intake2_reverse;
            intake2_forward = false;
            if (intake1_reverse) {
                intake_motor2.move_voltage(-12000);
            } else {
                intake_motor2.move_voltage(0);
            }
            pros::delay(200);
        }

		
		int forward = controller.get_analog(ANALOG_LEFT_Y); // forward / backward
		int strafe = -controller.get_analog(ANALOG_LEFT_X); // strafe left / right (x-drive)
		int turn = controller.get_analog(ANALOG_RIGHT_X); // turn left / right
		

		// X-Drive Kinematics
		// front Left = forward - strafe + turn
		int front_left_power = forward - strafe + turn;
		
		// front Right = forward + strafe - turn
		int front_right_power = forward + strafe - turn;
		
		// back Left = forward + strafe + turn
		int back_left_power = forward + strafe + turn;
		
		// back Right = forward - strafe - turn
		int back_right_power = forward - strafe - turn;

		// set motor powers
		front_left_motor.move(front_left_power);
		front_right_motor.move(front_right_power);
		back_left_mg.move(back_left_power);
		back_right_mg.move(back_right_power);
		
		pros::delay(20);
	}
}