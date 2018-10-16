/****************************************************************************
 *  Copyright (C) 2018 RoboMaster.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of鑱�
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.鑱� See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/

/**
  *********************** (C) COPYRIGHT 2018 DJI **********************
  * @update
  * @history
  * Version     Date           Author           Modification
  * V1.0.0      June-26-2018   ric.luo
  * @verbatim
  *********************** (C) COPYRIGHT 2018 DJI **********************
  */

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
