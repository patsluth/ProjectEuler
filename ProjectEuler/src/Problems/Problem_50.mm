// 
//  Problem_50.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"

#import "primes.h"





@interface Problem_50 : ProblemBase
{
}

@end





@implementation Problem_50

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	completion(@(largestConsecutivePrimeSumThatIsPrime(1000000)), self.endTime);	// 997651
}

uint64_t largestConsecutivePrimeSumThatIsPrime(uint64_t max)
{
	primes::loadPrimes(1);
	
	uint64_t sum = 0;
	
	auto startItr = primes::begin();
	auto endItr = primes::begin();
	
	for (auto itr = startItr; itr != primes::end(); advance(itr, 1)) {
		
		if (sum + *itr < max) {
			endItr = itr;
			sum += *itr;
		}
		
	}
	
	auto _startItr = startItr;
	auto _endItr = endItr;
	uint64_t _sum = sum;
	
	while (startItr != endItr) { // remove end until we find largest prime
		
		if (primes::isPrime(sum) && sum < max) {
			break;
		}
		
		sum -= *endItr;
		advance(endItr, -1);
		
	}
	
	while (_startItr != _endItr) { // remove start and try to increase end until we find largest prime
		
		if (primes::isPrime(_sum) && _sum < max) {
			break;
		}
		
		_sum -= *_startItr;
		advance(_startItr, 1);
		advance(_endItr, 1);
		if (_sum + *_endItr < max) {
			_sum += *_endItr;
		} else {
			advance(_endItr, -1);
		}
		
	}
	
	return MAX(sum, _sum);
}

@end




