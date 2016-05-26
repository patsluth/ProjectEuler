// 
//  Problem_49.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"

#import "primes.h"





@interface Problem_49 : ProblemBase
{
}

@end





@implementation Problem_49

- (id)solveProblem
{
	set<uint64_t> &millionPrimes = primes::sharedPrimes()->loadPrimes(1); // 1st million primes
	auto itr = millionPrimes.begin();
	
	while (itr != millionPrimes.end()) {
		
		uint64_t p1 = *itr;
		
		if (p1 > 999) {
			if (p1 > 9999) {
				break;
			}
			
			auto itr2 = itr;
			advance(itr2, 1);
			
			// Valid 4 digit prime
			
			while (itr2 != millionPrimes.end()) {
				
				uint64_t p2 = *itr2;
				
				if (p2 > 9999) {
					break;
				}
				
				if (p2 != 4817 && isPermutation(p1, p2)) {
					
					uint64_t deltaP = p2 - p1;
					uint64_t p3 = p2 + deltaP;
					
					if (p3 > 9999 || !primes::sharedPrimes()->isPrime(p3)) {
						break;
					} else if (isPermutation(p1, p3)) { // found it
						if (p1 != 1487 && p1 != 4817 && p1 != 8147) {
							return @(concatanate(concatanate(p1, p2), p3));
						}
					}
					
					
				}
				
				advance(itr2, 1);
				
			}
			
		}
		
		advance(itr, 1);
	}
	
	return nil;
}

@end




