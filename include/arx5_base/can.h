#ifndef _CAN_H_
#define _CAN_H_

#include <stdint.h>
#include <string.h>
#include <iostream>
#include "../libcan/SocketCAN.h"

#define KP_MIN 0.0f
#define KP_MAX 500.0f
#define KD_MIN 0.0f
#define KD_MAX 50.0f
#define POS_MIN -12.5f
#define POS_MAX 12.5f
#define SPD_MIN -18.0f
#define SPD_MAX 18.0f
#define T_MIN -30.0f
#define T_MAX 30.0f
#define I_MIN -30.0f
#define I_MAX 30.0f

// 电机反馈帧结构体？
typedef struct
{
    uint16_t motor_id;
    uint8_t INS_code;  // instruction code.
    uint8_t motor_feedback; // motor CAN communication feedback.
} MotorCommandFeedback;

// 电机状态结构体
typedef struct
{
    int16_t angle_actual_int = 0;
    int16_t speed_actual_int = 0;
    int16_t current_actual_int = 0;
    float speed_actual_rad = 0;
    float angle_actual_rad = 0.0;
    uint16_t motor_id = 0;
    uint8_t temperature = 0;
    uint8_t error = 0;
    float angle_actual_float = 0.0;
    float speed_actual_float = 0.0;
    float current_actual_float = 0.0;
    float power = 0.0;
    uint16_t acceleration = 0;
    uint16_t linkage_KP = 0;
    uint16_t speed_KI = 0;
    uint16_t feedback_KP = 0;
    uint16_t feedback_KD = 0;
    bool buildConnect = 0;
    bool getInitAngle = 0;
} MotorState;

// 使用Union来转换数据的不同写法
union TypeConvert
{
	float to_float;
	int to_int;
	unsigned int to_uint;
	uint8_t buf[4];
};

// 负责can收发
class ARX5_CAN
{
    public:
        ARX5_CAN(std::string can_port);
        ~ARX5_CAN();

        // 接收到CAN反馈后的处理函数
        void CAN_ReceiveFrame(can_frame_t *frame);
        // 标定单个电机
        void calibrateSingleMotor(uint16_t motor_id);
        // OD电机位置控制模式
        void sendODPositionCommand(uint16_t motor_id,float pos,uint16_t spd,uint16_t cur,uint8_t ack_status);
        // OD电机MIT控制模式
        void sendODMITCommand(uint16_t motor_id, float kp, float kd, float pos, float spd, float tor);
        // LK电机力矩控制模式
        void sendLKTorqueCommand(int16_t torque);
        // 获取电机状态
        MotorState* getMotorState();
        
    private:
        // CAN总线适配器
        SocketCAN can_adapter;
        // 对CAN收到的电机反馈数据进行解包
        void _responseDataRepack(uint32_t msgID, uint8_t* Data, int32_t databufferlen, uint8_t comm_mode);
        // 电机位置控制模式消息封装
        void _positionCommandRepack(uint16_t motor_id,float pos,uint16_t spd,uint16_t cur,uint8_t ack_status, uint8_t* Data, uint32_t* canID);
        // 电机MIT控制模式消息封装
        void _MITCommandRepack(uint16_t motor_id, float kp, float kd, float pos, float spd, float tor, uint8_t* Data, uint32_t* canID);
        // 储存电机当前状态
        MotorState rv_motor_msg[8];
};

#endif