// 
//  Problem_1.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_1 : ProblemBase
{
}

@end





@implementation Problem_1

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	uint64_t sum = 0;
	
	for (uint64_t x = 0; x < 1000; x += 1) {
		if (x % 3 == 0 || x % 5 == 0) {
			sum += x;
		}
	}
	
	completion(@(sum), self.endTime);	// 233168
}

@end




