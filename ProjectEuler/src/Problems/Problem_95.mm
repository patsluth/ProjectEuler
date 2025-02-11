// 
//  Problem_95.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"

#import "hashmap.h"
#import "numberChain.h"





@interface Problem_95 : ProblemBase
{
}

@end





@implementation Problem_95

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	completion([self solveProblem], self.endTime);	// 14316
}

- (id)solveProblem
{
	numberChain_continueCalculatingFunction continueCalculating = [] (const numberChain *currentChain) {
		
		if (currentChain->back() == currentChain->front() || currentChain->back() > 1000000) {
			return false;
		} else {
			return true;
		}
		
	};
	
	numberChain_nextNumberFunction sumOfProperDivisors_Chain = [] (const uint64_t *currentEndOfChain) {
		
		uint64_t currentEndOfChain_Copy = *currentEndOfChain;
		auto pd = calculateProperDivisors(currentEndOfChain_Copy);
		return sumOfVector(pd);
		
	};
	
	
	numberChain longest;
	
	for (uint64_t start = 0; start < 1000000; start += 1) {
		
		numberChain cur = numberChain_calculate(start, sumOfProperDivisors_Chain, continueCalculating);
		
		// constraints
		if (cur.back() < 1000000 &&
			cur.back() == cur.front() &&
			cur.size() > longest.size()) {
			
			longest = cur;
			
		}
		
	}
	
	return @(longest.back());
}

@end





