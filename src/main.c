/*
 * main.c
 *
 *  Created on: Sep 27, 2016
 *      Author: haozhang
 */

#include <stdio.h>
#include <stdlib.h>
#include "simulationEngine.h"
#include "randomNumber.h"
#include "EventHandler.h"
#include "queue.h"
#include "priorityqueue.h"


int main(void) {
	Engine *simulation = createEngine();
	run(simulation);
	return 1;
}
