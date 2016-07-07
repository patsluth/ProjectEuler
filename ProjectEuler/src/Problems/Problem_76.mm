// 
//  Problem_76.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_76 : ProblemBase
{
}

@end





@implementation Problem_76

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	uint64_t solutions[101] = { 0 };
	solutions[0] = 1;
 
	for (uint64_t i = 1; i <= 99; i += 1) {
		for (uint64_t j = i; j < 101; j += 1) {
			solutions[j] += solutions[j - i];
		}
	}
	
	completion(@(solutions[100]), self.endTime);	// 190569291
}

@end




