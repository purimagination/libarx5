#include "hardware/can.h"

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
        case 0x7FF:
        {
            RV_can_data_repack(frame->can_id, frame->data, frame->can_dlc, 0);
            break;
        }
        default:
        {
            break;
        }
    }
}