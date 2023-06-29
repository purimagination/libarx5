#ifndef HARDWARE_INTERFACE_H
#define HARDWARE_INTERFACE_H

#include "../hardware/can.h"
#include "../hardware/dbus.h"
#include "../hardware/A8120.h"

#include <vector>
#include <string>
#include <thread>
#include <memory>

class HardwareInterface
{
public:
  HardwareInterface(std::string init_hardware_type = "real", std::string init_control_mode = "position");
  ~HardwareInterface() = default;

  // 获取关节状态
  std::vector<double> getJointStates();
  // 控制关节角度
  void setJointAngles(std::vector<double> set_joint_angles);
  // 控制关节力矩
  void setJointTorques(std::vector<double> set_joint_torques);
  // 标定电机
  void calibrateAll();

private:
  // 硬件类型（fake/real/sim)
  std::string hardware_type;
  // 控制模式（position/torque)
  std::string control_mode;
  // 关节状态
  std::vector<double> joint_states = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
  // 关节角度指令
  std::vector<double> joint_angles = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
  // 关节了力矩指令
  std::vector<double> joint_torques = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
  // CAN通信接口
  std::shared_ptr<can> can_interface;
  // 电机ID
  int motor_ids[6] = { 1, 2, 4, 5, 6, 7 };
  // 创建独立线程
  pthread_t thread_1;
  // 线程函数
  void updateHardware();
};

#endif