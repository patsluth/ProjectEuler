// 
//  Problem_80.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"

#import <boost/multiprecision/cpp_dec_float.hpp>





@interface Problem_80 : ProblemBase
{
}

@end





@implementation Problem_80

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	uint64_t solution = 0;
	
	for (cpp_dec_float_100 n = 2.0; n <= 100.0; n += 1.0) {
		
		cpp_dec_float_100 squareRoot = sqrt(n);
		
		NSString *squareRootString = [NSString stringWithFormat:@"%s", squareRoot.str().c_str()];
		squareRootString = [squareRootString stringByReplacingOccurrencesOfString:@"." withString:@""];
		
		if (squareRootString.length >= 100) {
			squareRootString = [squareRootString substringWithRange:NSMakeRange(0, 100)];
			string temp = string(squareRootString.UTF8String);
			solution += sumOfDigitsInString(temp);
		}
		
	}
	
	completion(@(solution), self.endTime);	// 40886
}

@end





