// 
//  Problem_52.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_52 : ProblemBase
{
}

@end





@implementation Problem_52

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	for (uint64_t x = 1; ; x += 1) {
		
		// true for x*2 to x*6
		if ([self int:x containsSameDigitsAsInt:x * 2]) {
			if ([self int:x containsSameDigitsAsInt:x * 3]) {
				if ([self int:x containsSameDigitsAsInt:x * 4]) {
					if ([self int:x containsSameDigitsAsInt:x * 5]) {
						if ([self int:x containsSameDigitsAsInt:x * 6]) {
							completion(@(x), self.endTime);	// 142857
							return;
						}
					}
				}
			}
		}
	}
}

- (bool)int:(uint64_t)a containsSameDigitsAsInt:(uint64_t)b
{
	vector<uint64_t> aDigits;
	vector<uint64_t> bDigits;
	
	while (a != 0) {
		aDigits.push_back(a % 10);
		a /= 10;
	}
	
	while (b != 0) {
		bDigits.push_back(b % 10);
		b /= 10;
	}
	
	while (aDigits.size() == bDigits.size() && !aDigits.empty()) {
		
		uint64_t aDigit = aDigits.back();
		aDigits.pop_back();
		
		for (auto bItr = bDigits.begin(); bItr != bDigits.end(); advance(bItr, 1)) {
			
			if (aDigit == *bItr) {
				bDigits.erase(bItr);
				break;
			}
			
		}
		
	}
	
	if (aDigits.empty() && bDigits.empty()) {
		return true;
	}
	
	return false;
}

@end




