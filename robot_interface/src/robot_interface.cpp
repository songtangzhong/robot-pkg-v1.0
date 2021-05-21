#include <robot_interface/robot_interface.h>
#include <iostream>

namespace robot_interface
{
JointStateMultiThread::JointStateMultiThread()
{
    joint_state_sub_ = nh_.subscribe("/robot/joint_states", 100, 
        &JointStateMultiThread::joint_state_sub_cb_, this);
    joint_state_ser_ = nh_.advertiseService("/robot/joint_state_multi_thread", 
        &JointStateMultiThread::joint_state_ser_cb_, this);
}

JointStateMultiThread::~JointStateMultiThread(){}

void JointStateMultiThread::joint_state_sub_cb_(const sensor_msgs::JointState::ConstPtr& msg)
{
    std::lock_guard<std::mutex> guard(mtx_);

    joint_state_.name.resize(msg->name.size());
    joint_state_.position.resize(msg->name.size());
    joint_state_.velocity.resize(msg->name.size());
    joint_state_.effort.resize(msg->name.size());
    
    for (unsigned int j=0; j< msg->name.size(); j++)
    {
        joint_state_.name[j] = msg->name[j];
        joint_state_.position[j] = msg->position[j];
        joint_state_.velocity[j] = msg->velocity[j];
        joint_state_.effort[j] = msg->effort[j];
    }
}

bool JointStateMultiThread::joint_state_ser_cb_(robot_core_msgs::JointStateMultiThread::Request &req,
    robot_core_msgs::JointStateMultiThread::Response &res)
{
    std::lock_guard<std::mutex> guard(mtx_);
    
    if (req.request == req.ok)
    {
        res.result.name.resize(joint_state_.name.size());
        res.result.position.resize(joint_state_.name.size());
        res.result.velocity.resize(joint_state_.name.size());
        res.result.effort.resize(joint_state_.name.size());

        for (unsigned int j=0; j<joint_state_.name.size(); j++)
        {
            res.result.name[j] = joint_state_.name[j];
            res.result.position[j] = joint_state_.position[j];
            res.result.velocity[j] = joint_state_.velocity[j];
            res.result.effort[j] = joint_state_.effort[j];
        }

        return true;
    }
    else
    {
        ROS_ERROR("Joint state request command is not right.");
        return false;
    }
}

}