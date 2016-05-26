// 
//  Problem_67.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"

#import "hashMap.h"

#import <boost/foreach.hpp>





@interface Problem_67 : ProblemBase
{
}

@end





@implementation Problem_67

- (id)solveProblem
{
	pyramid p = pyramidFromFile("p067_triangle.txt");
	return @(pyramid_SumOfMaxPath(p));
}

@end





