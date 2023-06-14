#ifndef PLANNER_H
#define PLANNER_H

#include <vector>

class Planner
{
public:
  Planner();
  ~Planner() = default;

  // 更新位姿状态
  void updatePoseStates(std::vector<double> pose);

  // 传入期望的末端位姿（x, y, z, roll. pitch, yaw），返回位姿轨迹序列
  std::vector<std::vector<double>> getTraj(std::vector<double> target_pose);

private:
  // 当前位姿状态
  std::vector<double> pose_states;
  // 插值依据的机械臂运行速度（暂时设置为角速度与线速度一致）
  double velocity = 0.1;
  // 插值的精度（每个点之间的时间差）
  double dt = 0.001;
};

#endif