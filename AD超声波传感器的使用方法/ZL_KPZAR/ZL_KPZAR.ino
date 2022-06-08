/****************************************************************************
	*	@功能	：	ZL-KPZ控制板（AR版）模块例程4————串口的基本用法
	*	@函数列表：
	*	1.	void setup(void) -- 初始化函数
	*	2.	void loop(void) -- 主循环函数
 ****************************************************************************/

/*******全局变量宏定义*******/
#define UART_RECEIVE_BUF_SIZE 100

/*******全局变量定义*******/
u8 i=0;
u8 uart_receive_buf[UART_RECEIVE_BUF_SIZE]={0}, uart_receive_buf_index, uart_get_ok;

void setup(void) {																																																																																																																															//ZL
	setup_uart();			//初始化串口
	setup_sensor();			//初始化传感器相关设置
}
void loop(void) {
	loop_sensor();			//循环读取传感器的值
}
