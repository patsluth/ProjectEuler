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

- (id)solveProblem
{
	return @(largestConsecutivePrimeSumThatIsPrime(1000000));
}

uint64_t largestConsecutivePrimeSumThatIsPrime(uint64_t max)
{
	set<uint64_t> &millionPrimes = primes::sharedPrimes()->loadPrimes(1); // 1st million primes
	uint64_t sum = 0;
	
	auto startItr = millionPrimes.begin();
	auto endItr = millionPrimes.begin();
	auto itr = startItr;
	
	while (itr != millionPrimes.end()) {
		
		if (sum + *itr < max) {
			endItr = itr;
			sum += *itr;
		}
		
		advance(itr, 1);
		
	}
	
	auto _startItr = startItr;
	auto _endItr = endItr;
	uint64_t _sum = sum;
	
	while (startItr != endItr) { // remove end until we find largest prime
		
		if (primes::sharedPrimes()->isPrime(sum) && sum < max) {
			break;
		}
		
		sum -= *endItr;
		advance(endItr, -1);
		
	}
	
	while (_startItr != _endItr) { // remove start and try to increase end until we find largest prime
		
		if (primes::sharedPrimes()->isPrime(_sum) && _sum < max) {
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




