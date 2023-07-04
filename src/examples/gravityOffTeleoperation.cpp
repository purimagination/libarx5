#include <arx5_base/hardware_interface.h>
#include <arx5_base/kinematics_dynamics.h>
#include <arx5_base/rate.h>

int main()
{
  // 生成硬件接口对象
  HardwareInterface hardware_interface("real", "torque", "can0");
  // 生成硬件接口对象2
  HardwareInterface hardware_interface2("real", "position", "can1");
  // 机械臂urdf文件路径
  std::string urdf_path = "/home/hanzx/Dev/Projects/libarx5/urdf/arx5_kdl.urdf";
  // 生成运动学、动力学求解器
  KinematicsDynamics kinematics_dynamics(urdf_path);
  // 生成频率控制器
  Rate loop_rate(100);

  // 末端关节受力
  std::vector<double> end_effector_force = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  // 动力学逆解结果
  std::vector<double> id_result = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  // 关节状态（角度）
  std::vector<double> joint_states = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  // 关节力矩
  std::vector<double> t = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  // 两个机械臂的力矩差值
  std::vector<double> t_diff = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

  // 初始给一个零力矩
  hardware_interface.setODJointTorques(id_result);

  while (1)
  {
    // 控制频率
    loop_rate.sleep();

    // 获取关节状态
    std::vector<double> joint_states = hardware_interface.getJointAngles();
    std::vector<double> torques = hardware_interface2.getJointTorques();
    // 控制从动机械臂关节角度
    hardware_interface2.setODJointAngles(joint_states);

    // 打印关节状态
    // for (int i = 0; i < 6; i++)
    // {
    //   std::cout << "[" << i << "] = " << joint_states[i]<<" ";
    // }
    // std::cout<<" ||";

    // 更新运动学动力学求解器的关节状态
    kinematics_dynamics.updateJointStates(joint_states);

    // 动力学逆解
    id_result = kinematics_dynamics.solveID(end_effector_force);

    // 打印动力学逆解结果
    // std::cout << "ID result: " << id_result[0] << ", " << id_result[1] << ", " << id_result[2] << ", " << id_result[3]
    //           << ", " << id_result[4] << ", " << id_result[5];
    
    // std::cout<<" ||";

    // 打印当前电流
    // std::cout << "current_float: " << torques[0] << ", " << torques[1] << ", " << torques[2] << ", " << torques[3]
    //           << ", " << torques[4] << ", " << torques[5];
    
    // std::cout<<std::endl;

    for(int i=0; i<6; i++)
    {
      if(t[i] > 0)
      {
        t_diff[i] = abs(abs(id_result[i]) - abs(torques[i]));
      }
      else
      {
        t_diff[i] = -abs(abs(id_result[i]) - abs(torques[i]));
      }
      t[i] = id_result[i] + t_diff[i]*0.15;
    }

    // 将动力学逆解力矩赋值给关节
    hardware_interface.setODJointTorques(t);
  }

  return 0;
}