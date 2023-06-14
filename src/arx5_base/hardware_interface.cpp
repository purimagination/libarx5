#include "arx5_base/hardware_interface.h"

HardwareInterface::HardwareInterface(std::string init_hardware_type, std::string init_control_mode)
{
  hardware_type = init_hardware_type;
  control_mode = init_control_mode;
  if (hardware_type == "real")
  {
    can_interface = std::make_shared<can>();
    extern OD_Motor_Msg rv_motor_msg[8];
  }
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
  while (1)
  {
    if (hardware_type == "real")
    {
      if (control_mode == "position")
      {
        // 控制电机
        for (int i = 0; i < 6; i++)
        {
          can_interface->CAN_cmd_position(motor_ids[i], joint_angles[i] / M_PI * 180.0f, 300, 1000, 2);
          joint_states[i] = rv_motor_msg[motor_ids[i] - 1].angle_actual_float / 180 * M_PI;
        }
      }
      else
      {
        // 控制电机
        for (int i = 0; i < 6; i++)
        {
          can_interface->CAN_cmd_all(4, 100, 10, 0, 0, joint_torques[i]);
          joint_states[i] = rv_motor_msg[motor_ids[i] - 1].angle_actual_float / 180 * M_PI;
        }
      }
    }
    else if (hardware_type == "fake")
    {
      joint_states = joint_angles;
    }
  }
}