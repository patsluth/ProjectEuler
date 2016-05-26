// 
//  Problem_4.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_4 : ProblemBase
{
}

@end





@implementation Problem_4

- (id)solveProblem
{
	uint64_t factorOne = 0;
	uint64_t factorTwo = 0;
	uint64_t largestProduct = 0;
	
	for (uint64_t x = 100; x <= 999; x++) { // all 3 digit integers
		for (uint64_t y = 100; y <= 999; y++) { // all 3 digit integers
			
			uint64_t currentProduct = x * y;
			
			if (isPalindrome(currentProduct) && currentProduct > largestProduct) {
				factorOne = x;
				factorTwo = y;
				largestProduct = currentProduct;
			}
			
		}
	}
	
	return @(largestProduct);
}

@end




