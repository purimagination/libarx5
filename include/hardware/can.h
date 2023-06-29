#ifndef _CAN_H_
#define _CAN_H_

#include <stdint.h>
#include <string.h>
#include <iostream>
#include "../libcan/SocketCAN.h"
#include "A8120.h"

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
    // 电机内置位控模式
    void sendPositionCommand(uint16_t motor_id,float pos,uint16_t spd,uint16_t cur,uint8_t ack_status);
    // MIT控制模式
    void sendMITCommand(uint16_t motor_id, float kp, float kd, float pos, float spd, float tor);
    
private:
    SocketCAN can_adapter;
};

#endif