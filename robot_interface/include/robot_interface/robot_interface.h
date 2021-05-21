#ifndef ROBOT_INTERFACE_H_
#define ROBOT_INTERFACE_H_

#include <ros/ros.h>
#include <sensor_msgs/JointState.h>
#include <robot_core_msgs/JointStateMultiThread.h>
#include <mutex>
#include <controller_manager/controller_manager.h>

namespace robot_interface
{
class JointStateMultiThread
{
public:
    JointStateMultiThread();
    ~JointStateMultiThread();

private:
    void joint_state_sub_cb_(const sensor_msgs::JointState::ConstPtr& msg);
    bool joint_state_ser_cb_(robot_core_msgs::JointStateMultiThread::Request  &req,
        robot_core_msgs::JointStateMultiThread::Response &res);

    ros::NodeHandle nh_; 
    
	ros::Subscriber joint_state_sub_;
    ros::ServiceServer joint_state_ser_;

    sensor_msgs::JointState joint_state_;

    std::mutex mtx_;

};

}

#endif