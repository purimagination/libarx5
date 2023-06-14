#include "arx5_base/joint_trajectories.h"
#include <iostream>

JointTrajectories::JointTrajectories()
{
  // 初始化轨迹队列
  for (int i = 0; i < 6; i++)
  {
    std::vector<double> trajectory;
    trajectories_.push_back(trajectory);
  }
}

void JointTrajectories::push(std::vector<double> joint_positions)
{
  // 确保push的轨迹点的关节角度个数为6
  int size = joint_positions.size();
  if (size == 6)
  {
    // 将轨迹点添加到轨迹队列中
    for (int i = 0; i < 6; i++)
    {
      trajectories_[i].push_back(joint_positions[i]);
    }
  }
  else
  {
    std::cout << "The size of joint_positions is not 6!" << std::endl;
  }
}

void JointTrajectories::pop()
{
  // 删除轨迹队列中的第一个轨迹点
  for (int i = 0; i < 6; i++)
  {
    if (trajectories_[i].size() != 0)
    {
      trajectories_[i].erase(trajectories_[i].begin());
    }
  }
}

void JointTrajectories::update(std::vector<std::vector<double>> new_trajectories)
{
  // 更新轨迹
  trajectories_ = new_trajectories;
}

std::vector<double> JointTrajectories::front()
{
  // 轨迹队列中的第一个轨迹点
  std::vector<double> front;
  for (int i = 0; i < 6; i++)
  {
    front.push_back(trajectories_[i][0]);
  }
  // 返回轨迹队列中的第一个轨迹点
  return front;
}

void JointTrajectories::print()
{
  // 打印轨迹队列中的所有轨迹点
  for (int i = 0; i < 6; i++)
  {
    for (int j = 0; j < trajectories_[i].size(); j++)
    {
      std::cout << trajectories_[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

int JointTrajectories::size()
{
  // 返回轨迹队列中的轨迹点的个数
  return trajectories_[0].size();
}