//
//  Problem_74.m
//  ProjectEuler
//
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
//

#import "ProblemBase.h"

#import "numberChain.h"





@interface Problem_74 : ProblemBase
{
}

@end





@implementation Problem_74

- (id)solveProblem
{
	uint64_t x = 0;
	
	numberChain_continueCalculatingFunction continueCalculating = [] (const numberChain *currentChain) {
		if (currentChain->size() > 60) { // stop calculating chain with 60 items
			return false;
		} else {
			return true;
		}
	};
	
	for (uint64_t start = 0; start < 1000000; start++) {
		//+1 because the last term is guaranteed to be a repeated term
		if (numberChain_calculate(start, sumOfFactorialOfDigits_Chain(), continueCalculating).size() == 60 + 1) {
			x++;
		}
	}
	
	return @(x);
}

numberChain_nextNumberFunction sumOfFactorialOfDigits_Chain()
{
	return [] (const uint64_t *currentEndOfChain) {
		
		uint64_t nextEndOfChain = 0;
		uint64_t currentEndOfChain_Copy = *currentEndOfChain;
		
		while (currentEndOfChain_Copy != 0) {
			
			nextEndOfChain += factorial(currentEndOfChain_Copy % 10);
			currentEndOfChain_Copy /= 10;
			
		}
		
		return nextEndOfChain;
		
	};
}

@end





