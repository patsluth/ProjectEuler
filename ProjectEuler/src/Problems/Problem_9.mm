// 
//  Problem_1.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_9 : ProblemBase
{
}

@end





@implementation Problem_9

- (id)solveProblem
{
	for (uint64_t x = 1; x < 1000; x++) {
		for (uint64_t y = x + 1; y < 1000; y++) {
			
			uint64_t z = 1000 - x - y;
			
			if ( (x * x) + (y * y) == (z * z) ) {
				
				return @(x * y * z);
				
			}
			
		}
	}
	
	return nil;
}

@end




