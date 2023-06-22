#include <arx5_base/hardware_interface.h>
#include <arx5_base/kinematics_dynamics.h>

int main()
{
  // 生成硬件接口对象
  HardwareInterface hardware_interface("real", "torque");
  // 生成运动学、动力学求解器
  KinematicsDynamics kinematics_dynamics;
  // 动力学逆解结果
  std::vector<double> id_result = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  // 关节状态（角度）
  std::vector<double> joint_states = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  // 末端位姿
  std::vector<double> end_effector_pose = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

  // 初始给一个零力矩
  hardware_interface.setJointTorques(id_result);

  while (1)
  {
    // // 获取关节状态
    // std::vector<double> joint_states = hardware_interface.getJointStates();
    // // 打印关节状态
    // for (int i = 0; i < 6; i++)
    // {
    //   std::cout << "joint_states[" << i << "] = " << joint_states[i] << std::endl;
    // }

    // 动力学逆解测试
    id_result = kinematics_dynamics.solveID(end_effector_pose);
    std::cout << "ID result: " << id_result[0] << ", " << id_result[1] << ", " << id_result[2] << ", " << id_result[3]
              << ", " << id_result[4] << ", " << id_result[5] << std::endl;

    hardware_interface.setJointTorques(id_result);
  }

  return 0;
}