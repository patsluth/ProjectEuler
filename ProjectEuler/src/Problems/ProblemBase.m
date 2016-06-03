// 
//  ProblemBase.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface ProblemBase()
{
}

@property (nonatomic) CGFloat startTime;

@end





@implementation ProblemBase

- (id)solveProblem
{
	NSAssert(false, @"You must override this method");
	return nil;
}

- (void)solveProblem:(solutionBlock)completion
{
	[self tdd];
	
	self.startTime = CACurrentMediaTime();
}

- (CGFloat)endTime
{
	return CACurrentMediaTime() - self.startTime;
}

- (void)tdd
{
	
}

@end




