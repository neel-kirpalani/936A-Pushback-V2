# 936A V2 - VEX V5 Robot Codebase

A PROS (PROS Robotics Operating System) project for a VEX V5 holonomic X-Drive robot.

## Overview

This project contains the firmware code for a VEX V5 robot with an X-Drive (holonomic) drivetrain configuration. The robot uses 6 motors arranged in an X-Drive pattern, allowing for omnidirectional movement including forward/backward, strafing, and rotation.

## Robot Configuration
- Coming Soon

### Drivetrain
- **Type**: X-Drive (Holonomic)
- **Motors**: 6 motors with blue gear cartridges (4 x 600 RPM + 2 x Half-Motors)

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
pros make

# Upload to robot
`pros upload`

- `src/main.cpp`: Main robot code with motor declarations and control logic
- `include/`: Header files and PROS library includes
- `firmware/`: PROS firmware libraries

## Control Scheme

The robot uses standard VEX controller inputs for an X-Drive:
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
- Drive Controls

## License

This project is for VEX Robotics competition use.

## Author

Neel Kirpalani and the 936A Robotics Team
