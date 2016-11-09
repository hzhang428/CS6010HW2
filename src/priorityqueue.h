/*
 * priorityqueue.h
 *
 *  Created on: Sep 21, 2016
 *      Author: haozhang
 */

#ifndef PRIORITYQUEUE_H_
#define PRIORITYQUEUE_H_

typedef struct Event {
	double timeStamp;
	int type;
	struct Event *next;
}Event;

/**
 * detail information about and priority queue
 */
typedef struct PQ {
	Event *front;
	int size;
}PQ;

/**
 * create an empty priority queue
 */
PQ* createPQ();

/**
 * insert and event into the priority queue to the position based on its data
 */
void push(PQ *pq, double timeStamp, int type);

/**
 * take out the event from the top of the queue
 * contains event with smallest timestamp.
 */
Event* poll(PQ *pq);

/**
 * print out the priority queue
 * for debugging propose
 */
void printPQ(PQ *pq);

/**
 * Free the memory that is holding up by the queue
 */
void freePQ(PQ *pq);

#endif /* PRIORITYQUEUE_H_ */
