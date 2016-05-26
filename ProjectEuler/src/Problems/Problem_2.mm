// 
//  Problem_2.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_2 : ProblemBase
{
}

@end





@implementation Problem_2

- (id)solveProblem
{
	NSInteger sum = 0;
	
	NSInteger previousFib = 1;
	NSInteger currentFib = 1;
	
	while (currentFib <= 4000000) {
		
		// process current fib
		if (currentFib % 2 == 0) { // even
			sum += currentFib;
		}
		
		NSInteger temp = previousFib;
		previousFib = currentFib;
		currentFib = currentFib + temp;
		
	}
	
	return @(sum);
}

@end




