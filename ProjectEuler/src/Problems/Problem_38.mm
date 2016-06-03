// 
//  Problem_38.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_38 : ProblemBase
{
}

@end





@implementation Problem_38

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	uint64_t largestPandigital = 0;
	
	for (uint64_t x = 1; x < 10000; x += 1) {
		
		uint64_t y = x;
		
		for (uint64_t n = 2; n < 10; n += 1) { // 2 - 9. We already have 1 by setting y to x
			
			y = concatanate(y, x * n);
			
			if (y > 987654321) { // largest possible 9 digit pandigital number
				break;
			}
			
			if (isPandigital(y, 1, 9)) {
				if (largestPandigital < y) {
					largestPandigital = y;
				} else {
					break;
				}
			}
			
		}
		
	}
	
	completion(@(largestPandigital), self.endTime);	// 932718654
}

@end




