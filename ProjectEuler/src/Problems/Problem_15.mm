//
//  Problem_15.m
//  projecteuler
//
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
//

#import "ProblemBase.h"

#import <boost/multiprecision/number.hpp>





@interface Problem_15 : ProblemBase
{
}

@end





@implementation Problem_15

- (id)solveProblem
{
	cpp_int n = 20;
	
	return @(static_cast<int64_t>(nCr(n * 2, n)));
}

@end




