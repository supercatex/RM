#include "dev.h"
#include "tutorial_lib.h"

// 獲取按鈕模塊的按鍵狀態
extern key_sensor_t key_val[4];

// 顯示整數在數碼管模塊上 ( 參數1: 硬件ID號, 參數2: 整數 )
void show_num(uint8_t id, int num)
{
	int s = 0;				// 正負號：預設為 0.，即正數。
	if (num < 0) s = 1;     		// 如果數字為負數，設為 1.

	num = abs(num);         		// 絶對值數字
	int n1 = num / 1000;			// 千位數
	int n2 = num % 1000 / 100;		// 百位數
	int n3 = num % 100 / 10;		// 十位數
	int n4 = num % 10;			// 個位數

	num_ctrl_t n;
	n.pnt_4 = s;				// 四號小點亮代表負數，不亮代表正數。

	n.enable_1 = (n1 != 0);		        // 千位數不為零顯示千位
	n.enable_2 = (n.enable_1 || n2 != 0);	// 千位數已亮或百位數不為零顯示百位
	n.enable_3 = (n.enable_2 || n3 != 0);   // 百位數已亮或十位數不為零顯示十位
	n.enable_4 = 1;                         // 顯示個位

	n.num_1 = n1;                           // 設置千位數
	n.num_2 = n2;				// 設置百位數
	n.num_3 = n3;				// 設置十位數
	n.num_4 = n4;				// 設置個位數
	num_ctrl_data(id, n);
}

// 獲取按下的按鍵數字 ( 參數1: 按鈕數據 )
int get_key(key_sensor_t data)
{
	if (data.key1 == 1) return 1;		// 如果 Key 1 按下，則返回 1.
	if (data.key2 == 1) return 2;		// 如果 Key 2 按下，則返回 2.
	if (data.key3 == 1) return 3;		// 如果 Key 3 按下，則返回 3.
	if (data.key4 == 1) return 4;		// 如果 Key 4 按下，則返回 4.
	if (data.key5 == 1) return 5;		// 如果 Key 5 按下，則返回 5.
	if (data.key6 == 1) return 6;		// 如果 Key 6 按下，則返回 6.
	if (data.key7 == 1) return 7;		// 如果 Key 7 按下，則返回 7.
	if (data.key8 == 1) return 8;		// 如果 Key 8 按下，則返回 8.
	if (data.key9 == 1) return 9;		// 如果 Key 9 按下，則返回 9.
	return 0;				// 如果都不是，則返回 0.
}

// 主程序
void class_test_task(void const *argu)
{
	int is_pressed = 0;	// 按下的狀態 (0: 可按下, 1: 按下未放開)
	int value_1 = 0;	// 第一個數
	int value_2 = 0;	// 第二個數
	int op = 0;		// 運算符 ( +: 1, -: 2, *: 3, /: 4 )
	int ans = 0;		// 結果
	int step = 0;		// 0 代表正在輸入第一個數, 1 代表正在輸入第二個數, 2 代表顯示結果.

	while (1)
	{
		int k1 = get_key(key_val[0]);				// 第一個按鍵模塊按下的鍵
		int k2 = get_key(key_val[1]);				// 第二個按鍵模塊按下的鍵

		if (is_pressed == 0)					// 如果是可按下狀態
		{
			if (k1 > 0 || k2 == 7)				// 如果按下的是數字鍵 0 ~ 9. (第二個鍵盤的7號代表0)
			{
				is_pressed = 1;				// 變更為按下未放開狀態
				if (op == 0)				// 如果未有運算符
					step = 0;			// 正在輸入第一個數
				else					// 如果已有運算符
					step = 1;		        // 正在輸入第二個數

				if (step == 0)
					value_1 = value_1 * 10 + k1;	// 把原數放大10倍再加上剛剛按的數字
				else if (step == 1)
					value_2 = value_2 * 10 + k1;
			}
			else if (k2 >= 1 && k2 <= 4)			// 如果是按下運算符 (1: +, 2: -, 3: *, 4: /)
			{
				is_pressed = 1;				// 變更為按下未放開狀態
				op = k2;				// 設置運算符

				if (step == 2)				// 如果已顯示結果，再按運算符
					value_1 = ans;			// 把答案設為第一個數
			}
			else if (k2 == 5)				// 如果按下等於 (5: =)
			{
				is_pressed = 1;				// 變更為按下未放開狀態
				step = 2;				// 變更為顯示結果狀態

				if (op == 1)			        // 運算符 +
					ans = value_1 + value_2;
				else if (op == 2)			// 運算符 -
					ans = value_1 - value_2;
				else if (op == 3)			// 運算符 *
					ans = value_1 * value_2;
				else if (op == 4)			// 運算符 /
				{
					if (value_2 == 0)		// 如果除數為0, 則結果直接為0.
						ans = 0;
					else			        // 不為0才計算結果
						ans = value_1 / value_2;
				}

				value_1 = 0;				// 計算完重置
				value_2 = 0;
				op = 0;
			}
		}

		// 顯示
		if (k1 == 0 && k2 == 0)				        // 如果兩個鍵盤都沒有按下
			is_pressed = 0;					// 變更為可按下狀態
		
		if (step == 2)						// 如果是顯示結果狀態
			show_num(1, ans);				// 顯示結果
		else							// 否則
		{
			if (step == 0)					// 顯示第一個數字
				show_num(1, value_1);
			else if (step == 1)				// 顯示第二個數字
				show_num(1, value_2);
		}
	}
}
