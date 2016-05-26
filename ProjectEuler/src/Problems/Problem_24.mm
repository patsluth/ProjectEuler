// 
//  Problem_24.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_24 : ProblemBase
{
}

@end





@implementation Problem_24

- (id)solveProblem
{
	string permutation = "0123456789";		// Current Permutation
	uint64_t permutationIndex = 1;			// Initial permutation
	
	while (nextPermutation(permutation)) {
		
		permutationIndex += 1;
		if (permutationIndex >= 1000000) {
			break;
		}
		
	}
	
	return @(permutation.c_str());
}

@end




