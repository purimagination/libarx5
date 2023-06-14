#include <arx5_base/state_estimation.h>
#include <arx5_base/kinematics_dynamics.h>
#include <iostream>

int main()
{
  StateEstimation state_estimation;
  std::vector<double> joint_states;

  joint_states = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
  std::cout << state_estimation.ifDanger(joint_states) << std::endl;

  joint_states = { 0.0, 0.1, 0.0, 0.0, 0.0, 0.0 };
  std::cout << state_estimation.ifDanger(joint_states) << std::endl;

  joint_states = { 0.0, -1.0, 2.0, 0.0, 0.0, 0.0 };
  std::cout << state_estimation.ifDanger(joint_states) << std::endl;

  return 0;
}