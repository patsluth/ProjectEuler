// 
//  Problem_87.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"

#import <boost/foreach.hpp>





@interface Problem_87 : ProblemBase
{
}

@end





@implementation Problem_87

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	vector<uint64_t> primeCache; // TODO: use primes.h
	
	for (uint64_t p = 2; p < sqrt(50000000); p += 1) {
		if (isPrime(p)) {
			primeCache.push_back(p);
		}
	}
	
	set<uint64_t> count; // no duplicates
	
	BOOST_FOREACH (uint64_t x, primeCache) {
		BOOST_FOREACH (uint64_t y, primeCache) {
			BOOST_FOREACH (uint64_t z, primeCache) {
				
				uint64_t sum = ( (x * x) + (y * y * y) + (z * z * z * z) );
				
				if (sum < 50000000) {
					count.insert(sum);
				} else {
					break;
				}
				
			}
		}
	}
	
	completion(@(count.size()), self.endTime);	// 1097343
}

@end





