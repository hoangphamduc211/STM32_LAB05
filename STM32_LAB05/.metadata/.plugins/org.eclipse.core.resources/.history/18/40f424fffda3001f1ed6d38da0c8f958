/*
 * FSM_manual.c
 *
 *  Created on: Sep 26, 2024
 *      Author: ADMIN
 */
#include "FSM_manual.h"
void init_manual(){

}

void manual_run(){
	switch(status){
	case MAN_INIT:
		HAL_GPIO_WritePin(LED1_0_GPIO_Port , LED1_0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED1_1_GPIO_Port , LED1_1_Pin, GPIO_PIN_RESET);

		HAL_GPIO_WritePin(LED0_0_GPIO_Port , LED0_0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED0_1_GPIO_Port , LED0_1_Pin, GPIO_PIN_RESET);
		status = MAN_RED;
		counter0 = redDura;
		counter1 = MAN_RED % 10;
		setTimer(2, timer_dura[2]);
		break;
	case MAN_RED:
		if(isButtonPressed(1))
		{
			status = MAN_GREEN;
			counter0 = greenDura;
			counter1 = MAN_GREEN % 10;
			setTimer(2, timer_dura[2]);
		}
		if(isButtonPressed(2))
		{
			counter0 ++;
			setTimer(2, timer_dura[2]);
		}
		else if(isButtonHold(2))
		{
			if(timer_flag[3] == 1){
				counter0 ++;
				setTimer(3, timer_dura[3]);
			}
		}
		if(isButtonPressed(3)){
			//ENABLE COUTDOWN FOR AUTO_TRAFFIC_LIGHT
			greenDura += counter0 - redDura;
			redDura = counter0;
			HAL_GPIO_WritePin(LED0_0_GPIO_Port, LED0_0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED0_1_GPIO_Port, LED0_1_Pin, GPIO_PIN_SET);
			setTimer(2,timer_dura[4]);
		}
		if(timer_flag[2] == 1){
			HAL_GPIO_TogglePin(LED0_0_GPIO_Port, LED0_0_Pin);
			HAL_GPIO_TogglePin(LED0_1_GPIO_Port, LED0_1_Pin);
			setTimer(2, timer_dura[2]);
		}

		break;
	case MAN_AMBER:
		HAL_GPIO_WritePin(LED0_0_GPIO_Port, LED0_0_Pin, GPIO_PIN_RESET);
		if(isButtonPressed(1)){
			status = INIT;
		}
		if(isButtonPressed(2))
		{
			counter0 ++;
			setTimer(2, timer_dura[2]);
		}
		else if(isButtonHold(2))
		{
			if(timer_flag[3] == 1){
				counter0 ++;
				setTimer(3, timer_dura[3]);
			}
		}
		if(isButtonPressed(3)){
			redDura += counter0 - yellowDura;
			yellowDura = counter0;
			HAL_GPIO_WritePin(LED0_1_GPIO_Port, LED0_1_Pin, GPIO_PIN_SET);
			setTimer(2,timer_dura[4]);
		}
		if(timer_flag[2] == 1){
			HAL_GPIO_TogglePin(LED0_1_GPIO_Port, LED0_1_Pin);
			setTimer(2, timer_dura[2]);
		}
		break;
	case MAN_GREEN:
		HAL_GPIO_WritePin(LED0_1_GPIO_Port, LED0_1_Pin, GPIO_PIN_RESET);

		if(isButtonPressed(1)){
			status = MAN_AMBER;
			counter0 = yellowDura;
			counter1 = MAN_AMBER % 10;
			setTimer(2, timer_dura[2]);
		}
		if(isButtonPressed(2))
		{
			counter0 ++;
			setTimer(2, timer_dura[2]);
		}
		else if(isButtonHold(2))
		{
			if(timer_flag[3] == 1){
				counter0 ++;
				setTimer(3, timer_dura[3]);
			}
		}
		if(isButtonPressed(3)){
			redDura += counter0 - greenDura;
			greenDura = counter0;
			HAL_GPIO_WritePin(LED0_0_GPIO_Port, LED0_0_Pin, GPIO_PIN_SET);
			setTimer(2,timer_dura[4]);
		}
		if(timer_flag[2] == 1){
			HAL_GPIO_TogglePin(LED0_0_GPIO_Port, LED0_0_Pin);
			setTimer(2, timer_dura[2]);
		}
		break;
	default:
		break;
	}

}
