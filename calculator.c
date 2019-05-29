#include "dev.h"
#include "tutorial_lib.h"

extern key_sensor_t key_val[4];


void show_num(uint8_t id, int num)
{
	int s = 0;
	if (num < 0) s = 1;

	num = abs(num);
	int n1 = num / 1000;
	int n2 = num % 1000 / 100;
	int n3 = num % 100 / 10;
	int n4 = num % 10;

	num_ctrl_t n;
	n.pnt_4 = s;

	n.enable_1 = (n1 != 0);
	n.enable_2 = (n.enable_1 || n2 != 0);
	n.enable_3 = (n.enable_2 || n3 != 0);
	n.enable_4 = 1;

	n.num_1 = n1;
	n.num_2 = n2;
	n.num_3 = n3;
	n.num_4 = n4;
	num_ctrl_data(id, n);
}

int get_key(key_sensor_t data)
{
	if (data.key1 == 1) return 1;
	if (data.key2 == 1) return 2;
	if (data.key3 == 1) return 3;
	if (data.key4 == 1) return 4;
	if (data.key5 == 1) return 5;
	if (data.key6 == 1) return 6;
	if (data.key7 == 1) return 7;
	if (data.key8 == 1) return 8;
	if (data.key9 == 1) return 9;
	return 0;
}

void class_test_task(void const *argu)
{
	int is_pressed = 0;
	int value_1 = 0;
	int value_2 = 0;
	int op = 0;
	int ans = 0;
	int step = 0;	// 0 input value_1, 1 input value_2, 2 show answer.

	while (1)
	{
		int k1 = get_key(key_val[0]);
		int k2 = get_key(key_val[1]);

		if (is_pressed == 0 )
		{
			if (k1 > 0 || k2 == 7)
			{
				is_pressed = 1;
				if (op == 0)
					step = 0;
				else
					step = 1;

				if (step == 0)
					value_1 = value_1 * 10 + k1;
				else if (step == 1)
					value_2 = value_2 * 10 + k1;
			}
			else if (k2 >= 1 && k2 <= 4)
			{
				is_pressed = 1;
				op = k2;
			}
			else if (k2 == 5)
			{
				is_pressed = 1;
				step = 2;

				if (op == 1)
					ans = value_1 + value_2;
				else if (op == 2)
					ans = value_1 - value_2;
				else if (op == 3)
					ans = value_1 * value_2;
				else if (op == 3)
					if (value_2 == 0)
						ans = 0;
					else
						ans = value_1 / value_2;

				value_1 = 0;
				value_2 = 0;
				op = 0;
			}
		}

		if (k1 == 0 && k2 == 0)
			is_pressed = 0;

		if (step == 2)
			show_num(1, ans);
		else
		{
			if (step == 0)
				show_num(1, value_1);
			else if (step == 1)
				show_num(1, value_2);
		}
	}
}


