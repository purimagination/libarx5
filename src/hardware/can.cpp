#include "hardware/can.h"

m_rmd_t rmd_9015_01={0};
m_rmd_t rmd_9015_02={0};
m_rmd_t rmd_01={0};

void CAN_ReceiveHandlerProxy(can_frame_t *frame, void *ptr)
{
    ((ARX5_CAN *)ptr)->CAN_ReceiveFrame(frame);
}

ARX5_CAN::ARX5_CAN(std::string can_port)
{
    can_adapter.reception_handler_data = (void *)this;
    can_adapter.reception_handler = &CAN_ReceiveHandlerProxy;
    can_adapter.open(can_port.c_str());
}

ARX5_CAN::~ARX5_CAN()
{
    can_adapter.close();
}

void ARX5_CAN::calibrateSingleMotor(uint16_t motor_id)
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

void ARX5_CAN::sendPositionCommand(uint16_t motor_id,float pos,uint16_t spd,uint16_t cur,uint8_t ack_status)
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

void ARX5_CAN::sendMITCommand(uint16_t motor_id, float kp, float kd, float pos, float spd, float tor)
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

void ARX5_CAN::CAN_ReceiveFrame(can_frame_t *frame)
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
    case 0x141:
    {
        rmd_01.total_angle_last=rmd_01.position;
        rmd_01.speed_rpm=((int16_t)(frame->data[5]<<8) |(frame->data[4]))/57.3f;
        rmd_01.position=((int16_t)(frame->data[7]<<8) |(frame->data[6]));	
        rmd_01.real_current=((int16_t)(frame->data[2]<<8) |(frame->data[3]));
        if (rmd_01.position - rmd_01.total_angle_last > 32768)
            rmd_01.round_cnt--;
        else if (rmd_01.position - rmd_01.total_angle_last < -32768)
            rmd_01.round_cnt++;
        rmd_01.total_angle = rmd_01.round_cnt * 65536 + rmd_01.position;					
        break;
    }
    case 0x142:
    {
        rmd_9015_02.speed_rpm=((int16_t)(frame->data[5]<<8) |(frame->data[4]))/57.3f;
        rmd_9015_02.position =((int16_t)(frame->data[7]<<8) |(frame->data[6]));	
        break;
    } 
    default:
    {
        break;
    }
    }
}