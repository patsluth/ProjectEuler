// 
//  Problem_7.m
//  ProjectEuler
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

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	uint64_t number = 2;
	vector<uint64_t> primeNumbers;
	
	while (primeNumbers.size() < 10001) {
		
		if (isFactorPrime(factorInteger(number))) {
			primeNumbers.push_back(number);
		}
		
		number += 1;
		
	}
	
	if (primeNumbers.empty()) {
		completion(nil, self.endTime);
	} else {
		completion(@(primeNumbers.back()), self.endTime);	// 104743
	}
}

@end




