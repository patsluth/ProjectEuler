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

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	uint64_t bouncyCount = 0;
	
	for (uint64_t i = 1; i < UINT64_MAX; i += 1) {
		
		if (isBouncyNumber(i)) {
			bouncyCount += 1;
		}
		
		double bouncyProportion = (double)bouncyCount / (double)i;
		
		if (ABS(bouncyProportion - 0.99) == 0.0000000000000) {
			completion(@(i), self.endTime);	// 1587000
			return;
		}
	}
}

@end





