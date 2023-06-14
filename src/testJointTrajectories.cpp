#include <arx5_base/joint_trajectories.h>
#include <iostream>

int main()
{
  JointTrajectories joint_trajectories;

  std::vector<double> joint_positions;
  joint_positions.push_back(1.0);
  joint_positions.push_back(2.0);
  joint_positions.push_back(3.0);
  joint_positions.push_back(4.0);
  joint_positions.push_back(5.0);
  joint_positions.push_back(6.0);
  joint_trajectories.push(joint_positions);
  joint_trajectories.print();

  joint_positions.clear();
  joint_positions.push_back(2.0);
  joint_positions.push_back(3.0);
  joint_positions.push_back(4.0);
  joint_positions.push_back(5.0);
  joint_positions.push_back(6.0);
  joint_positions.push_back(7.0);
  joint_trajectories.push(joint_positions);
  joint_trajectories.print();

  joint_trajectories.pop();
  joint_trajectories.print();
  joint_trajectories.pop();
  joint_trajectories.print();
  joint_trajectories.pop();
  joint_trajectories.print();

  // 测试在没有数据的时候能不能pop
  joint_trajectories.pop();
  joint_trajectories.print();

  joint_positions.clear();
  joint_positions.push_back(1.0);
  joint_positions.push_back(2.0);
  joint_positions.push_back(3.0);
  joint_positions.push_back(4.0);
  joint_positions.push_back(5.0);
  joint_positions.push_back(6.0);
  joint_trajectories.push(joint_positions);
  joint_trajectories.print();

  joint_positions.clear();
  joint_positions.push_back(2.0);
  joint_positions.push_back(3.0);
  joint_positions.push_back(4.0);
  joint_positions.push_back(5.0);
  joint_positions.push_back(6.0);
  joint_positions.push_back(7.0);
  joint_trajectories.push(joint_positions);
  joint_trajectories.print();

  std::vector<std::vector<double>> new_trajs;
  for (double i = 0; i < 6; i++)
  {
    std::vector<double> traj;
    traj.push_back(10.0 + i);
    new_trajs.push_back(traj);
  }
  joint_trajectories.update(new_trajs);
  joint_trajectories.print();

  return 0;
}