#include <arx5_base/hardware_interface.h>
#include <arx5_base/kinematics_dynamics.h>
#include <arx5_base/teaching.h>
#include <arx5_utils/rate.h>

// 录制数据文件名称
std::string file_name = "gravity_off";

int main()
{
  // 生成硬件接口对象
  HardwareInterface hardware_interface("real", "position");
  // 生成运动学、动力学求解器
  KinematicsDynamics kinematics_dynamics;
  // 生成数据播放器
  Player player(file_name);
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
    hardware_interface.setJointAngles(joint_states);
  }

  return 0;
}