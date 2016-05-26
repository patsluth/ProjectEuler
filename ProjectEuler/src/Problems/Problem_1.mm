// 
//  Problem_1.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_1 : ProblemBase
{
}

@end





@implementation Problem_1

- (id)solveProblem
{
	NSInteger sum = 0;
	
	for (NSUInteger x = 0; x < 1000; x++) {
		if (x % 3 == 0 || x % 5 == 0) {
			sum += x;
		}
	}
	
	return @(sum);
}

@end




