// 
//  Problem_45.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_45 : ProblemBase
{
}

@end





@implementation Problem_45

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	uint64_t n = 286;
	
	// number is triangle, pentagonal, and hexagonal
	while (nForPentagonal(triangleForN(n)) == 0 || nForHexagonal(triangleForN(n)) == 0) {
		n += 1;
	}
	
	completion(@(triangleForN(n)), self.endTime);	// 1533776805
}

@end




