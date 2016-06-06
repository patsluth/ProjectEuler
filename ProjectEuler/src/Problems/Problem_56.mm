// 
//  Problem_56.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"

#import <boost/multiprecision/cpp_dec_float.hpp>

typedef number<cpp_dec_float<200> > cpp_dec_float_p56;





@interface Problem_56 : ProblemBase
{
}

@end





@implementation Problem_56

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	uint64_t solution = 0;
	
	for (uint64_t a = 1; a < 100; a += 1) {
		for (uint64_t b = 1; b < 100; b += 1) {
			
			cpp_dec_float_p56 value = pow(cpp_dec_float_p56(a), cpp_dec_float_p56(b));
			string str = value.str();
			uint64_t digitSum = sumOfDigitsInString(str);
			
			solution = MAX(solution, digitSum);
			
		}
	}
	
	completion(@(solution), self.endTime);	// 972
}

@end





