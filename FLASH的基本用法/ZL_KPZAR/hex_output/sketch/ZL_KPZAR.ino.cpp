#include <Arduino.h>
#line 1 "\\\\tb-pc\\产品资料\\001-线上产品\\103-DIY电控系统\\002 开源控制器\\003-ZL-KPZAR（开源开拓者Arduino控制器）\\03-源码例程\\例程05————FLASH的基本用法\\ZL_KPZAR\\ZL_KPZAR.ino"
/****************************************************************************
	*	@笔者	：	W
	*	@日期	：	2019年12月28日
	*	@所属	：	杭州众灵科技
	*	@论坛	：	www.ZL-robot.com
	*	@功能	：	ZL-KPZ控制板（AR版）模块例程5————FLASH的基本用法
	*	@函数列表：
	*	1.	void setup(void) -- 初始化函数
	*	2.	void loop(void) -- 主循环函数
    *   
    *   实验端口：SPI接口 W25Q64
    *   实验现象：串口打印读写W25Q64
 ****************************************************************************/

#include <winbondflash.h>

/*******全局变量宏定义*******/
#define UART_RECEIVE_BUF_SIZE 100

/*******全局变量定义*******/
u8 i=0;
u8 uart_receive_buf[UART_RECEIVE_BUF_SIZE]={0}, uart_receive_buf_index, uart_get_ok;
u8 a[1]={1}, b[1]={1};
winbondFlashSPI mem;

#line 26 "\\\\tb-pc\\产品资料\\001-线上产品\\103-DIY电控系统\\002 开源控制器\\003-ZL-KPZAR（开源开拓者Arduino控制器）\\03-源码例程\\例程05————FLASH的基本用法\\ZL_KPZAR\\ZL_KPZAR.ino"
void setup(void);
#line 46 "\\\\tb-pc\\产品资料\\001-线上产品\\103-DIY电控系统\\002 开源控制器\\003-ZL-KPZAR（开源开拓者Arduino控制器）\\03-源码例程\\例程05————FLASH的基本用法\\ZL_KPZAR\\ZL_KPZAR.ino"
void loop(void);
#line 26 "\\\\tb-pc\\产品资料\\001-线上产品\\103-DIY电控系统\\002 开源控制器\\003-ZL-KPZAR（开源开拓者Arduino控制器）\\03-源码例程\\例程05————FLASH的基本用法\\ZL_KPZAR\\z_beep.ino"
void beep_init(void);
#line 36 "\\\\tb-pc\\产品资料\\001-线上产品\\103-DIY电控系统\\002 开源控制器\\003-ZL-KPZAR（开源开拓者Arduino控制器）\\03-源码例程\\例程05————FLASH的基本用法\\ZL_KPZAR\\z_beep.ino"
void BEEP_F(void);
#line 18 "\\\\tb-pc\\产品资料\\001-线上产品\\103-DIY电控系统\\002 开源控制器\\003-ZL-KPZAR（开源开拓者Arduino控制器）\\03-源码例程\\例程05————FLASH的基本用法\\ZL_KPZAR\\z_setup.ino"
void setup_beep(void);
#line 29 "\\\\tb-pc\\产品资料\\001-线上产品\\103-DIY电控系统\\002 开源控制器\\003-ZL-KPZAR（开源开拓者Arduino控制器）\\03-源码例程\\例程05————FLASH的基本用法\\ZL_KPZAR\\z_setup.ino"
void setup_uart(void);
#line 40 "\\\\tb-pc\\产品资料\\001-线上产品\\103-DIY电控系统\\002 开源控制器\\003-ZL-KPZAR（开源开拓者Arduino控制器）\\03-源码例程\\例程05————FLASH的基本用法\\ZL_KPZAR\\z_setup.ino"
void setup_flash(void);
#line 20 "\\\\tb-pc\\产品资料\\001-线上产品\\103-DIY电控系统\\002 开源控制器\\003-ZL-KPZAR（开源开拓者Arduino控制器）\\03-源码例程\\例程05————FLASH的基本用法\\ZL_KPZAR\\z_uart.ino"
void uart_init(u32 baud);
#line 30 "\\\\tb-pc\\产品资料\\001-线上产品\\103-DIY电控系统\\002 开源控制器\\003-ZL-KPZAR（开源开拓者Arduino控制器）\\03-源码例程\\例程05————FLASH的基本用法\\ZL_KPZAR\\z_uart.ino"
void uart_send_byte(u8 dat);
#line 40 "\\\\tb-pc\\产品资料\\001-线上产品\\103-DIY电控系统\\002 开源控制器\\003-ZL-KPZAR（开源开拓者Arduino控制器）\\03-源码例程\\例程05————FLASH的基本用法\\ZL_KPZAR\\z_uart.ino"
void uart_send_str(char *s);
#line 52 "\\\\tb-pc\\产品资料\\001-线上产品\\103-DIY电控系统\\002 开源控制器\\003-ZL-KPZAR（开源开拓者Arduino控制器）\\03-源码例程\\例程05————FLASH的基本用法\\ZL_KPZAR\\z_uart.ino"
void uart_send_int(int tmp);
#line 26 "\\\\tb-pc\\产品资料\\001-线上产品\\103-DIY电控系统\\002 开源控制器\\003-ZL-KPZAR（开源开拓者Arduino控制器）\\03-源码例程\\例程05————FLASH的基本用法\\ZL_KPZAR\\ZL_KPZAR.ino"
void setup(void) {																																																																																																																															//ZL
	setup_beep();			//初始化蜂鸣器BEEP
	setup_uart();			//初始化串口
	setup_flash();			//初始化flash

	uart_send_str("a\tb\r\n");
	mem.setWriteEnable(true);
	mem.read(0,a,1);
	uart_send_int(a[0]);
	uart_send_str("\t");
	uart_send_int(b[0]);
	uart_send_str("\r\n");
	a[0]++;	b[0]++;
	uart_send_int(a[0]);
	uart_send_str("\t");
	uart_send_int(b[0]);
	uart_send_str("\r\n");
	mem.eraseSector(0,4096);
	mem.write(0,a,1);
}
void loop(void) {
}

#line 1 "\\\\tb-pc\\产品资料\\001-线上产品\\103-DIY电控系统\\002 开源控制器\\003-ZL-KPZAR（开源开拓者Arduino控制器）\\03-源码例程\\例程05————FLASH的基本用法\\ZL_KPZAR\\z_beep.ino"
/****************************************************************************
	*	@笔者	：	W
	*	@日期	：	2019年12月28日
	*	@所属	：	杭州众灵科技
	*	@论坛	：	www.ZL-robot.com
	*	@功能	：	存放蜂鸣器BEEP相关的函数
	*	@函数列表：
	*	1.	void beep_init(void) -- 初始化蜂鸣器BEEP
	*	2.	void BEEP_F(void) -- 翻转蜂鸣器BEEP
 ****************************************************************************/

/*******BEEP管脚映射表*******/
#define BEEP_PIN			4

/*******BEEP快捷指令表*******/
#define BEEP	 digitalRead(BEEP_PIN)			//读取蜂鸣器BEEP状态
#define BEEP_H() digitalWrite(BEEP_PIN,HIGH)		//蜂鸣器BEEP打开
#define BEEP_L() digitalWrite(BEEP_PIN,LOW)	//蜂鸣器BEEP关闭

/***********************************************
	函数名称:		beep_init(void)
	功能介绍:		初始化蜂鸣器
	函数参数:		无
	返回值:			无
 ***********************************************/
void beep_init(void) {
	pinMode(BEEP_PIN,OUTPUT);					//设置引脚为输出模式
}

/***********************************************
	函数名称：	BEEP_F(void)
	功能介绍：	翻转蜂鸣器BEEP
	函数参数：	无
	返回值：	无
 ***********************************************/
void BEEP_F(void) {
	if(BEEP==0)	
		BEEP_L();
	else 
		BEEP_H();
}

#line 1 "\\\\tb-pc\\产品资料\\001-线上产品\\103-DIY电控系统\\002 开源控制器\\003-ZL-KPZAR（开源开拓者Arduino控制器）\\03-源码例程\\例程05————FLASH的基本用法\\ZL_KPZAR\\z_loop.ino"
/****************************************************************************
	*	@笔者	：	W
	*	@日期	：	2019年12月28日
	*	@所属	：	杭州众灵科技
	*	@论坛	：	www.ZL-robot.com
	*	@功能	：	存放永久循环执行的函数
	*	@函数列表：
 ****************************************************************************/

#line 1 "\\\\tb-pc\\产品资料\\001-线上产品\\103-DIY电控系统\\002 开源控制器\\003-ZL-KPZAR（开源开拓者Arduino控制器）\\03-源码例程\\例程05————FLASH的基本用法\\ZL_KPZAR\\z_setup.ino"
/****************************************************************************
	*	@笔者	：	W
	*	@日期	：	2019年12月28日
	*	@所属	：	杭州众灵科技
	*	@论坛	：	www.ZL-robot.com
	*	@功能	：	存放初始化相关的函数
	*	@函数列表：
	*	1.	void setup_uart(void) -- 初始化串口
	*	2.	void setup_sensor(void) -- 初始化传感器
 ****************************************************************************/

/***********************************************
	函数名称：setup_beep() 
	功能介绍：初始化蜂鸣器BEEP
	函数参数：无
	返回值：	无
 ***********************************************/
void setup_beep(void) {
	beep_init();
	BEEP_L();							//蜂鸣器BEEP熄灭
}

/***********************************************
	函数名称:		setup_uart() 
	功能介绍:		初始化串口
	函数参数:		无
	返回值:			无
 ***********************************************/
void setup_uart(void) {
	uart_init(115200);
	uart_send_str((u8 *)"uart check ok!\r\n");
}

/***********************************************
	函数名称：setup_flash() 
	功能介绍：初始化flash
	函数参数：无
	返回值：	无
 ***********************************************/
void setup_flash(void) {
	while(!mem.begin(_W25Q64,SPI,SS))
		BEEP_H();
}

#line 1 "\\\\tb-pc\\产品资料\\001-线上产品\\103-DIY电控系统\\002 开源控制器\\003-ZL-KPZAR（开源开拓者Arduino控制器）\\03-源码例程\\例程05————FLASH的基本用法\\ZL_KPZAR\\z_uart.ino"
/****************************************************************************
	*	@笔者	：	W
	*	@日期	：	2019年12月28日
	*	@所属	：	杭州众灵科技
	*	@论坛	：	www.ZL-robot.com
	*	@功能	：	存放串口相关的函数
	*	@函数列表：
	*	1.	void uart_init(u32 baud) -- 初始化串口
	*	2.	void uart_send_byte(u8 dat) -- 串口发送字节
	*	3.	void uart_send_str(char *s) -- 串口发送字符串
	*	4.	void uart_send_int(int tmp) -- 串口发送数字
 ****************************************************************************/

/***********************************************
	函数名称:		uart_init() 
	功能介绍:		初始化串口
	函数参数:		baud 波特率
	返回值:			无
 ***********************************************/
void uart_init(u32 baud) {
	Serial.begin(baud);		//初始化波特率为baud
}

/***********************************************
	函数名称:		uart_send_byte() 
	功能介绍:		串口发送字节
	函数参数:		dat 发送的字节
	返回值:			无
 ***********************************************/
void uart_send_byte(u8 dat) {
	Serial.write(dat);
}

/***********************************************
	函数名称:		uart_send_str() 
	功能介绍:		串口发送字符串
	函数参数:		*s 发送的字符串
	返回值:			无
 ***********************************************/
void uart_send_str(char *s) {
	while (*s) {
		Serial.print(*s++);
	}
}

/***********************************************
	函数名称:		uart_send_int() 
	功能介绍:		串口发送数字
	函数参数:		tmp 发送的数字
	返回值:			无
 ***********************************************/
void uart_send_int(int tmp){
	Serial.print(tmp);
}

