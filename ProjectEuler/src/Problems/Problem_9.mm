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

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	for (uint64_t x = 1; x < 1000; x += 1) {
		for (uint64_t y = x + 1; y < 1000; y += 1) {
			
			uint64_t z = 1000 - x - y;
			
			if ( (x * x) + (y * y) == (z * z) ) {
				
				completion(@(x * y * z), self.endTime);	// 31875000
				return;
				
			}
			
		}
	}
	
	completion(nil, self.endTime);
}

@end




