// 
//  Problem_24.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_24 : ProblemBase
{
}

@end





@implementation Problem_24

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	string permutation = "0123456789";		// Current Permutation
	
	for (uint64_t i = 1; i < 1000000; i += 1) {
		if (!next_permutation(permutation.begin(), permutation.end())) {
			break;
		}
	}
	
	completion(@(permutation.c_str()), self.endTime);	// 2783915460
}

@end




