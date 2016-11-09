/*
 * queue.h
 *
 *  Created on: Sep 19, 2016
 *      Author: haozhang
 *  Struct of Node and Queue, and the abstract methods of the queue
 */

#ifndef QUEUE_H_
#define QUEUE_H_

/**
 * Definition of the Node
 */
typedef struct Part{
	double serviceTime;
	double waitTime;
	double enterTime;
	struct Part *next;
}Part;

/*
 * Definition of the Queue*
 */
typedef struct Queue{
	Part *front;
	Part *back;
	int size;
}Queue;

/**
 * Methods to create and FIFO queue
 */
Queue * createQueue();

/**
 * Methods to add one Node at the back of the queue
 */
void enqueue(Queue *queue, double data, double enterTime);

/**
 * Methods to pull a Node from the front of the queue
 */
Part * dequeue(Queue *queue);

/**
 * Print out all the Node in the queue
 */
void printQueue(Queue *queue);

/**
 * Free the memory that is hold by the queue
 */
void freeQueue(Queue *queue);

#endif /* QUEUE_H_ */
