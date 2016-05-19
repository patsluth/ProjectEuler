//
//  Problem_24.m
//  projecteuler
//
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
//

#import "ProblemBase.h"





@interface Problem_24 : ProblemBase
{
}

@end





@implementation Problem_24

- (id)solveProblem
{
	NSArray *digits = [NSArray arrayWithObjects:@(0), @(1), @(2), nil];
	
	test(0, digits);
	
	return nil;
}

void test(NSUInteger cur, NSArray *digits)
{
	
	printf("%ld ", [[digits objectAtIndex:cur] integerValue]);
	
	for (NSUInteger i = cur; i < digits.count; i += 1) {
		
		if (i != cur) {
			printf("%ld ", [[digits objectAtIndex:i] integerValue]);
			
		}
		if (cur + 1 < digits.count)
			test(cur + 1, digits);
		
		printf("\n");
		
	}
	
	printf("\n");
	
//	if (digits.count > 1)
	
}

@end




