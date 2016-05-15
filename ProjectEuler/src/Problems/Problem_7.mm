//
//  Problem_7.m
//  projecteuler
//
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
//

#import "ProblemBase.h"





@interface Problem_7 : ProblemBase
{
}

@end





@implementation Problem_7

- (id)solveProblem
{
	uint64_t number = 2;
	vector<uint64_t> primeNumbers;
	
	while (primeNumbers.size() < 10001) {
		
		if (isFactorPrime(factorInteger(number))) {
			primeNumbers.push_back(number);
		}
		
		number++;
		
	}
	
	if (!primeNumbers.empty()) {
		return @(primeNumbers.back());
	}
	
	return nil;
}

@end




