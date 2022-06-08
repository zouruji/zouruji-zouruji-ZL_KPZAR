/****************************************************************************
	*	@功能	：	存放初始化相关的函数
	*	@函数列表：
	*	1.	void setup_uart(void) -- 初始化串口
	*	2.	void setup_sensor(void) -- 初始化传感器
 ****************************************************************************/

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
	函数名称:		setup_sensor() 
	功能介绍:		初始化传感器
	函数参数:		无
	返回值:			无
 ***********************************************/
void setup_sensor(void) {
	sensor_init();
}
