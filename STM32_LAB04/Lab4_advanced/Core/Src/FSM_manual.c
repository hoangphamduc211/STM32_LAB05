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
		HAL_GPIO_WritePin(LED_RED2_GPIO_Port , LED_RED2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port , LED_YELLOW2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port , LED_GREEN2_Pin, GPIO_PIN_RESET);
		status = MAN_RED;
		counter0 = redDura;
		counter1 = MAN_RED % 10;
		setTimer(2, timer_dura[2]);
		break;
	case MAN_RED:
		HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_RESET);
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
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_SET);
			setTimer(2,timer_dura[4]);
		}
		if(timer_flag[2] == 1){
			HAL_GPIO_TogglePin(LED_RED1_GPIO_Port, LED_RED1_Pin);
			setTimer(2, timer_dura[2]);
		}

		break;
	case MAN_AMBER:
		HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_RESET);
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
			HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, GPIO_PIN_SET);
			setTimer(2,timer_dura[4]);
		}
		if(timer_flag[2] == 1){
			HAL_GPIO_TogglePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin);
			setTimer(2, timer_dura[2]);
		}
		break;
	case MAN_GREEN:
		HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, GPIO_PIN_RESET);

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
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_SET);
			setTimer(2,timer_dura[4]);
		}
		if(timer_flag[2] == 1){
			HAL_GPIO_TogglePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin);
			setTimer(2, timer_dura[2]);
		}
		break;
	default:
		break;
	}

}
