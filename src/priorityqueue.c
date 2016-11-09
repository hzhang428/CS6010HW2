/*
 * priorityqueue.c
 *
 *  Created on: Sep 21, 2016
 *      Author: haozhang
 */

#include <stdio.h>
#include <stdlib.h>
#include "priorityqueue.h"

PQ * createPQ() {
	PQ *pq = (PQ*) malloc(sizeof(struct PQ));
	if (pq == NULL) {
		printf("Fatal Error: Out of memory\n");
		exit(1);
	}
	pq->front = NULL;
	pq->size = 0;
	return pq;
}

void push(PQ *pq, double timeStamp, int type) {
	Event *current = (Event*) malloc(sizeof(struct Event));
	Event *newEvent = (Event*) malloc(sizeof(struct Event));
	newEvent->timeStamp = timeStamp;
	newEvent->type = type;
	newEvent->next = pq->front;
	pq->front = newEvent;
	current = pq->front;
	while(current->next != NULL && current->timeStamp > current->next->timeStamp) {
		double tempdata = current->timeStamp;
		int temptype = current->type;
		current->timeStamp = current->next->timeStamp;
		current->type = current->next->type;
		current->next->timeStamp = tempdata;
		current->next->type = temptype;
		current = current->next;
	}
	pq->size += 1;
}

Event* poll(PQ *pq) {
	Event *top = (Event*) malloc(sizeof(struct Event));
	top = pq->front;
	pq->front = pq->front->next;
	pq->size -= 1;
	return top;
}

void printPQ(PQ *pq) {
	Event *current = pq->front;
	while(current != NULL) {
		printf("data: %f, type: %d\n", current->timeStamp, current->type);
		current = current->next;
	}
	free(current);
}


void freePQ(PQ *pq) {
	Event *current;
	while(pq->front != NULL) {
		current = pq->front;
		pq->front = pq->front->next;
		free(current);
	}
	free(pq);
}
