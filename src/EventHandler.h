/*
 * EventHandler.h
 *
 *  Created on: Sep 24, 2016
 *      Author: haozhang
 */

#ifndef EVENTHANDLER_H_
#define EVENTHANDLER_H_
#include "simulationEngine.h"

/**
 * wrapper function to call the specific action to handle the event
 */
void action(Engine *engine, Event *event);

/**
 * generate the part and enqueue to the first station
 */
void arrival(Engine *engine, double currenttime);

/**
 * dequeue from station1 and service and enqueue to station1
 */
void service1(Engine *engine, double currenttime);

/**
 * dequeue from station2 and service and enqueue to station2
 */
void service2(Engine *engine, double currenttime);

/**
 * dequeue from station3 and service and enqueue to station3
 */
void service3(Engine *engine, double currenttime);

/**
 * leave the system and accumulate the statistics
 */
void depart(Engine *engine, double currenttime);


#endif /* EVENTHANDLER_H_ */
