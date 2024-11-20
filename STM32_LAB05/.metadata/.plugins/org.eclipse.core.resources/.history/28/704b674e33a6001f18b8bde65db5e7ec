/*
 * button.h
 *
 *  Created on: Oct 4, 2024
 *      Author: ADMIN
 */
#include "main.h"
#include "global.h"
#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

//DEFINE FOR BUTTON
#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET
#define AUTO_DURATION 200
#define BUTTON_NUM 3

void buttonReading();
extern int button_flag[BUTTON_NUM];
extern int button_hold[BUTTON_NUM];
void pressProcess(int i);
void holdProcess(int i);
void normalProcess();
int isButtonPressed(int index);
int isButtonHold(int index);
#endif /* INC_BUTTON_H_ */
