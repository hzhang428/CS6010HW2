/*
 * simulationEngine.c
 *
 *  Created on: Sep 19, 2016
 *      Author: haozhang
 */

#include <stdio.h>
#include <stdlib.h>
#include "simulationEngine.h"
#include "randomNumber.h"
#include "EventHandler.h"

Engine* createEngine() {
	Engine *engine = (Engine*) malloc(sizeof(struct Engine));
	if (engine == NULL) {
		printf("Fatal Error: Out of memory\n");
		exit(1);
	}
	engine->FEL = createPQ();
	engine->station1 = createQueue();
	engine->station2 = createQueue();
	engine->station3 = createQueue();
	engine->station1Served = 0;
	engine->station2Served = 0;
	engine->station3Served = 0;
	engine->duration = 1000.0;
	engine->systemTime = 0.0;
	return engine;
}

void schedule(Engine *engine, double timeStamp, int type) {
	push(engine->FEL, timeStamp, type);
	printf("schedule time: %f, type: %d\n", timeStamp, type);
}

void run(Engine *engine) {
	schedule(engine, 0, 1);
	while (engine->FEL->size > 0) {
		Event *event = poll(engine->FEL);
		engine->systemTime = event->timeStamp;
		printf("System time: %f, Event: %d\n", engine->systemTime, event->type);;
		if (engine->systemTime > engine->duration) {
			return;
		}
		action(engine, event);
		free(event);
	}
}
