/*
 * FSM_automatic.c
 *
 *  Created on: Sep 26, 2024
 *      Author: ADMIN
 */

#include "FSM_automatic.h"
#include "time_set.h"
void automaticRun(){
	switch(status){
	case INIT:
		if(1){
			HAL_GPIO_WritePin(LED0_0_GPIO_Port , LED0_0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED0_1_GPIO_Port , LED0_1_Pin, GPIO_PIN_SET);


			HAL_GPIO_WritePin(LED1_0_GPIO_Port , LED1_0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED1_1_GPIO_Port , LED1_1_Pin, GPIO_PIN_RESET);
			status = AUTO_RED;
			button_flag[0] = 0;
			button_flag[1] = 0;
			button_flag[2] = 0;
			setTimer(1, timer_dura[1]);

			counter0 = redDura;
			counter1 = greenDura;
			countdownEnable = ENABLE;
	}
	break;
	case AUTO_RED:
		if(counter0 == yellowDura) {
			HAL_GPIO_WritePin(LED1_0_GPIO_Port , LED1_0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED1_1_GPIO_Port , LED1_1_Pin, GPIO_PIN_SET);

			HAL_GPIO_WritePin(LED0_0_GPIO_Port , LED0_0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED0_1_GPIO_Port , LED0_1_Pin, GPIO_PIN_SET);
			counter1 = yellowDura;
		}
		if(counter0 == 0) {
			HAL_GPIO_WritePin(LED0_0_GPIO_Port , LED0_0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED0_1_GPIO_Port , LED0_1_Pin, GPIO_PIN_RESET);

			HAL_GPIO_WritePin(LED1_0_GPIO_Port , LED1_0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED1_1_GPIO_Port , LED1_1_Pin, GPIO_PIN_SET);

			counter0 = greenDura;
			counter1 = redDura;
			status = AUTO_GREEN;
		}
		if(isButtonPressed(1) == 1){
			status = MAN_INIT;
			countdown_save[0] = counter0;
			countdown_save[1] = counter1;
			countdownEnable = DISABLE;//DISABLE COUTDOWN
		}
		break;
	case AUTO_GREEN:
		if(counter0 == 0) {
			HAL_GPIO_WritePin(LED0_0_GPIO_Port , LED0_0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(LED0_1_GPIO_Port , LED0_1_Pin, GPIO_PIN_SET);

			HAL_GPIO_WritePin(LED1_0_GPIO_Port , LED1_0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED1_1_GPIO_Port , LED1_1_Pin, GPIO_PIN_SET);
			counter0 = yellowDura;
			status = AUTO_AMBER;
		}
		if(isButtonPressed(1) == 1){
			status = MAN_INIT;
			countdown_save[0] = counter0;
			countdown_save[1] = counter1;
			countdownEnable = DISABLE;
		}
		break;
	case AUTO_AMBER:
		if(counter0 == 0) {
			HAL_GPIO_WritePin(LED0_0_GPIO_Port , LED0_0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED0_1_GPIO_Port , LED0_1_Pin, GPIO_PIN_SET);


			HAL_GPIO_WritePin(LED1_0_GPIO_Port , LED1_0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED1_1_GPIO_Port , LED1_1_Pin, GPIO_PIN_RESET);

			counter0 = redDura;
			counter1 = greenDura;
			status = AUTO_RED;

		}
		if(isButtonPressed(1) == 1){
			status = MAN_INIT;
			countdown_save[0] = counter0;
			countdown_save[1] = counter1;
			countdownEnable = DISABLE;
		}
		break;
	default:
		break;
	}
	if(timer_flag[1] == 1 && countdownEnable)
	{
		counter0 --;
		counter1 --;
		setTimer(1, timer_dura[1]);
	}
}
