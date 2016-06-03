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
	
	set<uint64_t> amicableNumbers; // make sure there are no duplicates
	
	for (uint64_t a = 1; a < 10000; a += 1) {
		
		uint64_t b = sumOfVector(calculateProperDivisors(a));
		
		if (a != b && sumOfVector(calculateProperDivisors(b)) == a) {
			amicableNumbers.insert(a);
			amicableNumbers.insert(b);
		}
		
	}
	
	uint64_t sum = 0;
	
	for (auto x : amicableNumbers) {
		sum += x;
	}
	
	completion(@(sum), self.endTime);	// 31626
}

@end




