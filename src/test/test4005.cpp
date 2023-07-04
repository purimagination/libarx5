#include <arx5_base/hardware_interface.h>

int main()
{
  // 生成硬件接口对象
  HardwareInterface hardware_interface("real", "position", "can0");
  // 设置4005电机力矩
  float t = 15.0;
  hardware_interface.setGripperTorque(t);

  while(1)
  {
  }
  return 0;
}