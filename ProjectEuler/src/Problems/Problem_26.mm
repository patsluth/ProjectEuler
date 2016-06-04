// 
//  Problem_26.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"

#import <map>





@interface Problem_26 : ProblemBase
{
}

@end





@implementation Problem_26

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	// first = d
	// second = cycle length
	pair<uint64_t, uint64_t> max = { 0, 0 };
	
	for (uint64_t denomenator = 1; denomenator <= 1000; denomenator += 1) {
		
		uint64_t numerator = 1;
		uint64_t digitIndex = 0;
		uint64_t *remainders = new uint64_t[1000];
		
		while (remainders[numerator] == 0 && numerator > 0) {
			
			remainders[numerator] = digitIndex;
			numerator = (numerator * 10) % denomenator;
			digitIndex += 1;
			
		}
		
		if (max.second < digitIndex - remainders[numerator]) {
			max = { denomenator, digitIndex - remainders[numerator] };
		}
		
	}
	
	completion(@(max.first), self.endTime);	// 983
}

@end




