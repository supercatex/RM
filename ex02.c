#include "dev.h"
#include "tutorial_lib.h"

void class_test_task(void const *argu)
{
	led_ctrl_t my_led;			//先定義一個LED叫做 my_led
	
	while(1)				//無限循環大括號內的指令
	{
		my_led.led1 = 1;		//設置 my_led 第一盞燈亮起
		led_ctrl_data(1, my_led);	//執行 my_led 的設定
		task_delay(1000);		//停一秒
		
		my_led.led1 = 0;		//設置 my_led 第一盞燈熄滅
		led_ctrl_data(1, my_led);	//執行 my_led 的設定
		task_delay(1000);
		
		my_led.led2 = 1;		//設置 my_led 第二盞燈亮起
		led_ctrl_data(1, my_led);	//執行 my_led 的設定
		task_delay(1000);		//停一秒
		
		my_led.led2 = 0;		//設置 my_led 第二盞燈熄滅
		led_ctrl_data(1, my_led);	//執行 my_led 的設定
		task_delay(1000);
		
		my_led.led3 = 1;		//設置 my_led 第三盞燈亮起
		led_ctrl_data(1, my_led);	//執行 my_led 的設定
		task_delay(1000);		//停一秒
		
		my_led.led3 = 0;		//設置 my_led 第三盞燈熄滅
		led_ctrl_data(1, my_led);	//執行 my_led 的設定
		task_delay(1000);
		
		my_led.led4 = 1;		//設置 my_led 第四盞燈亮起
		led_ctrl_data(1, my_led);	//執行 my_led 的設定
		task_delay(1000);		//停一秒
		
		my_led.led4 = 0;		//設置 my_led 第四盞燈熄滅
		led_ctrl_data(1, my_led);	//執行 my_led 的設定
		task_delay(1000);
		
		my_led.led5 = 1;		//設置 my_led 第五盞燈亮起
		led_ctrl_data(1, my_led);	//執行 my_led 的設定
		task_delay(1000);		//停一秒
		
		my_led.led5 = 0;		//設置 my_led 第五盞燈熄滅
		led_ctrl_data(1, my_led);	//執行 my_led 的設定
		task_delay(1000);
		
		my_led.led6 = 1;		//設置 my_led 第六盞燈亮起
		led_ctrl_data(1, my_led);	//執行 my_led 的設定
		task_delay(1000);			//停一秒
		
		my_led.led6 = 0;		//設置 my_led 第六盞燈熄滅
		led_ctrl_data(1, my_led);	//執行 my_led 的設定
		task_delay(1000);
		
		my_led.led7 = 1;		//設置 my_led 第七盞燈亮起
		led_ctrl_data(1, my_led);	//執行 my_led 的設定
		task_delay(1000);		//停一秒
		
		my_led.led7 = 0;		//設置 my_led 第七盞燈熄滅
		led_ctrl_data(1, my_led);	//執行 my_led 的設定
		task_delay(1000);
		
		my_led.led8 = 1;		//設置 my_led 第八盞燈亮起
		led_ctrl_data(1, my_led);	//執行 my_led 的設定
		task_delay(1000);		//停一秒
		
		my_led.led8 = 0;		//設置 my_led 第八盞燈熄滅
		led_ctrl_data(1, my_led);	//執行 my_led 的設定
		task_delay(1000);
	}
}
