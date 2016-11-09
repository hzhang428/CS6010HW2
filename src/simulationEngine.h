/*
 * simulationEngine.h
 *
 *  Created on: Sep 24, 2016
 *      Author: haozhang
 */

#ifndef SIMULATIONENGINE_H_
#define SIMULATIONENGINE_H_

#include "priorityqueue.h"
#include "queue.h"

/**
 * contains a future event list FEL (priority queue)
 * And the duration of the simulation
 */
typedef struct Engine {
	PQ *FEL;
	Queue *station1;
	Queue *station2;
	Queue *station3;
	double timeinStation1;
	double timeinStation2;
	double timeinStation3;
	int station1Served;
	int	station2Served;
	int station3Served;
	double duration;
	double systemTime;
}Engine;

/**
 * create an simulation engine
 */
Engine* createEngine();

/**
 * schedule an event and push it into the FEL
 * type 1 = arrival into station1
 * type 2 = service in station 1 and enter station2
 * type 3 = service in station 2 and enter station3
 * type 4 = service in station 3 and depart
 * type 5 = leave the system and update the system statistics
 */
void schedule(Engine *engine, double timeStamp, int type);

/**
 * drive the simulation engine to run if there is still events in FEL
 */
void run(Engine *engine);

#endif /* SIMULATIONENGINE_H_ */
