/*
 * EventHandler.c
 *
 *  Created on: Sep 23, 2016
 *      Author: haozhang
 */

#include <stdio.h>
#include <stdlib.h>
#include "randomNumber.h"
#include "EventHandler.h"
#include "queue.h"

void action(Engine *engine, Event *event) {
	if (event->type == 1) {
		arrival(engine, event->timeStamp);
	} else if (event->type == 2) {
		service1(engine, event->timeStamp);
	} else if (event->type == 3) {
		service2(engine, event->timeStamp);
	} else if (event->type == 4) {
		service3(engine, event->timeStamp);
	} else {
		depart(engine, event->timeStamp);
	}
}

void arrival(Engine *engine, double currenttime) {
	enqueue(engine->station1, randexp(15), 1);
	schedule(engine, currenttime + randexp(12), 1);
	schedule(engine, currenttime, 2);
}

void service1(Engine *engine, double currenttime) {
	Part *part = dequeue(engine->station1);
	enqueue(engine->station2, part->serviceTime, currenttime);
	if (engine->station2->size == 1) {
		schedule(engine, currenttime + part->serviceTime, 3);
	}
	if (engine->station1->size > 0) {
		schedule(engine, currenttime + part->serviceTime, 2);
	}
	free(part);
}

void service2(Engine *engine, double currenttime) {
	Part *part = dequeue(engine->station2);
	enqueue(engine->station3, part->serviceTime, currenttime);
	if (engine->station3->size == 1) {
		schedule(engine, currenttime + part->serviceTime, 4);
	}
	if (engine->station2->size > 0) {
		schedule(engine, currenttime + part->serviceTime, 3);
	}
	free(part);
}

void service3(Engine *engine, double currenttime) {
	Part *part = dequeue(engine->station3);
	schedule(engine, currenttime + part->serviceTime, 5);
	if (engine->station3->size > 0) {
		schedule(engine, currenttime + part->serviceTime, 4);
	}
	free(part);
}

void depart(Engine *engine, double currenttime) {
	printf("parts in the sink - time:%f\n", currenttime);
}
