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
	
	completion(@(smallestMultipleOfRange(a, b)), self.endTime);	// 232792560
}

uint64_t smallestMultipleOfRange(uint64_t a, uint64_t b)
{
	uint64_t m = b;
	
	if (a == 0 || b == 0 || a > b) { // invalid
		return 0;
	}
	
	while (true) {
		
		bool success = true;
		
		for (uint64_t x = a; x <= b; x += 1) {
			if (m % x != 0) {
				success = false;
				break;
			}
		}
		
		if (success == true) {
			return m;
		}
		
		m += 1;
	}
	
	return 0;
}

@end




