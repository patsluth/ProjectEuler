// 
//  Problem_67.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_67 : ProblemBase
{
}

@end





@implementation Problem_67

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	pyramid p = pyramidFromFile("p067_triangle.txt");
	
	completion(@(maxPathSum(p)), self.endTime);	// 7273
}

@end





