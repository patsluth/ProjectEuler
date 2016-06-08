// 
//  Problem_77.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"

#import "primes.h"
#import "hashMap.h"





@interface Problem_77 : ProblemBase
{
}

@property (strong, nonatomic) NSArray *coins;

@end





@implementation Problem_77

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	primes::loadPrimes(1);
	
	hashMap<uint64_t, uint64_t> solutions;
	*solutions.valueForKey(0) = 1;
	
	for (auto itr = primes::begin(); itr != primes::end(); advance(itr, 1)) {
		
		uint64_t prime = *itr;
		
		for (uint64_t j = prime; j < 100; j += 1) {
			*solutions.valueForKey(j) += *solutions.valueForKey(j - prime);
		}
		
		if (*solutions.valueForKey(prime) > 5000) {
			completion(@(prime), self.endTime);	// 71
			return;
		}
	}
	
	completion(nil, self.endTime);
}

@end





