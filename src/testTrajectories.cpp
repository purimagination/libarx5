#include <arx5_base/trajectories.h>
#include <iostream>

int main()
{
  Trajectories trajectories;

  std::vector<double> positions;
  positions.push_back(1.0);
  positions.push_back(2.0);
  positions.push_back(3.0);
  positions.push_back(4.0);
  positions.push_back(5.0);
  positions.push_back(6.0);
  trajectories.push(positions);
  trajectories.print();

  positions.clear();
  positions.push_back(2.0);
  positions.push_back(3.0);
  positions.push_back(4.0);
  positions.push_back(5.0);
  positions.push_back(6.0);
  positions.push_back(7.0);
  trajectories.push(positions);
  trajectories.print();

  trajectories.pop();
  trajectories.print();
  trajectories.pop();
  trajectories.print();
  trajectories.pop();
  trajectories.print();

  // 测试在没有数据的时候能不能pop
  trajectories.pop();
  trajectories.print();

  positions.clear();
  positions.push_back(1.0);
  positions.push_back(2.0);
  positions.push_back(3.0);
  positions.push_back(4.0);
  positions.push_back(5.0);
  positions.push_back(6.0);
  trajectories.push(positions);
  trajectories.print();

  positions.clear();
  positions.push_back(2.0);
  positions.push_back(3.0);
  positions.push_back(4.0);
  positions.push_back(5.0);
  positions.push_back(6.0);
  positions.push_back(7.0);
  trajectories.push(positions);
  trajectories.print();

  std::vector<std::vector<double>> new_trajs;
  for (double i = 0; i < 6; i++)
  {
    std::vector<double> traj;
    traj.push_back(10.0 + i);
    new_trajs.push_back(traj);
  }
  trajectories.update(new_trajs);
  trajectories.print();

  return 0;
}