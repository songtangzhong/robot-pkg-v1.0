#include <robot_function/robot_function.h>

namespace robot_function
{
Robot::Robot()
{
    joint_names.resize(dof_);
    joint_names[0] = "right_j0";
    joint_names[1] = "right_j1";
    joint_names[2] = "right_j2";
    joint_names[3] = "right_j3";
    joint_names[4] = "right_j4";
    joint_names[5] = "right_j5";
    joint_names[6] = "right_j6";

    joint_state_cli_ = nh_.serviceClient<robot_core_msgs::JointStateMultiThread>(
        "/robot/joint_state_multi_thread");
}

Robot::~Robot(){}

void Robot::wait_for_ready()
{
    const unsigned int count = 3;
    ros::Rate loop_rate(1);
    for (unsigned int j=0; j<=count; j++)
    {
        ROS_INFO("Wait for ready... %d.", count-j);
        loop_rate.sleep();
    }
}

int Robot::get_joint_positions(std::vector<double> & positions)
{
    joint_state_.request.request = joint_state_.request.ok;

    if (joint_state_cli_.call(joint_state_))
    {
        for (unsigned int j=0; j<joint_state_.response.result.name.size(); j++)
        {
            for (unsigned int i=0; i<dof_; i++)
            {
                if (joint_state_.response.result.name[j] == joint_names[i])
                {
                    positions[i] = joint_state_.response.result.position[j];
                    break;
                }
            }
        }
    }
    else
    {
        ROS_ERROR("Failed to call service /robot/joint_state_multi_thread or interrupting occurs.");
        return -1;
    }

    return 1;
}

int Robot::get_joint_velocities(std::vector<double> & velocities)
{
    joint_state_.request.request = joint_state_.request.ok;

    if (joint_state_cli_.call(joint_state_))
    {
        for (unsigned int j=0; j<joint_state_.response.result.name.size(); j++)
        {
            for (unsigned int i=0; i<dof_; i++)
            {
                if (joint_state_.response.result.name[j] == joint_names[i])
                {
                    velocities[i] = joint_state_.response.result.velocity[j];
                    break;
                }
            }
        }
    }
    else
    {
        ROS_ERROR("Failed to call service /robot/joint_state_multi_thread or interrupting occurs.");
        return -1;
    }

    return 1;
}

int Robot::get_joint_efforts(std::vector<double> & efforts)
{
    joint_state_.request.request = joint_state_.request.ok;

    if (joint_state_cli_.call(joint_state_))
    {
        for (unsigned int j=0; j<joint_state_.response.result.name.size(); j++)
        {
            for (unsigned int i=0; i<dof_; i++)
            {
                if (joint_state_.response.result.name[j] == joint_names[i])
                {
                    efforts[i] = joint_state_.response.result.effort[j];
                    break;
                }
            }
        }
    }
    else
    {
        ROS_ERROR("Failed to call service /robot/joint_state_multi_thread or interrupting occurs.");
        return -1;
    }

    return 1;
}

}