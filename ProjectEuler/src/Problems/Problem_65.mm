// 
//  Problem_65.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_65 : ProblemBase
{
}

@end





@implementation Problem_65

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	
	pair<cpp_int, cpp_int> f = { 1, 2 };
	
	for (uint64_t i = 2; i <= 101; i += 1) {
		
		cpp_int temp = f.first;
		cpp_int x = 1;
		
		if (i % 3 == 0) {
			x = (i / 3) * 2;
		}
		
		f.first = f.second;
		f.second = (f.first * x) + temp;
		
	}
	
	string solution = f.first.str();
	completion(@(sumOfDigitsInString(solution)), self.endTime);	// 272
}

@end





