// 
//  Problem_112.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_112 : ProblemBase
{
}

@end





@implementation Problem_112

- (id)solveProblem
{
	uint64_t bouncyCount = 0;
	
	for (uint64_t i = 1; i < UINT64_MAX; i += 1) {
		
		if (isBouncyNumber(i)) {
			bouncyCount += 1;
		}
		
		double bouncyProportion = (double)bouncyCount / (double)i;
		
		if (ABS(bouncyProportion - 0.99) == 0.0000000000000) {
			return @(i);
		}
	}
	
	return nil;
}

/**
 *  A number n is called increasing if no digit is exceeded by the digit to its left
 *  ex		n = 134468
 *
 *  @param n
 *
 *  @return bool
 */
bool isIncreasingNumber(uint64_t n)
{
	string _n = to_string(n);
	
	for (auto itr = _n.begin(); itr + 1 != _n.end(); advance(itr, 1)) {
		if (*itr > *next(itr)) {
			return false;
		}
	}
	
	return true;
}

/**
 *  A number n is called decreasing if no digit is exceeded by the digit to its right
 *  ex		n = 66420
 *
 *  @param n
 *
 *  @return bool
 */
bool isDecreasingNumber(uint64_t n)
{
	string _n = to_string(n);
	
	for (auto itr = _n.begin(); itr + 1 != _n.end(); advance(itr, 1)) {
		if (*itr < *next(itr)) {
			return false;
		}
	}
	
	return true;
}

/**
 *  A number n that is neither increasing nor decreasing is called a 'bouncy' number
 *  ex		n = 155349
 *
 *  @param n
 *
 *  @return bool
 */
bool isBouncyNumber(uint64_t n)
{
	return (!isIncreasingNumber(n) && !isDecreasingNumber(n));
}

@end





