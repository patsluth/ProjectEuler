// 
//  Problem_20.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_20 : ProblemBase
{
}

@end





@implementation Problem_20

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	cpp_int fact = 100;
	
	for (uint64_t x = 2; x <= 100; x += 1) {
		fact *= x;
	}
	
	cpp_int factDigitSum = 0;
	
	while (fact > 0) {
		factDigitSum += fact % 10;
		fact /= 10;
	}
	
	completion(@(static_cast<int64_t>(factDigitSum)), self.endTime);	// 648
}

@end




