#include "arx5_base/hardware_interface.h"
#include "arx5_utils/rate.h"

HardwareInterface::HardwareInterface(std::string init_hardware_type, std::string init_control_mode)
{
  hardware_type = init_hardware_type;
  control_mode = init_control_mode;
  if (hardware_type == "real")
  {
    can_interface = std::make_shared<can>();
    extern OD_Motor_Msg rv_motor_msg[8];
  }
  std::cout<<"Hardware Interface Initialized. Hardware Type: "<<hardware_type<<", control_mode: "<<control_mode<<"."<<std::endl;
  // 创建线程
  std::thread thread_1(&HardwareInterface::updateHardware, this);
  thread_1.detach();
}

std::vector<double> HardwareInterface::getJointStates()
{
  return joint_states;
}

void HardwareInterface::setJointAngles(std::vector<double> set_joint_angles)
{
  joint_angles = set_joint_angles;
}

void HardwareInterface::setJointTorques(std::vector<double> set_joint_torques)
{
  joint_torques = set_joint_torques;
}

void HardwareInterface::updateHardware()
{
  Rate rate(100);
  while (1)
  {
    // 频率控制
    rate.sleep();
    // 获取电机硬件反馈
    if (hardware_type == "real")
    {
      // 位置控制
      if (control_mode == "position")
      {
        for (int i = 0; i < 6; i++)
        {
          can_interface->CAN_cmd_position(motor_ids[i], joint_angles[i] / M_PI * 180.0f, 300, 1000, 2);
          joint_states[i] = rv_motor_msg[motor_ids[i] - 1].angle_actual_float / 180 * M_PI;
        }
      }
      // 力矩控制
      else if (control_mode == "torque")
      {
        for (int i = 0; i < 6; i++)
        {
          can_interface->CAN_cmd_all(motor_ids[i], 0, 1, 0, 0, joint_torques[i]);
          joint_states[i] = rv_motor_msg[motor_ids[i] - 1].angle_actual_rad;
        }
      }
    }
    // 假反馈
    else if (hardware_type == "fake")
    {
      joint_states = joint_angles;
    }
  }
}