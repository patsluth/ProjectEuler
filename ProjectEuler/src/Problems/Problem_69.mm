// 
//  Problem_69.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_69 : ProblemBase
{
}

@end





@implementation Problem_69

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	uint64_t n = 0;
	uint64_t max = 1;
	auto primes = sieveOfEratosthenes(2, 200);
 
	while(max * primes[n] < 1000000) {
		max *= primes[n];
		n++;
	}
	
	completion(@(max), self.endTime);	// 510510
}

@end





