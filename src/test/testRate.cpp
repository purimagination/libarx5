#include <arx5_utils/rate.h>
#include <iostream>

int main()
{
  // 生产频率为10Hz的Rate对象
  Rate rate(10);
  // 计时开始
  while (1)
  {
    // 打印当前时刻
    auto now = std::chrono::high_resolution_clock::now();
    auto us = std::chrono::time_point_cast<std::chrono::microseconds>(now);
    auto ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
    std::cout << "Current time (ms): " << us.time_since_epoch().count() << std::endl;
    rate.sleep();
  }

  return 0;
}