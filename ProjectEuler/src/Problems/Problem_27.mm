// 
//  Problem_27.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_27 : ProblemBase
{
}

@end





@implementation Problem_27

- (id)solveProblem
{
	// quadratic in form n^2 + an + b
	
	pair<uint64_t, int64_t> maxContainer = {0, 0}; // first = # of primes, second = (a * b)
	
	for (int64_t a = -999; a < 1000; a++) {
		
		for (int64_t b = -999; b < 1000; b++) {
			
			uint64_t n = 0;
			
			while (true) {
				
				int64_t result = (n * n) + (n * a) + (b);
				
				if (result < 0 || !isPrime(result)) {
					break;
				}
				
				n++;
				
			}
			
			if (n > maxContainer.first) {
				maxContainer.first = n;
				maxContainer.second = (a * b);
			}
			
		}
		
	}
	
	return @(maxContainer.second);

}

@end




