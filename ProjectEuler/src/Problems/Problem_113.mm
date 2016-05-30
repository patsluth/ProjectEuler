// 
//  Problem_113.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_113 : ProblemBase
{
}

@end





@implementation Problem_113

- (id)solveProblem
{
	// http://www.mathblog.dk/project-euler-113-googol-not-bouncy/
	cpp_int solution = nCr(100 + 10, 10) + nCr(100 + 9, 9) - 10 * 100 - 2;
	return [NSString stringWithFormat:@"%s", solution.str().c_str()];
}

@end




