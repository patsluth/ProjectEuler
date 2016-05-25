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
	string permutation = "0123456789";				// current permutation
	
	for (uint64_t i = 1; i < 1000000; i += 1) {
		if (!nextPermutation(permutation)) {
			return nil;
		}
	}
	
	return @(permutation.c_str());
}

/**
 *  Swaps elements in provided string to give the next permutation
 *
 *  @param permutation
 *
 *  @return bool true if there are more possible permutations
 */
bool nextPermutation(string &permutation)
{
	uint64_t n = permutation.length();
	int64_t i = n - 2;								// Find the largest i
	while ((i >= 0) && (permutation[i] > permutation[i + 1])) {
		i -= 1;
	}
 
	if (i < 0) {									// No more permutations
		return false;
	}
	
	int64_t k =n - 1;								// Find the largest element after i but not larger than i
	while (permutation[i] > permutation[k]) {
		k -= 1;
	}
	
	swap(permutation[i], permutation[k]);
 
	k = 0;											// Swap the last n - i elements
	for (int64_t j = i + 1; j < ((n + i) / 2) + 1; j += 1, k += 1) {
		swap(permutation[j], permutation[n - k - 1]);
	}
 
	return true;
}

@end




