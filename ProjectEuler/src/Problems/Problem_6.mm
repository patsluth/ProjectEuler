// 
//  Problem_6.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_6 : ProblemBase
{
}

@end





@implementation Problem_6

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	uint64_t sumOfSquares = 0;
	uint64_t sum = 0;
	
	for (uint x = 1; x <= 100; x += 1) {
		sumOfSquares += (x * x);
		sum += x;
	}
 
	uint64_t sumSquared = (sum * sum);
	
	completion(@(sumSquared - sumOfSquares), self.endTime);	// 25164150
}

@end




