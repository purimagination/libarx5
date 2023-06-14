#ifndef TRAJECTORIES_H
#define TRAJECTORIES_H

#include <vector>

class Trajectories
{
public:
  Trajectories();
  ~Trajectories() = default;
  // 在轨迹队列中添加一个轨迹点
  void push(std::vector<double> joint_positions);
  // 删除轨迹队列中的第一个轨迹点
  void pop();
  // 更新轨迹
  void update(std::vector<std::vector<double>> new_trajectories);
  // 返回轨迹队列中的第一个轨迹点
  std::vector<double> front();
  // 打印轨迹队列中的所有轨迹点
  void print();
  // 返回轨迹队列中的轨迹点的个数
  int size();

private:
  // 轨迹队列
  std::vector<std::vector<double>> trajectories_;
};

#endif