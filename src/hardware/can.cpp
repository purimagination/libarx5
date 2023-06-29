#include "hardware/can.h"

void CAN_ReceiveHandlerProxy(can_frame_t *frame, void *ptr)
{
    ((can *)ptr)->CAN_ReceiveFrame(frame);
}

can::can()
{
    can_adapter.reception_handler_data = (void *)this;
    can_adapter.reception_handler = &CAN_ReceiveHandlerProxy;
    can_adapter.open("can0");
}

can::~can()
{
    can_adapter.close();
}

void can::calibrateSingleMotor(uint16_t motor_id)
{   
    can_frame_t frame;
    frame.can_id = 0x7FF;
    frame.can_dlc = 4;

	frame.data[0]=motor_id>>8;
	frame.data[1]=motor_id&0xff;
	frame.data[2]=0x00;
	frame.data[3]=0x03;

    if (can_adapter.is_open())
    {
        can_adapter.transmit(&frame);
    }
    else
    {
        std::cout << "Fail to open can bus" << std::endl;
    }
}

void can::CAN_cmd_position(uint16_t motor_id,float pos,uint16_t spd,uint16_t cur,uint8_t ack_status)
{
    can_frame_t frame;
    frame.can_dlc = 8;
    send_motor_position(motor_id,pos,spd,cur,ack_status,frame.data, &frame.can_id);
    if (can_adapter.is_open())
    {
        can_adapter.transmit(&frame);
    }
    else
    {
        std::cout << "Fail to open can bus" << std::endl;
    }
}

void can::CAN_cmd_all(uint16_t motor_id, float kp, float kd, float pos, float spd, float tor)
{
    can_frame_t frame;
    frame.can_dlc = 8;
    send_motor_ctrl_cmd(motor_id, kp, kd, pos, spd, tor, frame.data, &frame.can_id);
    if (can_adapter.is_open())
    {
        can_adapter.transmit(&frame);
    }
    else
    {
        std::cout << "Fail to open can bus" << std::endl;
    }
}

// Motor A8120 
// motor id 0x01 ~ 0x04
void can::CAN_cmd_fpc1(float kp[4], float kd[4], float pos[4], float spd[4], float tor[4])
{
    for (int i = 0; i < 4; i++)
    {
        can_frame_t frame;
        frame.can_dlc = 8;
        send_motor_ctrl_cmd(i+1, kp[i], kd[i], pos[i], spd[i], tor[i], frame.data, &frame.can_id);
        if (can_adapter.is_open())
        {
            can_adapter.transmit(&frame);
        }
        else
        {
            std::cout << "Fail to open can bus" << std::endl;
        }
    }
}

// Motor A8120 
// motor id 0x05 ~ 0x08
void can::CAN_cmd_fpc2(float kp[4], float kd[4], float pos[4], float spd[4], float tor[4])
{
    for (int i = 0; i < 4; i++)
    {
        can_frame_t frame;
        frame.can_dlc = 8;
        send_motor_ctrl_cmd(i+5, kp[i], kd[i], pos[i], spd[i], tor[i], frame.data, &frame.can_id);
        if (can_adapter.is_open())
        {
            can_adapter.transmit(&frame);
        }
        else
        {
            std::cout << "Fail to open can bus" << std::endl;
        }
    }
}

/**
 * @description: 收到can bus的消息
 */
void can::CAN_ReceiveFrame(can_frame_t *frame)
{

    switch (frame->can_id)
    {
    case 0x01:
    case 0x02:
    case 0x03:
    case 0x04:
    case 0x05:
    case 0x06:
    case 0x07:
    case 0x08:
    case 0x7FF:
    {
        RV_can_data_repack(frame->can_id, frame->data, frame->can_dlc, 0);
        break;
    }
    case 0x205:
    case 0x206:
    case 0x207:
    case 0x208:
    case 0x209:
    case 0x20A:
    case 0x20B:
    case 0x20C:
    {
        break;
    }
    case 0x141:
    {					
        break;
    }
    case 0x142:
    {
        break;
    }   
   
    case 0x501:
    {
        // std::cout << "# frame can_id= " << frame->can_id << std::endl;
        // std::cout << "# frame data0-3  = " << frame->data[0] << " " << frame->data[1] << " " << frame->data[2] << " " << frame->data[3] << " " << std::endl;
        // std::cout << "# frame data4-7  = " << frame->data[4] << " " << frame->data[5] << " " << frame->data[6] << " " << frame->data[7] << " " << std::endl;
        // IMU
        // float tmp[2];
        // memcpy((uint8_t *)(&tmp[0]), (uint8_t *)(&frame->data[0]), 4);
        // memcpy((uint8_t *)(&tmp[1]), (uint8_t *)(&frame->data[4]), 4);
        // IMU.imu[0] = tmp[0] * 0.0174533;
        // IMU.imu[1] = tmp[1] * 0.0174533;
        break;
    }
    case 0x502:
    {
        // std::cout << "# frame can_id= " << frame->can_id << std::endl;
        // std::cout << "# frame data0-3  = " << frame->data[0] << " " << frame->data[1] << " " << frame->data[2] << " " << frame->data[3] << " " << std::endl;
        // std::cout << "# frame data4-7  = " << frame->data[4] << " " << frame->data[5] << " " << frame->data[6] << " " << frame->data[7] << " " << std::endl;
        // // Gyro
        // memcpy((uint8_t *)(&IMU.gyro[0]), (uint8_t *)(&frame->data[0]), 4);
        // memcpy((uint8_t *)(&IMU.gyro[1]), (uint8_t *)(&frame->data[4]), 4);
        break;
    }
    default:
    {
        break;
    }
    }
}

bool can::is_open()
{
    return can_adapter.is_open();
}