/*
 * randomNumber.c
 *
 *  Created on: Sep 27, 2016
 *      Author: haozhang
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * Generate a random number that is in the range of [0,1)
 */
double urand() {
	return (double) rand() / ((unsigned) RAND_MAX + 1);
}

/**
 * Generate a random number from an exponential distribution
 * with mean of U
 */
double randexp(double U) {
	return - (U * log(1.0 - urand()));
}
