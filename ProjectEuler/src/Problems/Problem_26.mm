// 
//  Problem_26.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_26 : ProblemBase
{
}

@end





@implementation Problem_26

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	for (uint64_t d = 2; d < 20; d += 1) {
		
		CGFloat fraction = 1.0 / d;
		uint64_t n = 1;
		
		printf("%llu\t%f\t%lu\t", d, fraction, recurringDigitCycle(fraction).size());
		
		for (uint64_t x = 1; x < 40; x += 1) {
			n *= 10;
			fraction = (n / d) * 1.0;
			uint64_t digit = (uint64_t)fraction % 10;
			printf("%llu", digit);
		}
		
		printf("\n");
		
	}
	
	completion(@(0), self.endTime);	// ???
}

vector<uint64_t> recurringDigitCycle(CGFloat f)
{
	vector<uint64_t> cycle;
	
	for (uint64_t i = 1; ; i += 1) {
		
		f *= 10;
		uint64_t digit = (uint64_t)f % 10;
		
		if (cycle.size() == 0) {
			cycle.push_back(digit);
		} else {
			if (cycle.back() == digit) {
				cycle.pop_back();
				break;
			} else if (cycle.front() == digit) {
				break;
			} else {
				cycle.push_back(digit);
			}
		}
		
	}
	
	return cycle;
}

@end




