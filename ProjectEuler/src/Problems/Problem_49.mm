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

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	primes::loadPrimes(1);
	
	for (auto itr = primes::begin(); itr != primes::end(); advance(itr, 1)) {
		
		uint64_t p1 = *itr;
		
		if (p1 > 999) {
			if (p1 > 9999) {
				break;
			}
			
			// Valid 4 digit prime
			
			for (auto itr2 = next(itr); itr2 != primes::end(); advance(itr2, 1)) {
				
				uint64_t p2 = *itr2;
				
				if (p2 > 9999) {
					break;
				}
				
				string p1Str = to_string(p1);
				
				if (p2 != 4817 && is_permutation(p1Str.begin(), p1Str.end(), to_string(p2).begin())) {
					
					uint64_t deltaP = p2 - p1;
					uint64_t p3 = p2 + deltaP;
					
					if (p3 > 9999 || !primes::isPrime(p3)) {
						break;
					} else if (is_permutation(p1Str.begin(), p1Str.end(), to_string(p3).begin())) { // found it
						if (p1 != 1487 && p1 != 4817 && p1 != 8147) {
							completion( @(concatanate(concatanate(p1, p2), p3)), self.endTime);	// 296962999629
							return;
						}
					}
					
					
				}
				
			}
			
		}
	}
	
	completion(nil, self.endTime);
}

@end




