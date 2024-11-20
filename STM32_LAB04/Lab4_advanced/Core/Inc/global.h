/*
 * global.h
 *
 *  Created on: Sep 26, 2024
 *      Author: ADMIN
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_
#include "main.h"
#include "time_set.h"
#include "button.h"


//DEFINE FOR LED
#define INIT 1
#define AUTO_RED 2
#define AUTO_AMBER 3
#define AUTO_GREEN 4
#define MAN_INIT 11
#define MAN_RED 12
#define MAN_GREEN 13
#define MAN_AMBER 14
#define NUM_COUNTDOWN 2
#define ENABLE 1
#define DISABLE 0


extern int index7SEG;
extern int status;
extern int counter0, counter1;//COUNTDOWN FOR TRAFFIC LIGHT
extern int redDura, greenDura, yellowDura;
extern int countdownEnable;
extern int countdown_save[NUM_COUNTDOWN];
extern struct SCH_task* mainSCH;

void initial();
void display7SEG(int num);
void displayNum();
void task1();
void task2();
void task3();
void task4();
void taskButton1();
#endif /* INC_GLOBAL_H_ */
