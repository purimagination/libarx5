#include <arx5_base/planner.h>
#include <iostream>

int main()
{
  Planner planner;

  std::vector<std::vector<double>> trajs;
  trajs = planner.getTraj({ 0.0, 0.0, 0.1, 0.0, 0.0, 0.0 });

  // 打印轨迹队列中的所有轨迹点
  for (int i = 0; i < trajs[0].size(); i++)
  {
    for (int j = 0; j < 6; j++)
    {
      std::cout << trajs[j][i] << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}