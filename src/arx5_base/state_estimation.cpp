#include "arx5_base/state_estimation.h"

StateEstimation::StateEstimation(){

};

bool StateEstimation::ifDanger(std::vector<double> joint_states)
{
  // 判断关节角度是否超出安全范围
  for (int i = 0; i < 6; i++)
  {
    if (joint_states[i] < angle_lower_bound[i] || joint_states[i] > angle_upper_bound[i])
    {
      std::cout<<"joint angle out of bound. joint index: "<<i<<", angle value: "<<joint_states[i]<<std::endl;
      return true;
    }
  }

  // 通过运动学正解得到末端位姿，对末端位姿再做一次判断
  std::vector<double> pose_states = kinematics_dynamics.solveFK(joint_states);

  // 判断执行器末端位姿是否超出安全范围
  for (int i = 0; i < 6; i++)
  {
    if (pose_states[i] < pose_lower_bound[i] || pose_states[i] > pose_upper_bound[i])
    {
      std::cout<<"pose out of bounds. pose index: "<<i<<", value: "<<pose_states[i]<<std::endl;
      return true;
    }
  }

  return false;
}