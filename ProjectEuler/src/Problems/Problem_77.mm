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

- (id)solveProblem
{
	set<uint64_t> &millionPrimes = primes::sharedPrimes()->loadPrimes(1); // 1st million primes
	
	hashMap<uint64_t, uint64_t> solutions;
	*solutions.valueForKey(0) = 1;
	
	for (auto itr = millionPrimes.begin(); itr != millionPrimes.end(); advance(itr, 1)) {
		
		uint64_t prime = *itr;
		
		for (uint64_t j = prime; j < 100; j += 1) {
			*solutions.valueForKey(j) += *solutions.valueForKey(j - prime);
		}
		
		if (*solutions.valueForKey(prime) > 5000) {
			return @(prime);
		}
	}
	
	return nil;
}

@end





