#include <robot_interface/robot_interface.h>
#include <ros/ros.h>

int main(int argc, char ** argv)
{
    ros::init(argc,argv,"joint_state_multi_thread");

    robot_interface::JointStateMultiThread joint_state_multi_thread;

    ros::AsyncSpinner spinner(2);
    spinner.start();
    ROS_INFO("Joint state multi thread is working.");
    ros::waitForShutdown();

    return 0;
}
