#include "dev.h"
#include "tutorial_lib.h"

int L[] = {0, 262, 294, 330, 349, 392, 440, 494};
int M[] = {0, 523, 587, 659, 698, 784, 880, 988};
int H[] = {0, 1046, 1175, 1318, 1397, 1568, 1760, 1976};
double P = 60.0f / 120 * 1000;

buzzer_ctrl_t buzzer;

void tone(int freq, double delay)
{
	if (freq == 0) {
		buzzer.enable = 0;
	} else {
		buzzer.enable = 1;
		buzzer.freq = freq;
	}
	buzzer_ctrl_data(1, buzzer);
	task_delay(delay * P);
}

void class_test_task(void const *argu)
{
	while(1)
	{
		task_delay(3000);

		tone(L[5], 0.5);
		tone(M[0], 0.5);
		tone(M[3], 0.5);
		tone(M[0], 0.5);
		tone(M[1], 0.5);
		tone(M[0], 0.5);
		tone(M[2], 0.5);
		tone(M[1], 0.5); tone(M[0], 0.1);

		tone(M[1], 0.5);
		tone(M[0], 0.5);
		tone(L[7], 0.5);
		tone(M[0], 0.5);
		tone(L[7], 0.5);
		tone(M[0], 0.5);
		tone(L[2], 0.5);
		tone(L[3], 0.5);

		tone(L[4], 0.5);
		tone(M[0], 0.5);
		tone(M[2], 0.5);
		tone(M[0], 0.5);
		tone(L[7], 0.5);
		tone(M[0], 0.5);
		tone(M[1], 0.5);
		tone(L[7], 0.5);

		tone(L[6], 0.5);
		tone(M[0], 0.5);
		tone(L[5], 0.5);
		tone(M[0], 0.5);
		tone(L[5], 0.5);
		tone(M[0], 0.5);
		tone(L[3], 0.5);
		tone(L[4], 0.5);

		tone(L[5], 0.5);
		tone(M[0], 0.5);
		tone(M[1], 0.5);
		tone(M[2], 0.5);
		tone(M[3], 0.5);
		tone(M[0], 0.5);
		tone(M[2], 0.5);
		tone(M[1], 0.5);

		tone(L[6], 0.5);
		tone(M[0], 0.5);
		tone(M[2], 0.5);
		tone(M[3], 0.5);
		tone(M[4], 0.5);
		tone(M[0], 0.5);
		tone(M[3], 0.5);
		tone(M[2], 0.5);

		tone(L[5], 0.5);
		tone(M[0], 0.5);
		tone(M[4], 0.5);
		tone(M[0], 0.5);
		tone(M[3], 0.5);
		tone(M[0], 0.5);
		tone(M[2], 0.5);
		tone(M[0], 0.5);

		tone(M[1], 0.5);
		tone(M[0], 0.5);
		tone(M[0], 0.5);
		tone(M[0], 0.5);
		tone(M[0], 0.5);
		tone(M[0], 0.5);
		tone(M[0], 0.5);
		tone(M[0], 0.5);

		tone(M[1], 0.5);
		tone(M[0], 0.5);
		tone(M[0], 0.5);
		tone(M[1], 0.5);
		tone(M[3], 0.5);
		tone(M[0], 0.5);
		tone(M[1], 0.5);
		tone(M[0], 0.5);

		tone(M[2], 0.5);
		tone(M[0], 0.5);
		tone(M[0], 0.5);
		tone(M[2], 0.5); tone(M[0], 0.1);
		tone(M[2], 0.5);
		tone(M[0], 0.5);
		tone(M[0], 0.5);
		tone(M[0], 0.5);

		tone(M[2], 0.5);
		tone(M[0], 0.5);
		tone(M[0], 0.5);
		tone(M[2], 0.5);
		tone(M[4], 0.5);
		tone(M[0], 0.5);
		tone(M[2], 0.5);
		tone(M[0], 0.5);

		tone(M[3], 0.5);
		tone(M[0], 0.5);
		tone(M[0], 0.5);
		tone(M[3], 0.5); tone(M[0], 0.1);
		tone(M[3], 0.5);
		tone(M[0], 0.5);
		tone(M[0], 0.5);
		tone(M[0], 0.5);

		tone(M[3], 0.5);
		tone(M[0], 0.5);
		tone(M[0], 0.5);
		tone(M[3], 0.5);
		tone(M[5], 0.5);
		tone(M[0], 0.5);
		tone(M[3], 0.5);
		tone(M[0], 0.5);

		tone(M[4], 0.5);
		tone(M[0], 0.5);
		tone(M[0], 0.5);
		tone(M[4], 0.5); tone(M[0], 0.1);
		tone(M[4], 0.5);
		tone(M[0], 0.5);
		tone(M[3], 0.5);
		tone(M[2], 0.5);

		tone(L[5], 0.5);
		tone(M[0], 0.5);
		tone(M[0], 0.5);
		tone(M[0], 0.5);
		tone(L[7], 0.5);
		tone(M[0], 0.5);
		tone(M[0], 0.5);
		tone(M[0], 0.5);

		tone(M[1], 0.5);
		tone(M[0], 0.5);
		tone(M[0], 0.5);
		tone(M[0], 0.5);
		tone(M[0], 0.5);
		tone(M[0], 0.5);
		tone(M[0], 0.5);
		tone(M[0], 0.5);
	}
}
