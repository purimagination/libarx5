#include <arx5_base/kinematics_dynamics.h>
#include <iostream>

int main()
{
  // 机械臂urdf文件路径
  std::string urdf_path = "/home/hanzx/Dev/Projects/libarx5/urdf/arx5_kdl.urdf";
  KinematicsDynamics kinematics_dynamics(urdf_path);

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

  joint_angles = { 0.1, 0.1, 0.1, 0.1, 0.1, 0.0 };
  fk_result = kinematics_dynamics.solveFK(joint_angles);
  std::cout << "FK result: " << fk_result[0] << ", " << fk_result[1] << ", " << fk_result[2] << ", " << fk_result[3]
            << ", " << fk_result[4] << ", " << fk_result[5] << std::endl;

  joint_angles = { 0.1, 0.1, 0.1, 0.1, 0.1, 0.5 };
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

  // 动力学逆解测试
  end_effector_pose = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
  id_result = kinematics_dynamics.solveID(end_effector_pose);
  std::cout << "ID result: " << id_result[0] << ", " << id_result[1] << ", " << id_result[2] << ", " << id_result[3]
            << ", " << id_result[4] << ", " << id_result[5] << std::endl;

  return 0;
}