#include <robot_function/robot_function.h>
#include <iostream>

int main(int argc, char ** argv)
{
    if (argc != 8)
    {
        ROS_INFO("usage: rosrun robot_function set_joint_positions 0 0 0 0 0 0 0");
        return 0;
    }

    ros::init(argc,argv,"set_joint_positions");

    robot_function::Robot robot;
    robot.wait_for_ready();

    ros::Rate loop_rate(1000);
    std::vector<double> positions;
    positions.resize(robot.dof_);
    for (unsigned int j=0; j<robot.dof_; j++)
    {
        positions[j] = strtod(argv[j+1],NULL);
    }

    while (ros::ok())
    {
        robot.set_joint_positions(positions);
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}