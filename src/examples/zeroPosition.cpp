#include <arx5_base/hardware_interface.h>

int main()
{
  // 生成硬件接口对象
  HardwareInterface hardware_interface("real", "position");
  // 控制关节
  hardware_interface.setJointAngles({ 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 });

  // 等一秒钟
  sleep(1);

  // 获取关节状态
  std::vector<double> joint_states = hardware_interface.getJointStates();
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