// 
//  Problem_44.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_44 : ProblemBase
{
}

@end





@implementation Problem_44

- (id)solveProblem
{
	uint64_t minDifference = UINT64_MAX;
	uint64_t k = 0;
	
	while (true) {
		
		k++;
		
		uint64_t p_k = pentagonalForN(k);
		
		// if the difference between the prev pentagonal and this one is greater than the minDifference
		// then all previous pentagonals will be as well
		if (pentagonalForN(p_k - 1) > minDifference) {
			break;
		}
		
		for (uint64_t j = k - 1; j != 0; j--) {
			
			uint64_t p_j = pentagonalForN(j);
			
			uint64_t sum = p_k + p_j;
			uint64_t difference = p_k - p_j;
			
			if (difference >= minDifference) {
				break;
			} else {
				
				if (nForPentagonal(sum) != 0 && nForPentagonal(difference) != 0) {
					minDifference = difference;
				}
				
			}
			
		}
	}
	
	return @(minDifference);
}

@end




