//
//  Problem_34.m
//  projecteuler
//
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
//

#import "ProblemBase.h"





@interface Problem_34 : ProblemBase
{
}

@end





@implementation Problem_34

- (id)solveProblem
{
	uint64_t sum = 0;
	
	for (uint64_t x = 3; x < 1000000; x++){ // 1! and 2! dont count
		
		if ([self intEqualsSumOfFactorialOfItsDigits:x]) {
			sum += x;
		}
		
	}
	
	return @(sum);
}

- (bool)intEqualsSumOfFactorialOfItsDigits:(uint64_t)i
{
	uint64_t iCopy = i;
	uint64_t sum = 0;
	
	while (iCopy > 0) {
		
		sum += factorial(iCopy % 10);
		iCopy /= 10;
		
	}
	
	return (sum == i);
}

@end




