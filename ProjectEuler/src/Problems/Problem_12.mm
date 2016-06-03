// 
//  Problem_12.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_12 : ProblemBase
{
}

@end





@implementation Problem_12

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	uint64_t triangleNumber = 1;
	uint64_t triangleValue = 1;
	
	while (true) {
		
		triangleNumber += 1;
		triangleValue += triangleNumber;
		
		if (numberOfDivisors(triangleValue) > 500) {
			completion(@(triangleValue), self.endTime);	// 76576500
			return;
		}
		
	}
}

@end




