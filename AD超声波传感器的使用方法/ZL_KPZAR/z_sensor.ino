/****************************************************************************
	*	@功能	：	存放传感器相关的函数
	*	@函数列表：
	*	1.	void sensor_init(void) -- 初始化传感器
	*	2.	void sensor_read_ultrasonic(u8 range) -- 读取AD超声波传感器数据
 ****************************************************************************/

/*******传感器快捷指令表*******/
#define SSU_RANGE(x) digitalWrite(A5,x)
#define SSU_0 analogRead(A4)
#define SSU_1 analogRead(A4)*3

/***********************************************
	函数名称:		sensor_init() 
	功能介绍:		初始化传感器
	函数参数:		无
	返回值:			无
 ***********************************************/
void sensor_init(void) {
	pinMode(A5,OUTPUT);
	pinMode(A4,INPUT_PULLUP);
}

/***********************************************
	函数名称：sensor_read_ultrasonic() 
	功能介绍：读取AD超声波传感器数据
	函数参数：range 量程 1：3M 0：1M
	返回值：	无
 ***********************************************/
void sensor_read_ultrasonic(u8 range) {
	SSU_RANGE(range);
	delayMicroseconds(10);
	if(range == 0) {
		uart_send_str((u8 *)"\r\ndistance(AD_1.024M):");
		uart_send_int(SSU_0);
		uart_send_str((u8 *)"mm");
	}
	else if(range == 1) {
		uart_send_str((u8 *)"\r\ndistance(AD_3.072M):");
		uart_send_int(SSU_1);
		uart_send_str((u8 *)"mm");
	}
	else {
		uart_send_str((u8 *)"\r\nError!");
	}
}
