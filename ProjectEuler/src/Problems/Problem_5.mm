// 
//  Problem_5.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_5 : ProblemBase
{
}

@end





@implementation Problem_5

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	uint64_t a = 1;
	uint64_t b = 20;
	uint64_t i = 2520 * 20;
	
	while (true) {
		
		bool success = true;
		
		for (uint64_t x = b; x >= a; x -= 1) {
			if (i % x != 0) {
				success = false;
				break;
			}
		}
		
		if (success == true) {
			break;
		}
		
		i += 2;
	}
	
	completion(@(i), self.endTime);	// 232792560
}

@end




