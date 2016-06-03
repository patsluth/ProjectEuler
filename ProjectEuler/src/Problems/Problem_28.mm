// 
//  Problem_28.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_28 : ProblemBase
{
}

@end





@implementation Problem_28

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	uint64_t sum = 1;
	uint64_t corner = 1;
	
	for (uint64_t x = 3; x <= 1001; x += 2) {
		for (uint64_t y = 0; y < 4; y += 1) { //  calculate each corner
			
			corner += (x - 1);
			sum += corner;
			
		}
	}
	
	completion(@(sum), self.endTime);	// 669171001
}

@end




