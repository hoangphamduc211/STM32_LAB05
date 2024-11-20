/*
 * scheduler.h
 *
 *  Created on: Oct 11, 2024
 *      Author: ADMIN
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_
#include "global.h"
#include "main.h"
#include "stdint.h"

typedef struct Node
{
    void (*pTask)(void);
    int delay;
    int period;
    int ID;
    struct Node *next;
} Node;

typedef struct SCH_task
{
    int size;
    int time_skip;
    Node *head;
    Node *tail;
} SCH_task;

Node *createNode(void(*pFunction), int delay, int period, int ID, Node *next);
Node *createDefaultNode();
SCH_task *createDefaultSCH();
void SCH_init();
void SCH_addTask(void(*pFunction), int DELAY, int PERIOD, int ID);
void SCH_deleteTask(int ID);
void SCH_updateTask();
void SCH_dispatchTask();
void SCH_deleteHead();
#endif /* INC_SCHEDULER_H_ */
