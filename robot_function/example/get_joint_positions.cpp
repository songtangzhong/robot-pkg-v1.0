#include <robot_function/robot_function.h>
#include <iostream>

int main(int argc, char ** argv)
{
    ros::init(argc,argv,"get_joint_positions");

    robot_function::Robot robot;
    robot.wait_for_ready();

    ros::Rate loop_rate(1000);
    std::vector<double> positions;
    positions.resize(robot.dof_);
    while (ros::ok())
    {
        robot.get_joint_positions(positions);
        loop_rate.sleep();

        for (unsigned int j=0; j<robot.dof_; j++)
        {
            std::cout << "positions[" << j << "]: " << positions[j] << std::endl;
        }
    }

    return 0;
}
