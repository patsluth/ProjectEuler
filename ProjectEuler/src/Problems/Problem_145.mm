// 
//  Problem_145.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_145 : ProblemBase
{
}

@end





@implementation Problem_145

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	uint64_t reversibleNumberCount = 0;
	
	for (uint64_t i = 1; i < 1000000000; i += 1) {
		if (isReversible(i)) {
			reversibleNumberCount += 1;
		}
	}
	
	completion(@(reversibleNumberCount), self.endTime);	// 608720
}

/**
 *  A number n is called reversible if n + reverse(n) consists entirely of odd digits
 *  ex		36 + 63 = 99
 *
 *  @param n
 *
 *  @return bool
 */
bool isReversible(uint64_t n)
{
	if (n % 10 == 0) { // Leading 0's not allowed as per problem 145 spec
		return false;
	}
	
	uint64_t reverseN = reverseNumber(n);
	n += reverseN;
	
	while (n > 0) {
		
		uint64_t digit = n % 10;
		if (digit % 2 == 0) {
			return false;
		}
		n /= 10;
		
	}
	
	return true;
}

@end




