// 
//  Problem_206.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_206 : ProblemBase
{
}

@end





@implementation Problem_206

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	uint64_t min = 1020304050607080900;
	uint64_t max = 1929394959697989990;
	
	uint64_t minSqr = sqrt(min);
	uint64_t maxSqr = sqrt(max);
	
	for (uint64_t i = maxSqr; i >= minSqr; i -= 1) {
		
		uint64_t i2 = (i * i);
		
		if ((i2 / 1) % 10 == 0 &&
			(i2 / 100) % 10 == 9 &&
			(i2 / 10000) % 10 == 8 &&
			(i2 / 1000000) % 10 == 7 &&
			(i2 / 100000000) % 10 == 6 &&
			(i2 / 10000000000) % 10 == 5 &&
			(i2 / 1000000000000) % 10 == 4 &&
			(i2 / 100000000000000) % 10 == 3 &&
			(i2 / 10000000000000000) % 10 == 2 &&
			(i2 / 1000000000000000000) % 10 == 1) {
			
			completion(@(i), self.endTime);	// 1389019170
			return;
			
		}
	}
	
	completion(nil, self.endTime);
}

@end




