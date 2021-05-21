# robot-pkg-v1.0

## Description:
This package realized some interface functions of a robot in user level. Robot informations which have been advertised from a real robot platform to some ros topics and services, can be read and written directly by these packages.

Package "robot_core_msgs" includes some common messages, services and actions used in this framework.

Package "robot_interface" realized the bridge between real robot platform topics (and services) and interface functions in this framework. It is based on multi thread method of ros.

Package "robot_function" realized some interface functions to operate a real robot.

## Dependence:
The framework is based on ros-kinetic and sawyer robot. It is also can be used on other robots with some slight modifications.

## Usage:
1. Firstly, clone and put all these packages in your "ros_ws/src" folder, "ros_ws" should be replaced with your own ros workspace name.
```
cd ~/ros_ws
catkin_make
```

2. Start transfer nodes in the system.
```
rosrun robot_interface joint_state_multi_thread
```

3. Run some examples.

(1) Get joint positions.
```
rosrun robot_function get_joint_positions
```

(2) Set joint positions.
```
rosrun robot_function set_joint_positions 0 0 0 0 0 0 0
```
(3) Set joint efforts.
```
rosrun robot_function set_joint_efforts 0 0 0 0 0 0 0
```