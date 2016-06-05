// 
//  Problem_57.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_57 : ProblemBase
{
}

@end





@implementation Problem_57

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	uint64 solution = 0;
	pair<cpp_int, cpp_int> f = { 3, 2 };
	
	for (uint64_t i = 1; i <= 1000; i += 1) {
		
		f.first += 2 * f.second;
		f.second = f.first - f.second;
		
		if (f.first.str().length() > f.second.str().length()) {
			solution += 1;
		}
		
	}
	
	completion(@(solution), self.endTime);	// 153
}

@end





