#include "arx5_base/can.h"
#include "arx5_base/math_ops.h"

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

void ARX5_CAN::sendODPositionCommand(uint16_t motor_id,float pos,uint16_t spd,uint16_t cur,uint8_t ack_status)
{
    can_frame_t frame;
    frame.can_dlc = 8;
    _positionCommandRepack(motor_id,pos,spd,cur,ack_status,frame.data, &frame.can_id);
    if (can_adapter.is_open())
    {
        can_adapter.transmit(&frame);
    }
    else
    {
        std::cout << "Fail to open can bus" << std::endl;
    }
}

void ARX5_CAN::sendODMITCommand(uint16_t motor_id, float kp, float kd, float pos, float spd, float tor)
{
    can_frame_t frame;
    frame.can_dlc = 8;
    _MITCommandRepack(motor_id, kp, kd, pos, spd, tor, frame.data, &frame.can_id);
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
            _responseDataRepack(frame->can_id, frame->data, frame->can_dlc, 0);
            break;
        }
        default:
        {
            break;
        }
    }
}

void ARX5_CAN::_responseDataRepack(uint32_t msgID, uint8_t* Data, int32_t databufferlen, uint8_t comm_mode)
{
    uint8_t motor_id_t = 0;
    uint8_t ack_status = 0;
    int pos_int = 0;
    int spd_int = 0;
    int cur_int = 0;

    // CAN的电机反馈数据结构体
    MotorCommandFeedback _motor_command_feedback;
    // 用于不同格式的数据转换
    TypeConvert type_convert;

    if (msgID == 0x7FF)
    {
        if (Data[2] != 0x01) // determine whether it is a motor feedback instruction
            return;                     // it is not a motor feedback instruction
        if ((Data[0] == 0xff) && (Data[1] == 0xFF))
        {
            _motor_command_feedback.motor_id = Data[3] << 8 | Data[4];
            _motor_command_feedback.motor_feedback = 0x01;
            rv_motor_msg[_motor_command_feedback.motor_id-1].buildConnect = true;
        }
        else if ((Data[0] == 0x80) && (Data[1] == 0x80)) // inquire failed
        {
            _motor_command_feedback.motor_id = 0;
            _motor_command_feedback.motor_feedback = 0x80;
        }
        else if ((Data[0] == 0x7F) && (Data[1] == 0x7F)) // reset ID succeed
        {
            _motor_command_feedback.motor_id = 1;
            _motor_command_feedback.motor_feedback = 0x05;
        }
        else
        {
            _motor_command_feedback.motor_id = Data[0] << 8 | Data[1];
            _motor_command_feedback.motor_feedback = Data[3];
        }
    }
    else if (comm_mode == 0x00) // Response mode
    {
        ack_status = Data[0] >> 5;
        motor_id_t = msgID - 1;
        rv_motor_msg[motor_id_t].motor_id = motor_id_t;
        rv_motor_msg[motor_id_t].error = Data[0] & 0x1F;
        if (ack_status == 1) // response frame 1
        {
            pos_int = Data[1] << 8 | Data[2];
            spd_int = Data[3] << 4 | (Data[4] & 0xF0) >> 4;
            cur_int = (Data[4] & 0x0F) << 8 | Data[5];

            rv_motor_msg[motor_id_t].angle_actual_rad = uint_to_float(pos_int, POS_MIN, POS_MAX, 16);
            rv_motor_msg[motor_id_t].speed_actual_rad = uint_to_float(spd_int, SPD_MIN, SPD_MAX, 12);
            rv_motor_msg[motor_id_t].current_actual_float = uint_to_float(cur_int, I_MIN, I_MAX, 12);
            rv_motor_msg[motor_id_t].temperature = (Data[6] - 50) / 2;
        }
        else if (ack_status == 2) // response frame 2
        {
            type_convert.buf[0] = Data[4];
            type_convert.buf[1] = Data[3];
            type_convert.buf[2] = Data[2];
            type_convert.buf[3] = Data[1];
            rv_motor_msg[motor_id_t].angle_actual_float = type_convert.to_float;
            
            rv_motor_msg[motor_id_t].current_actual_int = Data[5] << 8 | Data[6];
            rv_motor_msg[motor_id_t].temperature = (Data[7] - 50) / 2;
            rv_motor_msg[motor_id_t].current_actual_float = rv_motor_msg[motor_id_t].current_actual_int / 100.0f;
        }
        else if (ack_status == 3) // response frame 3
        {
            type_convert.buf[0] = Data[4];
            type_convert.buf[1] = Data[3];
            type_convert.buf[2] = Data[2];
            type_convert.buf[3] = Data[1];
            rv_motor_msg[motor_id_t].speed_actual_float = type_convert.to_float;
            rv_motor_msg[motor_id_t].current_actual_int = Data[5] << 8 | Data[6];
            rv_motor_msg[motor_id_t].temperature = (Data[7] - 50) / 2;
            rv_motor_msg[motor_id_t].current_actual_float = rv_motor_msg[motor_id_t].current_actual_int / 100.0f;
        }
        else if (ack_status == 4) // response frame 4
        {
            if (databufferlen != 3)
                return;
            _motor_command_feedback.INS_code = Data[1];
            _motor_command_feedback.motor_feedback = Data[2];
        }
        else if (ack_status == 5) // response frame 5
        {
            _motor_command_feedback.INS_code = Data[1];
            if (_motor_command_feedback.INS_code == 1 & databufferlen == 6) // get position
            {
                type_convert.buf[0] = Data[5];
                type_convert.buf[1] = Data[4];
                type_convert.buf[2] = Data[3];
                type_convert.buf[3] = Data[2];
                rv_motor_msg[motor_id_t].angle_actual_float = type_convert.to_float;
                rv_motor_msg[motor_id_t].getInitAngle = true;
            }
            else if (_motor_command_feedback.INS_code == 2 & databufferlen == 6) // get speed
            {
                type_convert.buf[0] = Data[5];
                type_convert.buf[1] = Data[4];
                type_convert.buf[2] = Data[3];
                type_convert.buf[3] = Data[2];
                rv_motor_msg[motor_id_t].speed_actual_float = type_convert.to_float;
            }
            else if (_motor_command_feedback.INS_code == 3 & databufferlen == 6) // get current
            {
                type_convert.buf[0] = Data[5];
                type_convert.buf[1] = Data[4];
                type_convert.buf[2] = Data[3];
                type_convert.buf[3] = Data[2];
                rv_motor_msg[motor_id_t].current_actual_float = type_convert.to_float;
            }
            else if (_motor_command_feedback.INS_code == 4 & databufferlen == 6) // get power
            {
                type_convert.buf[0] = Data[5];
                type_convert.buf[1] = Data[4];
                type_convert.buf[2] = Data[3];
                type_convert.buf[3] = Data[2];
                rv_motor_msg[motor_id_t].power = type_convert.to_float;
            }
            else if (_motor_command_feedback.INS_code == 5 & databufferlen == 4) // get acceleration
            {
                rv_motor_msg[motor_id_t].acceleration = Data[2] << 8 | Data[3];
            }
            else if (_motor_command_feedback.INS_code == 6 & databufferlen == 4) // get linkage_KP
            {
                rv_motor_msg[motor_id_t].linkage_KP = Data[2] << 8 | Data[3];
            }
            else if (_motor_command_feedback.INS_code == 7 & databufferlen == 4) // get speed_KI
            {
                rv_motor_msg[motor_id_t].speed_KI = Data[2] << 8 | Data[3];
            }
            else if (_motor_command_feedback.INS_code == 8 & databufferlen == 4) // get feedback_KP
            {
                rv_motor_msg[motor_id_t].feedback_KP = Data[2] << 8 | Data[3];
            }
            else if (_motor_command_feedback.INS_code == 9 & databufferlen == 4) // get feedback_KD
            {
                rv_motor_msg[motor_id_t].feedback_KD = Data[2] << 8 | Data[3];
            }
        }
    }
    else if (comm_mode == 0x01) // automatic feedback mode
    {

        motor_id_t = msgID - 0x205;
        rv_motor_msg[motor_id_t].angle_actual_int = (uint16_t)(Data[0] << 8 | Data[1]);
        rv_motor_msg[motor_id_t].speed_actual_int = (int16_t)(Data[2] << 8 | Data[3]);
        rv_motor_msg[motor_id_t].current_actual_int = (Data[4] << 8 | Data[5]);
        rv_motor_msg[motor_id_t].temperature = Data[6];
        rv_motor_msg[motor_id_t].error = Data[7];
    }
}

void ARX5_CAN::_positionCommandRepack(uint16_t motor_id,float pos,uint16_t spd,uint16_t cur,uint8_t ack_status, uint8_t* Data, uint32_t* canID)
{
    *canID = motor_id;
  	if(spd>18000) spd=18000;
	if(cur>3000) cur=3000;
	if(ack_status>3)
    {
        return;
    }
    // 用于不同格式的数据转换
    TypeConvert type_convert;
    type_convert.to_float=pos;
	Data[0]=0x20|(type_convert.buf[3]>>3);
	Data[1]=(type_convert.buf[3]<<5)|(type_convert.buf[2]>>3);
	Data[2]=(type_convert.buf[2]<<5)|(type_convert.buf[1]>>3);
	Data[3]=(type_convert.buf[1]<<5)|(type_convert.buf[0]>>3);
	Data[4]=(type_convert.buf[0]<<5)|(spd>>10);
	Data[5]=(spd&0x3FC)>>2;
	Data[6]=(spd&0x03)<<6|(cur>>6);
	Data[7]=(cur&0x3F)<<2|ack_status;
}

void ARX5_CAN::_MITCommandRepack(uint16_t motor_id, float kp, float kd, float pos, float spd, float tor, uint8_t* Data, uint32_t* canID)
{
    int kp_int;
    int kd_int;
    int pos_int;
    int spd_int;
    int tor_int;

    *canID = motor_id;
  
    if (kp > KP_MAX){kp = KP_MAX;}
    else if (kp < KP_MIN){kp = KP_MIN;}
    if (kd > KD_MAX){kd = KD_MAX;}
    else if (kd < KD_MIN){kd = KD_MIN;}
    if (pos > POS_MAX){pos = POS_MAX;}
    else if (pos < POS_MIN) {pos = POS_MIN;}
    if (spd > SPD_MAX){spd = SPD_MAX;}
    else if (spd < SPD_MIN){spd = SPD_MIN;}
    if (tor > T_MAX){tor = T_MAX;}
    else if (tor < T_MIN){tor = T_MIN;}

    kp_int = float_to_uint(kp, KP_MIN, KP_MAX, 12);
    kd_int = float_to_uint(kd, KD_MIN, KD_MAX, 9);
    pos_int = float_to_uint(pos, POS_MIN, POS_MAX, 16);
    spd_int = float_to_uint(spd, SPD_MIN, SPD_MAX, 12);
    tor_int = float_to_uint(tor, T_MIN, T_MAX, 12);

    Data[0] = 0x00 | (kp_int >> 7);                             // kp5
    Data[1] = ((kp_int & 0x7F) << 1) | ((kd_int & 0x100) >> 8); // kp7+kd1
    Data[2] = kd_int & 0xFF;
    Data[3] = pos_int >> 8;
    Data[4] = pos_int & 0xFF;
    Data[5] = spd_int >> 4;
    Data[6] = (spd_int & 0x0F) << 4 | (tor_int >> 8);
    Data[7] = tor_int & 0xff;
}

MotorState* ARX5_CAN::getMotorState()
{
    return rv_motor_msg;
}

void ARX5_CAN::sendLKTorqueCommand(int16_t torque)
{
    can_frame_t frame;
    frame.can_id = 0x280;
    frame.can_dlc = 8;
    frame.data[0] = torque;
    frame.data[1] = torque >> 8;
    frame.data[2] = 0.0;
    frame.data[3] = 0.0;
    frame.data[4] = 0.0;
    frame.data[5] = 0.0;
    frame.data[6] = 0.0;
    frame.data[7] = 0.0;
    if (can_adapter.is_open())
    {
        can_adapter.transmit(&frame);
    }
    else
    {
        std::cout << "Fail to open can bus" << std::endl;
    }
}                      