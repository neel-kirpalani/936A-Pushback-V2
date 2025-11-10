# 936A V2 - VEX V5 Robot Code

A PROS (PROS Robotics Operating System) project for a VEX V5 holonomic X-Drive robot.

## Overview

This project contains the firmware code for a VEX V5 robot with an X-Drive (holonomic) drivetrain configuration. The robot uses four motors arranged in an X-Drive pattern, allowing for omnidirectional movement including forward/backward, strafing, and rotation.

## Robot Configuration

### Drivetrain
- **Type**: X-Drive (Holonomic)
- **Motors**: 4 motors with blue gear cartridges (600 RPM)

### Motor Ports
- **Front Left**: Port 15 (reversed)
- **Front Right**: Port 20
- **Back Left**: Ports 1 & 2 (reversed, motor group)
- **Back Right**: Ports 9 & 10 (motor group)

### Controller
- Master controller for operator control

## Features

- **Holonomic Movement**: Full omnidirectional control with forward/backward, strafing, and rotation
- **X-Drive Kinematics**: Properly implemented X-Drive motor calculations
- **Motor Groups**: Back motors are grouped for synchronized control
- **LCD Support**: LCD initialization for potential future display features

## Building the Project

### Prerequisites
- [PROS CLI](https://pros.cs.purdue.edu/v5/getting-started/) installed
- VEX V5 Brain connected via USB

### Build Commands
# Build the project
make

# Upload to robot
pros upload## Code Structure

- `src/main.cpp`: Main robot code with motor declarations and control logic
- `include/`: Header files and PROS library includes
- `firmware/`: PROS firmware libraries

## Control Scheme

The robot uses standard VEX controller inputs:
- **Left Stick Y-Axis**: Forward/backward movement
- **Left Stick X-Axis**: Strafing (left/right)
- **Right Stick X-Axis**: Rotation (left/right)

## X-Drive Kinematics

The code implements standard X-Drive kinematics:
- Front Left = forward - strafe + turn
- Front Right = forward + strafe - turn
- Back Left = forward + strafe + turn
- Back Right = forward - strafe - turn

## Future Development

- Autonomous routines (currently empty)
- Odometry and position tracking (commented out)
- LCD display for robot status

## License

This project is for VEX Robotics competition use.

## Author

936A V2 Team
