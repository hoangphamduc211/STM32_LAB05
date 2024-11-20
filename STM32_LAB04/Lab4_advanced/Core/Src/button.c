/*
 * button.c
 *
 *  Created on: Oct 4, 2024
 *      Author: ADMIN
 */

#include "button.h"

static GPIO_PinState buttonBuffer[BUTTON_NUM];
static GPIO_PinState buttonBounce1[BUTTON_NUM];
static GPIO_PinState buttonBounce2[BUTTON_NUM];
static GPIO_PinState buttonBounce3[BUTTON_NUM];
int button_flag[BUTTON_NUM];
int button_hold[BUTTON_NUM];
int keyPressCounter[BUTTON_NUM];
void pressProcess(int i)
{
	button_flag[i] = 1;
	button_hold[i] = 0;
	return;
}
void holdProcess(int i)
{
	button_flag[i] = 0;
	button_hold[i] = 1;
	return;
}
void normalProcess(int i)
{
	button_flag[i] = 0;
	button_hold[i] = 0;
	return;
}
 void buttonReading(){
	 for(int i = 0; i < BUTTON_NUM; i ++ ){
		 buttonBounce1[i] = buttonBounce2[i];
		 buttonBounce2[i] = buttonBuffer[i];
		 switch(i)
		 {
		 case 0:
			 buttonBuffer[i] = HAL_GPIO_ReadPin(button1_GPIO_Port, button1_Pin);
			 if((buttonBounce1[i] == buttonBounce2[i]) && (buttonBounce2[i] == buttonBuffer[i])){
			 			 if(buttonBounce3[i] != buttonBuffer[i]){
			 				 buttonBounce3[i] = buttonBuffer[i];
			 				 if(buttonBuffer[i] == PRESSED_STATE){
			 					 pressProcess(i);
			 				 }
			 				 else if(buttonBuffer[i] == NORMAL_STATE)
			 				 {
			 					 normalProcess(i);
			 				 }
			 				 keyPressCounter[i] = AUTO_DURATION;
			 			 }
			 			 else{
			 				 keyPressCounter[i] --;
			 				 if(keyPressCounter[i] <= 0){
			 					 if(buttonBuffer[i] == PRESSED_STATE){
			 						 pressProcess(i);
			 					 }
			 					 keyPressCounter[i] = AUTO_DURATION;
			 					 //TODO
			 				 }
			 			 }
			 		 }
			 break;
		 case 1:
			 buttonBuffer[i] = HAL_GPIO_ReadPin(button2_GPIO_Port, button2_Pin);
			 if((buttonBounce1[i] == buttonBounce2[i]) && (buttonBounce2[i] == buttonBuffer[i])){
			 			 if(buttonBounce3[i] != buttonBuffer[i]){
			 				 buttonBounce3[i] = buttonBuffer[i];
			 				 if(buttonBuffer[i] == PRESSED_STATE){
			 					 pressProcess(i);
			 				 }
			 				 else if(buttonBuffer[i] == NORMAL_STATE)
							 {
								 normalProcess(i);
							 }
							 keyPressCounter[i] = AUTO_DURATION;

			 			 }
			 			 else{
			 				 keyPressCounter[i] --;
			 				 if(keyPressCounter[i] <= 0){
			 					 if(buttonBuffer[i] == PRESSED_STATE){
			 						 holdProcess(i);
			 					 }

			 					 //TODO
			 				 }
			 			 }
			 		 }
			 break;
		 case 2:
			 buttonBuffer[i] = HAL_GPIO_ReadPin(button3_GPIO_Port, button3_Pin);
			 if((buttonBounce1[i] == buttonBounce2[i]) && (buttonBounce2[i] == buttonBuffer[i])){
			 			 if(buttonBounce3[i] != buttonBuffer[i]){
			 				 buttonBounce3[i] = buttonBuffer[i];
			 				 if(buttonBuffer[i] == PRESSED_STATE){
			 					 pressProcess(i);
			 				 }
			 				 else if(buttonBuffer[i] == NORMAL_STATE)
							 {
								 normalProcess(i);
							 }
							 keyPressCounter[i] = AUTO_DURATION;

			 			 }
			 			 else{
			 				 keyPressCounter[i] --;
			 				 if(keyPressCounter[i] <= 0){
			 					 if(buttonBuffer[i] == PRESSED_STATE){
			 						 pressProcess(i);
			 					 }
			 					 keyPressCounter[i] = AUTO_DURATION;
			 					 //TODO
			 				 }
			 			 }
			 		 }
			 break;
		 default:
		 	 break;
		 }
	 }
 }
//BUTTON INDEX COUNT FROM 1
 int isButtonPressed(int index){
	 if(button_flag[index - 1] == 1){
		 button_flag[index - 1] = 0;
		 return 1;
	 }
	 return 0;
 }
 int isButtonHold(int index){
	 if(button_hold[index - 1] == 1){
		 button_hold[index - 1] = 0;
		 return 1;
	 }
	 return 0;
 }
