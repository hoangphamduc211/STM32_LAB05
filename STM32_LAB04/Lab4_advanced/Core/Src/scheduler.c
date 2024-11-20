/*
 * scheduler.c
 *
 *  Created on: Oct 11, 2024
 *      Author: ADMIN
 */

#include "scheduler.h"
Node *createNode(void(*pFunction), int delay, int period, int ID, Node *next)
{
    Node *newNode = (Node *)malloc(sizeof(Node)); // Cấp phát bộ nhớ cho Node
    if (newNode != NULL)
    {
    	newNode->pTask = pFunction;
        newNode->delay = delay;
        newNode->period = period;
        newNode->ID = ID;
        newNode->next = next;
    }
    return newNode;
}

// Hàm tạo một Node với giá trị mặc định
Node *createDefaultNode()
{
    return createNode(NULL, 0, 0, 0, NULL); // Node mặc định với các giá trị 0 và con trỏ NULL
}

SCH_task *createDefaultSCH()
{
    SCH_task *SCH = (SCH_task *)malloc(sizeof(SCH_task));
    SCH->size = 0;
    SCH->time_skip = 0;
    SCH->head = SCH->tail = NULL;
    return SCH;
}
void SCH_init()
{
	mainSCH = (SCH_task *)malloc(sizeof(SCH_task));
	mainSCH->size = 0;
	mainSCH->time_skip = 0;
	mainSCH->head = mainSCH->tail = NULL;
}
void SCH_deleteHead()
{
    Node *current = mainSCH->head;
    switch (mainSCH->size)
    {
    case 0:
        return;
    case 1:
        mainSCH->head = NULL;
        mainSCH->tail = NULL;
        mainSCH->size--;
        free(current);
    default:
        mainSCH->head = mainSCH->head->next;
        free(current);
        mainSCH->size--;
    }
}
void SCH_deleteTask(int ID)
{
	Node *pFront = NULL;
    Node *pEnd = mainSCH->head;
    while((pEnd != NULL) && (pEnd != mainSCH->tail->next))
    {
    	if(pEnd->ID == ID){
    		if(pEnd == mainSCH->head) SCH_deleteHead();
    		else
    		{
    			pFront->next = pEnd->next;
    			pEnd->next = NULL;
    			free(pEnd);
    		}
    		mainSCH->size --;
    		break;
    	}
    	pFront = pEnd;
    	pEnd = pEnd->next;
    }
}
void SCH_addTask(void(*pFunction), int DELAY, int PERIOD, int ID)
{
    Node *node = createNode(pFunction, DELAY, PERIOD, ID, NULL);
    Node *pFront = NULL;
    Node *pEnd = mainSCH->head;
    bool added = false;
    int tmp = 0;
    while ((pEnd != NULL) && (pEnd != mainSCH->tail->next))
    {
        tmp = node->delay - pEnd->delay;
        if (tmp >= 0)
        {
            node->delay = tmp;
        }
        else if (tmp < 0)
        {
            node->next = pEnd;
            pEnd->delay = pEnd->delay - node->delay;
            if (pFront)
                pFront->next = node;
            else
            	mainSCH->head = node;
            added = true;
            break;
        }
        pFront = pEnd;
        pEnd = pEnd->next;
    }
    if (!added)
    {
        if (mainSCH->head)
        {
            mainSCH->tail->next = node;
            mainSCH->tail = mainSCH->tail->next;
        }
        else
        {
            mainSCH->head = mainSCH->tail = node;
        }
    }
    mainSCH->size++;
}
void SCH_updateTask()
{
    if(mainSCH->size > 0){
    	mainSCH->time_skip ++;
    	if(mainSCH->head->delay >= mainSCH->time_skip) mainSCH->head->delay -= mainSCH->time_skip;
    	else{
    		mainSCH->time_skip -= mainSCH->head->delay;
    		mainSCH->head->delay = 0;
    	}
    }

}
void SCH_dispatchTask()
{
    if (mainSCH->size > 0)
    {

        Node *p = mainSCH->head;
        while (p->delay == 0)
        {
            // Do task
        	(*p->pTask)();
//        	HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
            if (p->period > 0)
            {
                SCH_addTask(p->pTask, p->period, p->period, p->ID);
            }
            p = p->next;
            SCH_deleteHead();
        }
    }
}
