//
//  Problem_10.m
//  ProjectEuler
//
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
//

#import "ProblemBase.h"





@interface Problem_10 : ProblemBase
{
}

@end





@implementation Problem_10

- (id)solveProblem
{
	uint64_t primeLimit = 2000000;
	uint64_t number = 2;
	uint64_t sum = 0;
	
	while (number < primeLimit) {
		
		if (isPrime(number)) {
			sum += number;
		}
		
		number++;
		
	}
	
	return @(sum);
}

@end




