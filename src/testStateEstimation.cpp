#include <arx5_base/state_estimation.h>
#include <iostream>

int main()
{
  StateEstimation state_estimation;
  std::vector<double> joint_states;
  std::vector<double> pose_states;

  joint_states = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
  pose_states = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
  std::cout << state_estimation.ifDanger(joint_states, pose_states) << std::endl;

  joint_states = { 0.0, 0.1, 0.0, 0.0, 0.0, 0.0 };
  pose_states = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
  std::cout << state_estimation.ifDanger(joint_states, pose_states) << std::endl;

  joint_states = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
  pose_states = { 1.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
  std::cout << state_estimation.ifDanger(joint_states, pose_states) << std::endl;

  return 0;
}