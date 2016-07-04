// 
//  Problem_97.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"

#import <boost/multiprecision/cpp_dec_float.hpp>





@interface Problem_97 : ProblemBase
{
}

@end





@implementation Problem_97

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	cpp_int solution = powm(cpp_int(2), cpp_int(7830457), cpp_int(10000000000));
	solution *= 28433;
	solution += 1;
	solution %= 10000000000;
	
	completion(@(static_cast<uint64_t>(solution)), self.endTime);	// 8739992577
}

@end





