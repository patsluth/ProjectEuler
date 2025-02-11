// 
//  Problem_36.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_36 : ProblemBase
{
}

@end





@implementation Problem_36

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	uint64_t sum = 0;
	
	for (uint64_t i = 0; i < 1000000; i += 1) {
		
		if (isPalindrome(i)) {
			
			string binaryI = bitset<64>(i).to_string();
			binaryI = binaryI.erase(0, binaryI.find_first_not_of("0")); // erase all extra 0's
			
			if (isPalindrome(binaryI)) {
				sum += i;
			}
			
		}
		
	}
	
	completion(@(sum), self.endTime);	// 872187
}

@end




