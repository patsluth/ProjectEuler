// 
//  Problem_53.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_53 : ProblemBase
{
}

@end





@implementation Problem_53

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	uint64_t nCrCount = 0; // number of nCr combos over 1 million
	
	for (uint64_t n = 23; n <= 100; n += 1) { // we are given the first one doesnt occur until n = 23
		for (uint64_t r = 1; r <= n; r += 1) {
			
			cpp_int nFact = factorial_cpp_int(n);
			cpp_int rFact = factorial_cpp_int(r);
			
			cpp_int n_minus_rFact = factorial_cpp_int(n - r);
			
			cpp_int result = nFact / (rFact * n_minus_rFact);
			
			if (result > 1000000) {
				nCrCount += 1;
			}
			
		}
	}
	
	completion(@(nCrCount), self.endTime);	// 4075
}

@end




