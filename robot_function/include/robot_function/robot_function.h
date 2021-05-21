#ifndef ROBOT_FUNCTION_H_
#define ROBOT_FUNCTION_H_

#include <ros/ros.h>
#include <vector>
#include <robot_core_msgs/JointStateMultiThread.h>

namespace robot_function
{
class Robot
{
public:
    Robot();
    ~Robot();

    void wait_for_ready();

    int get_joint_positions(std::vector<double> & positions);

    int get_joint_velocities(std::vector<double> & velocities);

    int get_joint_efforts(std::vector<double> & efforts);

    void set_joint_positions(std::vector<double> & positions);

    void set_joint_efforts(std::vector<double> & efforts);

    const unsigned int dof_ = 7;

private:
    std::vector<std::string> joint_names;

    ros::NodeHandle nh_;

    robot_core_msgs::JointStateMultiThread joint_state_;

    ros::ServiceClient joint_state_cli_;

    ros::Publisher joint_command_pub_;

};

}

#endif