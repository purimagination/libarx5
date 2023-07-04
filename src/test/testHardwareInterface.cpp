#include <arx5_base/hardware_interface.h>

int main()
{
  // 生成硬件接口对象
  HardwareInterface hardware_interface("real", "position", "can0");
  // 控制关节
  hardware_interface.setODJointAngles({ 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 });
  // 获取关节状态
  std::vector<double> joint_states = hardware_interface.getJointAngles();
  // 打印关节状态
  for (int i = 0; i < 6; i++)
  {
    std::cout << "joint_states[" << i << "] = " << joint_states[i] << std::endl;
  }

  // 等待1秒
  sleep(1);

  // 控制关节
  hardware_interface.setODJointAngles({ 0.0, -0.2, 0.0, 0.0, 0.0, 0.0 });
  // 等待1秒
  sleep(1);
  // 获取关节状态
  joint_states = hardware_interface.getJointAngles();
  // 打印关节状态
  for (int i = 0; i < 6; i++)
  {
    std::cout << "joint_states[" << i << "] = " << joint_states[i] << std::endl;
  }

  while (1)
  {
  }

  return 0;
}