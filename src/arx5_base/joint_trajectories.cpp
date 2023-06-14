#include "arx5_base/trajectories.h"
#include <iostream>

Trajectories::Trajectories()
{
  // 初始化轨迹队列
  for (int i = 0; i < 6; i++)
  {
    std::vector<double> trajectory;
    trajectories_.push_back(trajectory);
  }
}

void Trajectories::push(std::vector<double> positions)
{
  // 确保push的轨迹点的元素个数为6
  int size = positions.size();
  if (size == 6)
  {
    // 将轨迹点添加到轨迹队列中
    for (int i = 0; i < 6; i++)
    {
      trajectories_[i].push_back(positions[i]);
    }
  }
  else
  {
    std::cout << "The size of jositions is not 6!" << std::endl;
  }
}

void Trajectories::pop()
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

void Trajectories::update(std::vector<std::vector<double>> new_trajectories)
{
  // 更新轨迹
  trajectories_ = new_trajectories;
}

std::vector<double> Trajectories::front()
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

void Trajectories::print()
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

int Trajectories::size()
{
  // 返回轨迹队列中的轨迹点的个数
  return trajectories_[0].size();
}