// 
//  Problem_41.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"

#import "primes.h"





@interface Problem_41 : ProblemBase
{
}

@end





@implementation Problem_41

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	primes::loadPrimes(1);
	
	// reverse iterator, since we are looking for the largest, the first prime to pass is the answer
	for (auto itr = primes::rbegin(); itr != primes::rend(); advance(itr, 1)) {
		if (isPandigital(*itr, 1, numberOfDigits(*itr))) {
			completion(@(*itr), self.endTime);	// 7652413
			return;
		}
	}
	
	completion(nil, self.endTime);
}

@end




