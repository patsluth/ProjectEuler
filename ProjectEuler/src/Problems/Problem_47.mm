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
	
//	set<uint64_t> &millionPrimes = primes::sharedPrimes()->loadPrimes(1); // 1st million primes
//	
//	for (uint64_t i = 644; i < 1000; i += 1) {
//		
//	}
	
	completion(@(0), self.endTime);	// ??
}

@end




