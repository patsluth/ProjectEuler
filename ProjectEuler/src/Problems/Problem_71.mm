// 
//  Problem_71.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"

bool operator <(const CGPoint &x, const CGPoint &y)
{
	uint64_t xNumerator = x.x * y.y;
	uint64_t yNumerator = y.x * x.y;
	return (xNumerator < yNumerator);
}

bool operator >(const CGPoint &x, const CGPoint &y)
{
	uint64_t xNumerator = x.x * y.y;
	uint64_t yNumerator = y.x * x.y;
	return (xNumerator > yNumerator);
}

bool operator ==(const CGPoint &x, const CGPoint &y)
{
	return (x.x == y.x && x.y == y.y);
}





@interface Problem_71 : ProblemBase
{
}

@end





@implementation Problem_71

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	set<CGPoint> fractions;
	CGPoint a = CGPointMake(3, 7);
	CGPoint b = CGPointMake(0, 1);
	
	for (uint64_t d = 1000000; d >= 1; d -= 1) {
		
		uint64_t n = ((a.x * d) - 1) / a.y;		// numerator
		CGPoint f = CGPointMake(n, d);			// current fraction
		
		if (b < f) {
			b = f;
		}
		
	}
	
	completion(@((uint64_t)b.x), self.endTime);	// 428570
}

@end





