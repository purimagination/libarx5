#ifndef STATE_ESTIMATION_H
#define STATE_ESTIMATION_H

#include <vector>
#include <arx5_base/kinematics_dynamics.h>

class StateEstimation
{
public:
  StateEstimation();
  ~StateEstimation() = default;

  // 根据当前状态，判断是否需要停止运动
  bool ifDanger(std::vector<double> joint_states);

private:
  // 6个关节角度的上下限
  std::vector<double> angle_lower_bound = { -1.57, -3.14, 0.0, -1.57, -1.57, -1.57 };
  std::vector<double> angle_upper_bound = { 1.57, 0.0, 3.14, 1.57, 1.57, 1.57 };

  // 执行器末端的位姿上下限 (x, y, z, roll, pitch, yaw)
  // std::vector<double> pose_lower_bound = { 0.0, -0.3, 0.0, -1.57, -1.57, -1.57 };
  // std::vector<double> pose_upper_bound = { 0.5, 0.3, 0.5, 1.57, 1.57, 1.57 };

  // 需要用到运动学求解器对关节角度进行正解计算
  // KinematicsDynamics kinematics_dynamics;
};

#endif