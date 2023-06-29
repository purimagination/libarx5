#include <arx5_base/hardware_interface.h>

int main()
{
  // 生成硬件接口对象
  HardwareInterface hardware_interface("real", "position");
  hardware_interface.calibrateAll();
  return 0;
}