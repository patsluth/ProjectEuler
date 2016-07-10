// 
//  Problem_69.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_69 : ProblemBase
{
}

@end





@implementation Problem_69

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	uint64_t n = 0;
	uint64_t max = 1;
	auto primes = sieveOfEratosthenes(2, 200);
 
	while(max * primes[n] < 1000000) {
		max *= primes[n];
		n++;
	}
	
	completion(@(max), self.endTime);	// 510510
}

/**
 *  Calulcate vector of primes from a to b
 *
 *  @param a lower bounds
 *  @param b upper bounds
 *
 *  @return vector<uint64_t>
 */
vector<uint64_t> sieveOfEratosthenes(uint64_t a, uint64_t b)
{
	bool *isComposite = new bool[b + 1];
	memset(isComposite, true, sizeof(bool) * b + 1);
	
	uint64_t bSqrt = sqrt(b);

	for (uint64_t i = 1; i <= bSqrt; i += 1) {
		
		if (isComposite[i]) {
			uint64_t twoI = 2 * i;
			for (uint64_t j = twoI * (i + 1); j <= b; j += twoI + 1) {
				isComposite[j] = false;
			}
		}
		
	}
	
	vector<uint64_t> primeSieve;
	
	if (a < 3) {
		primeSieve.push_back(2);
		a = 3;
	}
	
	for (uint64_t i = 0; i <= b; i += 1) {
		if (isComposite[i]) {
			primeSieve.push_back((2 * i) + 1);
		}
	}
	
	delete [] isComposite;
	return primeSieve;
}

- (void)tdd
{
	assert(totient(1) == 1);
	assert(totient(2) == 1);
	assert(totient(3) == 2);
	assert(totient(4) == 2);
	assert(totient(5) == 4);
	assert(totient(6) == 2);
	assert(totient(7) == 6);
	assert(totient(8) == 4);
	assert(totient(9) == 6);
}

uint64_t totient(uint64_t n)
{
	uint64_t count = 0;
	
	for (uint64_t i = 0; i < n; i += 1) {
		if (gcd(i, n) == 1) {
			count += 1;
		}
	}
	
	return count;
}

@end





