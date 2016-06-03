// 
//  Problem_29.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_29 : ProblemBase
{
}

@end





@implementation Problem_29

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	set<cpp_int> distinctTerms;
	
	for (cpp_int a = 2; a <= 100; a += 1) {
		for (uint64_t b = 2; b <= 100; b += 1) {
			distinctTerms.insert( pow(a, b) );
		}
	}
	
	completion(@(distinctTerms.size()), self.endTime);	// 9183
}

@end




