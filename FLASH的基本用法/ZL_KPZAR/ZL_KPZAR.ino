/****************************************************************************
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
