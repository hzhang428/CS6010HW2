/*
 * queue.c
 *
 *  Created on: Sep 19, 2016
 *      Author: haozhang
 *	Implementation of the queue
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "queue.h"

/**
 * Methods to create and FIFO queue
 */
Queue* createQueue() {
	Queue *queue =(Queue*) malloc(sizeof(struct Queue));
	if (queue == NULL) {
		printf("Fatal Error: Out of memory when creating queue\n");
		exit(1);
	}
	queue->front = NULL;
	queue->back = NULL;
	queue->size = 0;
	return queue;
}

/**
 * Methods to add one Node at the back of the queue
 */
void enqueue(Queue *queue, double serviceTime, double enterTime) {
	Part *newNode = (Part*) malloc(sizeof(struct Part));
	if (newNode == NULL) {
		printf("Fatal Error: Out of memory\n");
		exit(1);
	}
	newNode->serviceTime = serviceTime;
	newNode->enterTime = enterTime;
	newNode->waitTime = 0.0;
	newNode->next = NULL;
	if (queue->size == 0) {
		queue->front = newNode;
		queue->back = newNode;
	} else {
		queue->back->next = newNode;
		queue->back = newNode;
	}
	queue->size++;
}

/**
 * Methods to pull a Node from the front of the queue
 */
Part* dequeue(Queue *queue) {
	Part *top = (Part*) malloc(sizeof(struct Part));
	top = queue->front;
	if (queue->size == 1) {
		queue->front = NULL;
		queue->back = NULL;
	} else {
		queue->front = queue->front->next;
	}
	queue->size--;
	return top;
}

/**
 * Print out all the Node in the queue
 */
void printQueue(Queue *queue) {
	Part *current = queue->front;
	while(current != NULL) {
		printf("data: %f, type: %f\n", current->serviceTime, current->enterTime);
		current = current->next;
	}
	free(current);
}


/**
 * Free the memory that is hold by the queue
 */
void freeQueue(Queue *queue) {
	Part *current;
	while(queue->front != NULL) {
		current = queue->front;
		queue->front = queue->front->next;
		free(current);
	}
	free(queue);
}
