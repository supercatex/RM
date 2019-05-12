#include "dev.h"
#include "tutorial_lib.h"

led_ctrl_t my_led;

void set_led(int n, int v)  // n 是第幾顆 LED, v 是 0(熄) 或 1(亮)
{
	switch(n)
	{
	case 1:
		my_led.led1 = v;
		break;
	case 2:
		my_led.led2 = v;
		break;
	case 3:
		my_led.led3 = v;
		break;
	case 4:
		my_led.led4 = v;
		break;
	case 5:
		my_led.led5 = v;
		break;
	case 6:
		my_led.led6 = v;
		break;
	case 7:
		my_led.led7 = v;
		break;
	case 8:
		my_led.led8 = v;
		break;
	}
}

void class_test_task(void const *argu)
{
	while(1)
	{
		for (int i = 1; i <= 8; i++)    // 由第 1 顆到第 8 顆 LED
		{
			set_led(i, 1);				// 第 i 顆 LED 亮
            led_ctrl_data(1, my_led);   // 執行
			task_delay(1000);			// 亮 1 秒
            
			set_led(i, 0);				// 第 i 顆 LED 熄
            led_ctrl_data(1, led);      // 執行
			task_delay(1000);			// 熄 1 秒
		}
	}
}
