#include "arx5_base/planner.h"
#include <math.h>
#include <iostream>

Planner::Planner()
{
  // 初始化位姿状态
  pose_states = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
}

void Planner::updatePoseStates(std::vector<double> pose)
{
  // 更新位姿状态
  pose_states = pose;
}

std::vector<std::vector<double>> Planner::getTraj(std::vector<double> target_pose)
{
  // 初始化位姿轨迹队列
  std::vector<std::vector<double>> trajectories;
  for (int i = 0; i < 6; i++)
  {
    std::vector<double> trajectory;
    trajectories.push_back(trajectory);
  }

  // 计算最大差值
  double max_diff = 0.0;
  for (int i = 0; i < 3; i++)
  {
    if (fabs(target_pose[i] - pose_states[i]) > max_diff)
    {
      max_diff = fabs(target_pose[i] - pose_states[i]);
    }
  }
  for (int i = 3; i < 6; i++)
  {
    if (fabs(target_pose[i] - pose_states[i]) / M_PI > max_diff)
    {
      max_diff = fabs(target_pose[i] - pose_states[i]) / M_PI;
    }
  }

  // 根据当前状态与目标状态之间最大的关节角度差值计算得到运动需要的时间
  double interval = max_diff / velocity;

  // 如果时间为0，设为一个特别接近于0的数，防止拟合时报错
  if (interval == 0.0)
  {
    interval = 0.001;
  }

  // 进行线性插值拟合
  double params[6][2];
  for (int i = 0; i < 6; i++)
  {
    params[i][0] = pose_states[i];
    params[i][1] = (target_pose[i] - pose_states[i]) / interval;
  }

  // 计时
  double t = 0.0;
  while (t <= interval)
  {
    for (int i = 0; i < 6; i++)
    {
      // 根据当前时间与拟合得到的三次函数得到该时刻的角度值（弧度制）
      trajectories[i].push_back(params[i][0] + params[i][1] * t);
    }
    t += dt;
  }

  return trajectories;
}