/*
 * time_set.c
 *
 *  Created on: Sep 14, 2024
 *      Author: ADMIN
 */
#include "time_set.h"


int timer_counter[NUM_TIMER];
int timer_flag[NUM_TIMER];
int timer_dura[NUM_TIMER] = {50, 1000, 250, 250, INT_MAX};

void setTimer(int index, int dura){
	timer_flag[index] = 0;
	timer_counter[index] = dura / 10;
}
void runTimer(){
	for(int i = 0; i < NUM_TIMER; i++){
		if(timer_counter[i] <= 0){
			timer_flag[i] = 1;
		}
		else{
			timer_counter[i] --;
		}
	}
}

