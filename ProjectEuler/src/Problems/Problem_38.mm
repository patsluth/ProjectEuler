//
//  Problem_38.m
//  projecteuler
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

- (id)solveProblem
{
	uint64_t largestPandigital = 0;
	
	for (uint64_t x = 1; x < 10000; x++) {
		
		uint64_t y = x;
		
		for (uint64_t n = 2; n < 10; n++) { // 2 - 9. We already have 1 by setting y to x
			
			y = concatanate(y, x * n);
			
			if (y > 987654321) { // largest possible 9 digit pandigital number
				break;
			}
			
			if (isPandigital(y, 9)){
				if (largestPandigital < y) {
					largestPandigital = y;
				} else {
					break;
				}
			}
			
		}
		
	}
	
	return @(largestPandigital);
}

@end




