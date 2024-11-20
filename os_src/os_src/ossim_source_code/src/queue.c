#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
        if (q == NULL) return 1;
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
        /* TODO: put a new process to queue [q] */
        #ifdef MLQ_SCHED //using multiple queue with different prio
        if(q != NULL && proc != NULL && q->size < MAX_QUEUE_SIZE){
                q->proc[q->size] = proc;
                q->size ++;
        }

        if(q != NULL && proc != NULL && q->size < MAX_QUEUE_SIZE){
                int i = 0;
                while(i < q->size){
                        if(proc->priority < q->proc[i]->priority) break;
                        i ++;
                }

                for(int j = q->size; j > i; j --){
                        q->proc[j] = q->proc[j - 1]; 
                }
                q->proc[i] = proc;
                q->size++;
        }
        #endif
        
}

struct pcb_t * dequeue(struct queue_t * q) {
        /* TODO: return a pcb whose prioprity is the highest
         * in the queue [q] and remember to remove it from q
         * */
        if(empty(q)) return NULL;
        struct pct_t* process = q->proc[0];
        for(int i = 0; i < q->size - 1; i ++){
                q->proc[i] = q->proc[i + 1];
        }
        q->proc[q->size] = NULL;
        q->size --;
	return process;
}

