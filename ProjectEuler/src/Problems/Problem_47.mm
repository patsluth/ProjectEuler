// 
//  Problem_47.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"

#import "primes.h"





@interface Problem_47 : ProblemBase
{
}

@end





@implementation Problem_47

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	assert(primes::isPrime(982451654));
	uint64_t x = 0;
	
	for (auto itr = primes::begin(); itr != primes::end(); advance(itr, 1)) {
		x += 1;
	}
	
	printf("%llu", x);
//
//	for (uint64_t i = 644; i < 1000; i += 1) {
//		
//	}
	
	completion(@(0), self.endTime);	// ??
}

@end




