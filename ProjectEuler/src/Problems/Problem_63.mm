//
//  Problem_63.m
//  projecteuler
//
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
//

#import "ProblemBase.h"





@interface Problem_63 : ProblemBase
{
}

@end





@implementation Problem_63

- (id)solveProblem
{
	uint64_t solutions = 0;
	
	for (uint64_t base = 1; base <= 9; base += 1) {
		for (uint64_t n = 1; n < 25; n += 1) {
			
			cpp_int value = pow(cpp_int(base), n);
			
			if (value.str().length() == n) {
				solutions += 1;
			}
			
		}
	}
	
	return @(solutions);
}

@end





