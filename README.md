# robot-pkg-v1.0

Based on: ros-kinetic and sawyer robot. It is also can be used on other robots with some slight modifications.

This package realizes basic functions of a robot in user level. Robot informations can be advertised from a real robot platform to some ros topics and services. In this package, all these informations can be obtained by some functions in package "robot_function". 

Interface functions are based on package "robot_interface" and "robot_core_msgs". Package "robot_function" is realized using the multi thread of ros. In our method, it contains subscriber and service server in one ros node.

## usage
Firstly, run the following command in one terminal.
```
rosrun robot_interface joint_state_multi_thread
```

## example
Position mode.
```
rosrun robot_function set_joint_positions 0 0 0 0 0 0 0
```

Effort mode.
```
rosrun robot_function set_joint_efforts 0 0 0 0 0 0 0
```