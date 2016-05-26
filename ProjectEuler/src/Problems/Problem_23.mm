// 
//  Problem_23.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_23 : ProblemBase
{
}

@end





@implementation Problem_23

- (id)solveProblem
{
	set<uint64_t> abundantNumberCache;
	
	for (uint64_t aN = 1; aN < 28123; aN++) {
		if (getNumberType(aN) == NumberType_Abundant) {
			abundantNumberCache.insert(aN);
		}
	}
	
	uint64_t sum = 0;
	
	for (uint64_t x = 1; x < 28123; x++) { // check all integers less than 28123 (it is proven all ints > 28123 can be written as sum of 2 abundants)
		
		bool isSumOfTwoAbundantNumbers = false;
		
		for (uint64_t aN : abundantNumberCache) { // check all abundant numbers less than the current int
			
			if (aN >= x) {
				break;
			}
			
			uint64_t difference = x - aN;
			
			// if the difference of the current number and the current abundant number is an abuntant number, we passed the test
			if (abundantNumberCache.count(difference) != 0) {
				isSumOfTwoAbundantNumbers = true;
				break;
			}
			
		}
		
		if (!isSumOfTwoAbundantNumbers) {
			sum += x;
		}
		
	}
	
	return @(sum);
}

@end




