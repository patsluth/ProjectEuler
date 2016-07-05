// 
//  Problem_47.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"

#import "primes.h"





@interface Problem_47 : ProblemBase
{
}

@end





@implementation Problem_47

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	vector<uint64_t> consecutivePrimes;
	set<uint64_t> *primeFactors = new set<uint64_t>();
	
	for (uint64_t n = 647; consecutivePrimes.size() != 4; n += 1) {
		
		primeFacors(n, primeFactors);
		
		if ((*primeFactors).size() == 4) {
			
			if (consecutivePrimes.size() > 0 && consecutivePrimes.back() != n - 1) {
				consecutivePrimes.clear(); // Reset consecutive prime list
			}
			
			consecutivePrimes.push_back(n);
			
		}
		
	}
	
	completion(@(*consecutivePrimes.begin()), self.endTime);	// 134043
	
	(*primeFactors).clear();
	delete primeFactors;
}

void primeFacors(uint64_t n, set<uint64_t> *s)
{
	primes::loadPrimes(1);
	
	(*s).clear();
	uint64_t rem = n;
 
	for (auto itr = primes::begin(); itr != primes::end(); advance(itr, 1)) {
		
		uint64_t prime = *itr;
		
		if (prime * prime > n) {
			(*s).insert(prime);
			return;
		}
		
		while (rem % prime == 0) {
			rem /= prime;
			(*s).insert(prime);
		}
		
		if (rem == 1) { // No remainder
			break;
		}
		
	}
}

@end




