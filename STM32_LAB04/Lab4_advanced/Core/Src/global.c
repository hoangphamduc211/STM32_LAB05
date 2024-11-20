/*
 * global.c
 *
 *  Created on: Sep 26, 2024
 *      Author: ADMIN
 */
#include "global.h"
int status = 0;
int index7SEG = 0;
int redDura = 5, greenDura = 3, yellowDura = 2;
int countdownEnable = 1;
int counter0 = 0;
int counter1 = 0;
int countdown_save[NUM_COUNTDOWN];
struct SCH_task *mainSCH = NULL;

void display7SEG(int num){
	switch(num){
	case 0:
		HAL_GPIO_WritePin(SEG_A_GPIO_Port , SEG_A_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_B_GPIO_Port , SEG_B_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_C_GPIO_Port , SEG_C_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_D_GPIO_Port , SEG_D_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_E_GPIO_Port , SEG_E_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_F_GPIO_Port , SEG_F_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_G_GPIO_Port , SEG_G_Pin, GPIO_PIN_SET);
		break;
	case 1:
		HAL_GPIO_WritePin(SEG_A_GPIO_Port , SEG_A_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_B_GPIO_Port , SEG_B_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_C_GPIO_Port , SEG_C_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_D_GPIO_Port , SEG_D_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_E_GPIO_Port , SEG_E_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_F_GPIO_Port , SEG_F_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_G_GPIO_Port , SEG_G_Pin, GPIO_PIN_SET);
		break;
	case 2:
		HAL_GPIO_WritePin(SEG_A_GPIO_Port , SEG_A_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_B_GPIO_Port , SEG_B_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_C_GPIO_Port , SEG_C_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_D_GPIO_Port , SEG_D_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_E_GPIO_Port , SEG_E_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_F_GPIO_Port , SEG_F_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_G_GPIO_Port , SEG_G_Pin, GPIO_PIN_RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(SEG_A_GPIO_Port , SEG_A_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_B_GPIO_Port , SEG_B_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_C_GPIO_Port , SEG_C_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_D_GPIO_Port , SEG_D_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_E_GPIO_Port , SEG_E_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_F_GPIO_Port , SEG_F_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_G_GPIO_Port , SEG_G_Pin, GPIO_PIN_RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(SEG_A_GPIO_Port , SEG_A_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_B_GPIO_Port , SEG_B_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_C_GPIO_Port , SEG_C_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_D_GPIO_Port , SEG_D_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_E_GPIO_Port , SEG_E_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_F_GPIO_Port , SEG_F_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_G_GPIO_Port , SEG_G_Pin, GPIO_PIN_RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(SEG_A_GPIO_Port , SEG_A_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_B_GPIO_Port , SEG_B_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_C_GPIO_Port , SEG_C_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_D_GPIO_Port , SEG_D_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_E_GPIO_Port , SEG_E_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_F_GPIO_Port , SEG_F_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_G_GPIO_Port , SEG_G_Pin, GPIO_PIN_RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(SEG_A_GPIO_Port , SEG_A_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_B_GPIO_Port , SEG_B_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_C_GPIO_Port , SEG_C_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_D_GPIO_Port , SEG_D_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_E_GPIO_Port , SEG_E_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_F_GPIO_Port , SEG_F_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_G_GPIO_Port , SEG_G_Pin, GPIO_PIN_SET);
		break;
	case 6:
		HAL_GPIO_WritePin(SEG_A_GPIO_Port , SEG_A_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_B_GPIO_Port , SEG_B_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_C_GPIO_Port , SEG_C_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_D_GPIO_Port , SEG_D_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_E_GPIO_Port , SEG_E_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_F_GPIO_Port , SEG_F_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_G_GPIO_Port , SEG_G_Pin, GPIO_PIN_RESET);
		break;
	case 8:
		HAL_GPIO_WritePin(SEG_A_GPIO_Port , SEG_A_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_B_GPIO_Port , SEG_B_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_C_GPIO_Port , SEG_C_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_D_GPIO_Port , SEG_D_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_E_GPIO_Port , SEG_E_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_F_GPIO_Port , SEG_F_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_G_GPIO_Port , SEG_G_Pin, GPIO_PIN_RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(SEG_A_GPIO_Port , SEG_A_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_B_GPIO_Port , SEG_B_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_C_GPIO_Port , SEG_C_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_D_GPIO_Port , SEG_D_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_E_GPIO_Port , SEG_E_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_F_GPIO_Port , SEG_F_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(SEG_G_GPIO_Port , SEG_G_Pin, GPIO_PIN_RESET);
		break;
	default:
		HAL_GPIO_WritePin(SEG_A_GPIO_Port , SEG_A_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_B_GPIO_Port , SEG_B_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_C_GPIO_Port , SEG_C_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_D_GPIO_Port , SEG_D_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_E_GPIO_Port , SEG_E_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_F_GPIO_Port , SEG_F_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(SEG_G_GPIO_Port , SEG_G_Pin, GPIO_PIN_RESET);
		break;

	}
}
void displayNum(int mode)
{
	switch(index7SEG)
	{
	case 0:
		display7SEG(counter0 / 10);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port , EN1_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port , EN2_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port , EN3_Pin , GPIO_PIN_SET);
		break;
	case 1:
		display7SEG(counter0 % 10);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN0_GPIO_Port , EN0_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port , EN2_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port , EN3_Pin , GPIO_PIN_SET);
		break;
	case 2:
		display7SEG(counter1 / 10);
		HAL_GPIO_WritePin(EN1_GPIO_Port , EN1_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN0_GPIO_Port , EN0_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port , EN2_Pin , GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN3_GPIO_Port , EN3_Pin , GPIO_PIN_SET);
		break;
	case 3:
		display7SEG(counter1 % 10);
		HAL_GPIO_WritePin(EN1_GPIO_Port , EN1_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN0_GPIO_Port , EN0_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port , EN2_Pin , GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port , EN3_Pin , GPIO_PIN_RESET);
		break;
	default:
		break;
	}
	index7SEG ++;
	if(index7SEG >= NUM_ENABLE) index7SEG = 0;
}
void task1(){
	if(timer_flag[1] == 1)
	{
		HAL_GPIO_TogglePin(LED_RED1_GPIO_Port, LED_RED1_Pin);
		setTimer(1, timer_dura[1]);
	}
}
void initial(){
	setTimer(0, timer_dura[0]);
	setTimer(1, timer_dura[1]);
	setTimer(2, timer_dura[2]);
	setTimer(3, timer_dura[3]);
	status = INIT;
}
