#include "fobots_pid/fobots_pid_core.h"

FobotsPID::FobotsPID()
{
}

FobotsPID::~FobotsPID()
{
}

void FobotsPID::publishMessage(ros::Publisher *pub_message)
{
  fobots_msgs::PID msg;
  msg.p = p_;
  msg.d = d_;
  msg.i = i_;
  pub_message->publish(msg);
}

void FobotsPID::messageCallback(const fobots_msgs::PID::ConstPtr &msg)
{
  p_ = msg->p;
  d_ = msg->d;
  i_ = msg->i;

  //echo P,I,D
  ROS_INFO("P: %f", p_);
  ROS_INFO("D: %f", d_);
  ROS_INFO("I: %f", i_);
}

void FobotsPID::configCallback(fobots_pid::fobotsPIDConfig &config, double level)
{
  //for PID GUI
  p_ = config.p;
  d_ = config.d;
  i_ = config.i;

}
