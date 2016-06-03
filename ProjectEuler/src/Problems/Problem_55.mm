// 
//  Problem_55.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_55 : ProblemBase
{
}

@end





@implementation Problem_55

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	uint64_t solution = 0;
	
	for (uint64_t i = 1; i < 10000; i += 1) {
		if (isLychrel(i)) {
			solution += 1;
		}
	}
	
	completion(@(solution), self.endTime);	// 249
}

@end





