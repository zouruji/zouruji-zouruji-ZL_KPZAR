#include <Arduino.h>
#line 1 "F:\\Desktop\\03-源码例程\\例程09————2路电机驱动控制\\ZL_KPZAR\\ZL_KPZAR.ino"
/****************************************************************************
	*	@笔者	：	W
	*	@日期	：	2019年12月28日
	*	@所属	：	杭州众灵科技
	*	@论坛	：	www.ZL-robot.com
	*	@功能	：	ZL-KPZ控制板（AR版）模块例程9————2路电机驱动控制
	*	@函数列表：
	*	1.	void setup(void) -- 初始化函数
	*	2.	void loop(void) -- 主循环函数
 ****************************************************************************/

/*******全局变量定义*******/
u8 i=0;
int motor1_speed=0, motor2_speed=0;

#line 16 "F:\\Desktop\\03-源码例程\\例程09————2路电机驱动控制\\ZL_KPZAR\\ZL_KPZAR.ino"
void setup(void);
#line 20 "F:\\Desktop\\03-源码例程\\例程09————2路电机驱动控制\\ZL_KPZAR\\ZL_KPZAR.ino"
void loop(void);
#line 25 "F:\\Desktop\\03-源码例程\\例程09————2路电机驱动控制\\ZL_KPZAR\\z_key.ino"
void key_init(void);
#line 17 "F:\\Desktop\\03-源码例程\\例程09————2路电机驱动控制\\ZL_KPZAR\\z_loop.ino"
void loop_key(void);
#line 24 "F:\\Desktop\\03-源码例程\\例程09————2路电机驱动控制\\ZL_KPZAR\\z_motor.ino"
void motor1_SetSpeed(int Speed);
#line 46 "F:\\Desktop\\03-源码例程\\例程09————2路电机驱动控制\\ZL_KPZAR\\z_motor.ino"
void motor2_SetSpeed(int Speed);
#line 18 "F:\\Desktop\\03-源码例程\\例程09————2路电机驱动控制\\ZL_KPZAR\\z_setup.ino"
void setup_key(void);
#line 28 "F:\\Desktop\\03-源码例程\\例程09————2路电机驱动控制\\ZL_KPZAR\\z_setup.ino"
void setup_motor(void);
#line 16 "F:\\Desktop\\03-源码例程\\例程09————2路电机驱动控制\\ZL_KPZAR\\ZL_KPZAR.ino"
void setup(void) {																																																																																																																															//ZL
	setup_key();			//初始化按键
	setup_motor();			//初始化电机相关设置
}
void loop(void) {
	loop_key();				//循环检测按键状态
}

#line 1 "F:\\Desktop\\03-源码例程\\例程09————2路电机驱动控制\\ZL_KPZAR\\z_key.ino"
/****************************************************************************
	*	@笔者	：	W
	*	@日期	：	2019年12月28日
	*	@所属	：	杭州众灵科技
	*	@论坛	：	www.ZL-robot.com
	*	@功能	：	存放按键相关的函数
	*	@函数列表：
	*	1.	void key_init(void) -- 初始化按键
 ****************************************************************************/

/*******按键管脚映射表*******/
#define KEY1_PIN			A1
#define KEY2_PIN			A2

/*******按键快捷指令表*******/
#define KEY1	 digitalRead(KEY1_PIN)			//读取按键1状态
#define KEY2	 digitalRead(KEY2_PIN)			//读取按键2状态

/***********************************************
	函数名称:		key_init() 
	功能介绍:		初始化按键
	函数参数:		无
	返回值:			无
 ***********************************************/
void key_init(void) {
	pinMode(KEY1_PIN,INPUT_PULLUP);					//设置引脚为输入模式
	pinMode(KEY2_PIN,INPUT_PULLUP);					//设置引脚为输入模式
}

#line 1 "F:\\Desktop\\03-源码例程\\例程09————2路电机驱动控制\\ZL_KPZAR\\z_loop.ino"
/****************************************************************************
	*	@笔者	：	W
	*	@日期	：	2019年12月28日
	*	@所属	：	杭州众灵科技
	*	@论坛	：	www.ZL-robot.com
	*	@功能	：	存放永久循环执行的函数
	*	@函数列表：
	*	1.	void loop_key(void) -- 循环检测按键状态
 ****************************************************************************/

/***********************************************
	函数名称:		loop_key() 
	功能介绍:		循环检测按键状态
	函数参数:		无
	返回值:			无
 ***********************************************/
void loop_key(void) {
	static u32 systick_ms_bak = 0;

/*****************按键1按下检测*****************/
	if(KEY1==0){
		delay(50);
		if(KEY1==0){
/*****************按键1长按检测*****************/
			systick_ms_bak = millis();
			while(KEY1==0){
				if(millis() - systick_ms_bak >= 500) {
/*****************按键1长按执行*****************/
/***********************************************/
				}
			}
/*****************按键1松开执行*****************/
/***********************************************/
/*****************按键1单次检测*****************/
			if(millis() - systick_ms_bak < 500) {
/*****************按键1单次执行*****************/
				motor1_speed+=10;
				if(motor1_speed>1000)	motor1_speed=1000;
				motor1_SetSpeed(motor1_speed);
				motor2_speed+=10;
				if(motor2_speed>1000)	motor2_speed=1000;
				motor2_SetSpeed(motor2_speed);
/***********************************************/
			}
		}
	}
	
/*****************按键2按下检测*****************/
	if(KEY2==0){
		delay(50);
		if(KEY2==0){
/*****************按键2长按检测*****************/
			systick_ms_bak = millis();
			while(KEY2==0){
				if(millis() - systick_ms_bak >= 500) {
/*****************按键2长按执行*****************/
/***********************************************/
				}
			}
/*****************按键2松开执行*****************/
/***********************************************/
/*****************按键2单次检测*****************/
			if(millis() - systick_ms_bak < 500) {
/*****************按键2单次执行*****************/
				motor1_speed-=10;
				if(motor1_speed<-1000)	motor1_speed=-1000;
				motor1_SetSpeed(motor1_speed);
				motor2_speed-=10;
				if(motor2_speed<-1000)	motor2_speed=-1000;
				motor2_SetSpeed(motor2_speed);
/***********************************************/
			}
		}
	}
}

#line 1 "F:\\Desktop\\03-源码例程\\例程09————2路电机驱动控制\\ZL_KPZAR\\z_motor.ino"
/****************************************************************************
	*	@笔者	：	W
	*	@日期	：	2019年12月28日
	*	@所属	：	杭州众灵科技
	*	@论坛	：	www.ZL-robot.com
	*	@功能	：	存放电机相关的函数
	*	@函数列表：
	*	1.	void motor1_SetSpeed(int Speed) -- 电机1速度控制
	*	2.	void motor2_SetSpeed(int Speed) -- 电机2速度控制
 ****************************************************************************/

/*******电机控制指令表*******/
#define motor1_p(x) analogWrite(3,x)
#define motor1_n(x) analogWrite(5,x)
#define motor2_p(x) analogWrite(6,x)
#define motor2_n(x) analogWrite(9,x)

/***********************************************
	函数名称:		motor1_SetSpeed() 
	功能介绍:		电机1速度控制
	函数参数:		Speed 速度
	返回值:			无
 ***********************************************/
void motor1_SetSpeed(int Speed) {
	if(Speed==0) {
		motor1_p(0);
		motor1_n(0);
	}
	else if(Speed>0) {
		Speed=Speed/5+55;
		motor1_p(Speed);
		motor1_n(0);
	} else {
		Speed=-1*Speed/5+55;
		motor1_p(0);
		motor1_n(Speed);
	}
}

/***********************************************
	函数名称:		motor2_SetSpeed() 
	功能介绍:		电机2速度控制
	函数参数:		Speed 速度
	返回值:			无
 ***********************************************/
void motor2_SetSpeed(int Speed) {
	if(Speed==0) {
		motor2_p(0);
		motor2_n(0);
	}
	else if(Speed>0) {
		Speed=Speed/5+55;
		motor2_p(Speed);
		motor2_n(0);
	} else {
		Speed=-1*Speed/5+55;
		motor2_p(0);
		motor2_n(Speed);
	}
}


#line 1 "F:\\Desktop\\03-源码例程\\例程09————2路电机驱动控制\\ZL_KPZAR\\z_setup.ino"
/****************************************************************************
	*	@笔者	：	W
	*	@日期	：	2019年12月28日
	*	@所属	：	杭州众灵科技
	*	@论坛	：	www.ZL-robot.com
	*	@功能	：	存放初始化相关的函数
	*	@函数列表：
	*	1.	void setup_key(void) -- 初始化按键
	*	2.	void setup_motor(void) -- 初始化电机
 ****************************************************************************/

/***********************************************
	函数名称:		setup_key() 
	功能介绍:		初始化按键
	函数参数:		无
	返回值:			无
 ***********************************************/
void setup_key(void) {
	key_init();
}

/***********************************************
	函数名称:		setup_motor() 
	功能介绍:		初始化电机
	函数参数:		无
	返回值:			无
 ***********************************************/
void setup_motor(void) {
	motor1_speed = 0;
	motor2_speed = 0;
	motor1_SetSpeed(motor1_speed);
	motor2_SetSpeed(motor2_speed);
}

