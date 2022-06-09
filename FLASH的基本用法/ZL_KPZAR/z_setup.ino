/****************************************************************************
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
