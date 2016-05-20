//
//  Problem_3.m
//  ProjectEuler
//
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
//

#import "ProblemBase.h"





@interface Problem_3 : ProblemBase
{
}

@end





@implementation Problem_3

- (id)solveProblem
{
	uint64_t number = 600851475143;
	
	std::vector<uint64_t> primeFactors;
	
	while (true) {
		
		Factor f = factorInteger(number);
		number = f.y;
		
		if (f.x != 0 && f.y != 0) { // We can keep on factoring
			
			// Pop the last added prime factor because it is still factorable
			if (!primeFactors.empty()) {
				primeFactors.pop_back();
			}
			
			// Push both factors
			// x is guaranteed to be the smallest it can
			// y will be removed and factored again in the next iteration
			primeFactors.push_back(f.x);
			primeFactors.push_back(f.y);
			
		} else {
			break;
		}
		
	}
	
	if (!primeFactors.empty()) {
		return @(primeFactors.back());
	}
	
	return nil;
}

@end




