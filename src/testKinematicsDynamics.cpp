#include <arx5_base/kinematics_dynamics.h>
#include <iostream>

int main()
{
  KinematicsDynamics kinematics_dynamics;

  std::vector<double> fk_result;
  std::vector<double> ik_result;
  std::vector<double> id_result;
  std::vector<double> joint_angles;
  std::vector<double> end_effector_pose;

  // 运动学正解测试
  joint_angles = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
  fk_result = kinematics_dynamics.solveFK(joint_angles);
  std::cout << "FK result: " << fk_result[0] << ", " << fk_result[1] << ", " << fk_result[2] << ", " << fk_result[3]
            << ", " << fk_result[4] << ", " << fk_result[5] << std::endl;

  joint_angles = { 0.0, -0.3, 0.6, -0.2, 0.0, 0.1 };
  fk_result = kinematics_dynamics.solveFK(joint_angles);
  std::cout << "FK result: " << fk_result[0] << ", " << fk_result[1] << ", " << fk_result[2] << ", " << fk_result[3]
            << ", " << fk_result[4] << ", " << fk_result[5] << std::endl;

  // 运动学逆解测试
  end_effector_pose = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
  ik_result = kinematics_dynamics.solveIK(end_effector_pose);
  std::cout << "IK result: " << ik_result[0] << ", " << ik_result[1] << ", " << ik_result[2] << ", " << ik_result[3]
            << ", " << ik_result[4] << ", " << ik_result[5] << std::endl;

  end_effector_pose = { 0.0, 0.0, 0.3, 0.0, 0.0, 0.0 };
  ik_result = kinematics_dynamics.solveIK(end_effector_pose);
  std::cout << "IK result: " << ik_result[0] << ", " << ik_result[1] << ", " << ik_result[2] << ", " << ik_result[3]
            << ", " << ik_result[4] << ", " << ik_result[5] << std::endl;

  // 线程测试
  while (1)
  {
  }

  return 0;
}