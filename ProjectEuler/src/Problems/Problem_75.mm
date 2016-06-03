// 
//  Problem_75.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_75 : ProblemBase
{
}

@end





@implementation Problem_75

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	uint64_t maxP = 1500000;
	uint64_t count = 0;
	uint64_t *triangles = new uint64_t[maxP + 1];
	
	for (uint64_t m = 2; m < sqrt(maxP / 2); m += 1) {
		for (uint64_t n = 1; n < m; n += 1) {
			
			if ((m + n) % 2 != 0 && gcd(m, n) == 1) {
				
				uint64_t a = (m * m) - (n * n);
				uint64_t b = 2 * m * n;
				uint64_t c = (m * m) + (n * n);
				uint64_t p = a + b + c;
				
				while (p <= maxP) {
					
					triangles[p] += 1;
					
					if (triangles[p] == 1) {
						count += 1;
					}
					if (triangles[p] == 2) {
						count -= 1;
					}
					
					p += (a + b + c);
				}
				
			}
			
		}
	}
	
	delete [] triangles;
	
	completion(@(count), self.endTime);	// 161667
}

@end





