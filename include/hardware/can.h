#ifndef _CAN_H_
#define _CAN_H_

#include <stdint.h>
#include <string.h>
#include <iostream>
#include "../libcan/SocketCAN.h"
#include "A8120.h"

// 负责can收发
class can
{
public:
    can();
    ~can();

    // sensor_msgs::Imu ImuMsg;
    // Motor_measure_t Motor[MOTOR_NUM] = {0};

    void CAN_ReceiveFrame(can_frame_t *frame);

    void calibrateSingleMotor(uint16_t motor_id);
    void CAN_cmd_position(uint16_t motor_id,float pos,uint16_t spd,uint16_t cur,uint8_t ack_status);

    void CAN_cmd_all(uint16_t motor_id, float kp, float kd, float pos, float spd, float tor);
    // motor id 0x01 ~ 0x04
    void CAN_cmd_fpc1(float kp[4], float kd[4], float pos[4], float spd[4], float tor[4]);
    // motor id 0x05 ~ 0x08
    void CAN_cmd_fpc2(float kp[4], float kd[4], float pos[4], float spd[4], float tor[4]);
    void MotorSetting(uint16_t motor_id,uint8_t cmd);

    bool is_open();
    
private:
    SocketCAN can_adapter;
};

#endif