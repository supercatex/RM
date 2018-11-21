#include "dev.h"
#include "tutorial_lib.h"

extern sonic_sensor_t sonic_val[4];
led_ctrl_t led;

void set_led(int n, int v)
{
	switch(n)
	{
	case 1:
		led.led1 = v;
		break;
	case 2:
		led.led2 = v;
		break;
	case 3:
		led.led3 = v;
		break;
	case 4:
		led.led4 = v;
		break;
	case 5:
		led.led5 = v;
		break;
	case 6:
		led.led6 = v;
		break;
	case 7:
		led.led7 = v;
		break;
	case 8:
		led.led8 = v;
		break;
	}
}

void display_led(int n)
{
	for (int i = 1; i <= 8; i++) {
		if (i <= n) {
			set_led(i, 1);
		} else {
			set_led(i, 0);
		}
	}
}

void class_test_task(void const *argu)
{

	while(1)
	{
		int max = 200;
		int min = 60;
		sonic_mesg_request(1);
		int distance = sonic_val[0].distance;
		if (distance == 0) {
			display_led(8);
		} else {
			display_led((distance - min) * 8 / (max - min));
		}
		led_ctrl_data(1, led);
		task_delay(100);
	}
}
