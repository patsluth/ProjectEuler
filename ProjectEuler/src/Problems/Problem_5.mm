// 
//  Problem_5.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_5 : ProblemBase
{
}

@end





@implementation Problem_5

- (id)solveProblem
{
	uint64_t a = 1;
	uint64_t b = 20;
	
	return @(smallestMultipleOfRange(a, b));
}

static uint64_t smallestMultipleOfRange(uint64_t a, uint64_t b)
{
	uint64_t m = b;
	
	if (a == 0 || b == 0 || a > b) { // invalid
		return 0;
	}
	
	while (true) {
		
		bool success = true;
		
		for (uint64_t x = a; x <= b; x++) {
			if (m % x != 0) {
				success = false;
				break;
			}
		}
		
		if (success == true) {
			return m;
		}
		
		m++;
	}
	
	return 0;
}

@end




