// 
//  Problem_21.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_21 : ProblemBase
{
}

@end





@implementation Problem_21

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	set<uint64_t> amicableNumbers;
	
	for (uint64_t a = 1; a < 10000; a += 1) {
		
		auto pdA = calculateProperDivisors(a);
		uint64_t b = sumOfVector(pdA);
		
		if (a != b) {
			
			auto pdB = calculateProperDivisors(b);
			
			if (sumOfVector(pdB) == a) {
				amicableNumbers.insert(a);
				amicableNumbers.insert(b);
			}
			
		}
		
	}
	
	completion(@(sumOfSet(amicableNumbers)), self.endTime);	// 31626
}

@end




