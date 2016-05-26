// 
//  Problem_46.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_46 : ProblemBase
{
}

@end





@implementation Problem_46

- (id)solveProblem
{
	uint64_t n = 3;
	
	while (true) {
		
		if (!isPrime(n)) {
			
			bool success = false;
			
			for (uint64_t x = 1; x < n; x++) {
				if (isPrime(x)) {
					
					uint64_t difference = n - x;
					
					if (difference % 2 == 0) {
						
						uint64_t possibleSquare = difference / 2;
						float squareRoot = sqrt(possibleSquare);
						
						if (fmod(squareRoot, (uint64_t)squareRoot) == 0) { // is a square
							success = true;
						}
						
					}
					
				}
			}
			
			if (!success) { // this odd composite is not the sum of a prime and 2 * a square
				return @(n);
			}
			
		}
		
		n += 2; // odd
	}
}

@end




