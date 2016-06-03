// 
//  Problem_92.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"

#import "hashmap.h"
#import "numberChain.h"





@interface Problem_92 : ProblemBase
{
}

@end





@implementation Problem_92

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	uint64_t x = 0;
	
	numberChain_continueCalculatingFunction continueCalculating = [] (const numberChain *currentChain) {
		if (currentChain->back() == 89) { // stop calculating chain at 89
			return false;
		} else {
			return true;
		}
	};
	
	for (uint64_t start = 0; start < 10000000; start += 1) {
		if (numberChain_calculate(start, sumOfSquaresOfDigits_Chain(), continueCalculating).back() == 89) {
			x += 1;
		}
	}
	
	completion(@(x), self.endTime);	// 8581146
}

numberChain_nextNumberFunction sumOfSquaresOfDigits_Chain()
{
	return [] (const uint64_t *currentEndOfChain) {
		
		uint64_t nextEndOfChain = 0;
		uint64_t currentEndOfChain_Copy = *currentEndOfChain;
		
		while (currentEndOfChain_Copy != 0) {
			
			nextEndOfChain += ( (currentEndOfChain_Copy % 10) * (currentEndOfChain_Copy % 10) ); // sum of current digit squared
			currentEndOfChain_Copy /= 10;
			
		}
		
		return nextEndOfChain;
		
	};
}

@end





