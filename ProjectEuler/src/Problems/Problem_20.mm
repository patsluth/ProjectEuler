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

- (id)solveProblem
{
	cpp_int fact = 100;
	
	for (uint64_t x = 2; x <= 100; x++) {
		fact *= x;
	}
	
	cpp_int factDigitSum = 0;
	
	while (fact > 0) {
		factDigitSum += fact % 10;
		fact /= 10;
	}
	
	return @(static_cast<int64_t>(factDigitSum));
}

@end




