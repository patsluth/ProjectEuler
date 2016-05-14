//
//  Problem_12.m
//  projecteuler
//
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
//

#import "ProblemBase.h"





@interface Problem_12 : ProblemBase
{
}

@end





@implementation Problem_12

- (id)solveProblem
{
	uint64_t triangleNumber = 1;
	uint64_t triangleValue = 1;
	
	while (true) {
		
		triangleNumber++;
		triangleValue += triangleNumber;
		
		if (numberOfDivisors(triangleValue) > 500) {
			return @(triangleValue);
		}
		
	}
	
	return nil;
}

@end




