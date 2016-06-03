// 
//  Problem_2.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_2 : ProblemBase
{
}

@end





@implementation Problem_2

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	uint64_t sum = 0;
	
	uint64_t previousFib = 1;
	uint64_t currentFib = 1;
	
	while (currentFib <= 4000000) {
		
		// process current fib
		if (currentFib % 2 == 0) { // even
			sum += currentFib;
		}
		
		uint64_t temp = previousFib;
		previousFib = currentFib;
		currentFib = currentFib + temp;
		
	}
	
	completion(@(sum), self.endTime);	// 4613732
}

@end




