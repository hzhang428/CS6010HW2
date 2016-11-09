/*
 * randomNumber.h
 *
 *  Created on: Sep 27, 2016
 *      Author: haozhang
 */

#ifndef RANDOMNUMBER_H_
#define RANDOMNUMBER_H_

/**
 * Generate a random number that is in the range of [0,1)
 */
double urand();

/**
 * Generate a random number from an exponential distribution
 * with mean of U
 */
double randexp(double U);


#endif /* RANDOMNUMBER_H_ */
