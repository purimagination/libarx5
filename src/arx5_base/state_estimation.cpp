#include "arx5_base/state_estimation.h"

StateEstimation::StateEstimation(){

};

bool StateEstimation::ifDanger(std::vector<double> joint_states, std::vector<double> pose_states)
{
  // 判断关节角度是否超出安全范围
  for (int i = 0; i < 6; i++)
  {
    if (joint_states[i] < angle_lower_bound[i] || joint_states[i] > angle_upper_bound[i])
    {
      return true;
    }
  }

  // 判断执行器末端位姿是否超出安全范围
  for (int i = 0; i < 6; i++)
  {
    if (pose_states[i] < pose_lower_bound[i] || pose_states[i] > pose_upper_bound[i])
    {
      return true;
    }
  }

  return false;
}