#ifndef _FLY_CTRL_H
#define	_FLY_CTRL_H

#include "stm32f4xx.h"
#include "include.h"

//输出的控制类信息
extern float CH_ctrl[CH_NUM];	//具体输入给ctrl的遥控器值
extern u8 All_Out_Switch;
extern u8 my_height_mode;
extern float my_except_height;

//上位机监控变量（上位机监控状态，但不用于其他函数的控制）
extern u8 ctrl_command;			//当前飞行指令
extern u8 my_fly_mode;			//当前飞行模式
extern u8 height_command;			//当前飞行指令

//定时调用线程
void Fly_Mode_Ctrl(float T);	//飞行模式控制
void Fly_Height_Ctrl(float T);	//高度控制函数（5ms）
void Fly_Ctrl(float T);			//5ms姿态控制函数
void Fly_Ctrl_Cam(float T);		//摄像头数据频率姿态控制函数
void Fly_Ctrl_Flow(void);		//光流数据频率姿态控制函数

void Ctrl_Mode(float *ch_in);	//在fly_mode里调用

//数传输入处理函数
void set_except_height(u8 height);	//接收高度数据
void set_attitude_calibration(u8);
void set_all_out_switch(u8 cmd);

extern u8	height_mode,	//高度控制模式		0：手动控高		1：锁定当前高度		2：根据指令高度控高		3：起飞				4：降落
	roll_speed,				//速度横滚控制模式	0：手动控制		1：摄像头数据定点	2：光流数据定点
	pitch_speed,			//速度俯仰控制模式	0：手动控制		1：摄像头数据定点	2：摄像头数据前进		3：摄像头数据后退	4：光流数据定点		5：光流数据前进		6：光流数据后退
	roll_position,			//位置横滚控制		0：输出0			1：输出摄像头计算偏移
	pitch_position;			//位置俯仰控制		0：输出0			1：输出摄像头计算偏移


#endif
