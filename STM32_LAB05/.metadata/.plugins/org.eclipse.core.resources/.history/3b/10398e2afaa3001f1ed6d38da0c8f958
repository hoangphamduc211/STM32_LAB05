/*
 * displayLCD.c
 *
 *  Created on: Nov 16, 2024
 *      Author: LENOVO
 */
#include<displayLCD.h>

int buffer[4] = {0,0,0,0};
void automatic_display(){
//	lcd_clear();
	lcd_put_cur(0, 0);
	lcd_send_string("AUTOMATIC MODE");
	char str1[20];
	char str2[20];
	switch(buffer[2]){
	case 0:
		sprintf(str1,"RED: %d",buffer[0]);
		break;
	case 1:
		sprintf(str1,"GREEN: %d",buffer[0]);
		break;
	case 2:
		sprintf(str1,"AMBER: %d",buffer[0]);
		break;
	default:
		break;
	}
	switch(buffer[3]){
	case 0:
		sprintf(str2,"RED: %d",buffer[1]);
		break;
	case 1:
		sprintf(str2,"GREEN: %d",buffer[1]);
		break;
	case 2:
		sprintf(str2,"AMBER: %d",buffer[1]);
	}
	lcd_put_cur(1, 0);
	lcd_send_string(str1);
	lcd_put_cur(1, 8);
	lcd_send_string(str2);
}
void manual_display(){
//	lcd_clear();
	lcd_send_string("MANUAL MODE");
	char str1[20];
	char str2[20];
	switch(buffer[2]){
	case 0:
		sprintf(str1,"RED: %d",buffer[0]);
		break;
	case 1:
		sprintf(str1,"GREEN: %d",buffer[0]);
		break;
	case 2:
		sprintf(str1,"AMBER: %d",buffer[0]);
		break;
	default:
		break;
	}
	switch(buffer[2]){
	case 0:
		sprintf(str2,"MODE: %d",buffer[1]);
		break;
	case 1:
		sprintf(str2,"MODE: %d",buffer[1]);
		break;
	case 2:
		sprintf(str2,"MODE: %d",buffer[1]);
	}
	lcd_put_cur(1, 0);
	lcd_send_string(str1);
	lcd_put_cur(1, 8);
	lcd_send_string(str2);
}
