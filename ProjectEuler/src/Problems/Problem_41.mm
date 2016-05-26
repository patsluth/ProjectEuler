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

- (id)solveProblem
{
	set<uint64_t> &millionPrimes = primes::sharedPrimes()->loadPrimes(1); // 1st million primes
	auto itr = millionPrimes.rbegin(); // reverse iterator
									   // Since we are looking for the largest, the first prime to pass is the answer
	
	while (itr != millionPrimes.rend()) {
		
		if (isPandigital(*itr, 1, numberOfDigits(*itr))) {
			return @(*itr);
		}
		
		advance(itr, 1);
	}
	
	return nil;
}

@end




