#include <arx5_base/hardware_interface.h>
#include <arx5_base/kinematics_dynamics.h>
#include <arx5_base/teaching.h>
#include <arx5_base/rate.h>

// 录制数据文件名称
std::string file_name = "gravity_off";
// 录制数据文件保存路径
std::string save_path = "/home/hanzx/Dev/Projects/libarx5/saved_data";
// 机械臂urdf文件路径
std::string urdf_path = "/home/hanzx/Dev/Projects/libarx5/urdf/arx5_kdl.urdf";

int main()
{
  // 生成硬件接口对象
  HardwareInterface hardware_interface("real", "position");
  // 生成运动学、动力学求解器
  KinematicsDynamics kinematics_dynamics(urdf_path);
  // 生成数据播放器
  Player player(save_path, file_name);
  float frequency = player.getFrequency();
  // 生成频率控制器
  Rate loop_rate(frequency);

  // 关节状态（角度）
  std::vector<double> joint_states = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

  while (!player.isEnd())
  {
    // 控制频率
    loop_rate.sleep();

    // 获取关节状态
    joint_states = player.getData();

    // 将动力学逆解力矩赋值给关节
    hardware_interface.setODJointAngles(joint_states);
  }

  return 0;
}