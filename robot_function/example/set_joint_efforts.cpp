#include <robot_function/robot_function.h>
#include <iostream>

int main(int argc, char ** argv)
{
    if (argc != 8)
    {
        ROS_INFO("usage: rosrun robot_function set_joint_efforts 0 0 0 0 0 0 0");
        return 0;
    }

    ros::init(argc,argv,"set_joint_efforts");

    robot_function::Robot robot;
    robot.wait_for_ready();

    ros::Rate loop_rate(1000);
    std::vector<double> efforts;
    efforts.resize(robot.dof_);
    for (unsigned int j=0; j<robot.dof_; j++)
    {
        efforts[j] = strtod(argv[j+1],NULL);
    }

    while (ros::ok())
    {
        robot.set_joint_efforts(efforts);
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}