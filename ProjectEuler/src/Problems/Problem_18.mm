// 
//  Problem_18.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_18 : ProblemBase
{
}

@end





@implementation Problem_18

- (id)solveProblem
{
	pyramid p = pyramidFromFile("p018_triangle.txt");
	return @(pyramid_SumOfMaxPath(p));
}

@end




