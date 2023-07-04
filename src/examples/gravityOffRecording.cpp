#include <arx5_base/hardware_interface.h>
#include <arx5_base/kinematics_dynamics.h>
#include <arx5_base/teaching.h>
#include <arx5_base/rate.h>

// 是否停止录制
int stopRecording = 0;
// 运行频率
float frequency = 100;
// 录制数据文件名称
std::string file_name = "gravity_off";
// 录制数据文件保存路径
std::string save_path = "/home/hanzx/Dev/Projects/libarx5/saved_data";
// 机械臂urdf文件路径
std::string urdf_path = "/home/hanzx/Dev/Projects/libarx5/urdf/arx5_kdl.urdf";

// 线程函数，判断是否停止录制
void ifStoping()
{
  while(1)
  {
    std::cout<<"type 'yes' to stop recording."<<std::endl;
    std::string answer;
    std::cin>>answer;
    if(answer == "yes")
    {
      stopRecording = 1;
    }
  }
}

int main()
{
  // 生成硬件接口对象
  HardwareInterface hardware_interface("real", "torque");
  // 生成运动学、动力学求解器
  KinematicsDynamics kinematics_dynamics(urdf_path);
  // 生成频率控制器
  Rate loop_rate(frequency);
  // 生成数据录制器
  Recorder recorder(save_path, file_name, frequency);

  // 末端关节受力
  std::vector<double> end_effector_force = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  // 动力学逆解结果
  std::vector<double> id_result = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  // 关节状态（角度）
  std::vector<double> joint_states = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

  // 初始给一个零力矩
  hardware_interface.setODJointTorques(id_result);

  // 创建线程
  std::thread thread_1(ifStoping);
  thread_1.detach();

  while (!stopRecording)
  {
    // 控制频率
    loop_rate.sleep();

    // 获取关节状态
    std::vector<double> joint_states = hardware_interface.getJointAngles();

    // 记录关节状态
    recorder.writeData(joint_states);

    // 更新运动学动力学求解器的关节状态
    kinematics_dynamics.updateJointStates(joint_states);

    // 动力学逆解
    id_result = kinematics_dynamics.solveID(end_effector_force);

    // 将动力学逆解力矩赋值给关节
    hardware_interface.setODJointTorques(id_result);
  }

  recorder.endRecording();

  return 0;
}