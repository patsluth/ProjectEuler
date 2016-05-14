//
//  Problem_45.m
//  projecteuler
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

- (id)solveProblem
{
	uint64_t n = 286;
	
	//number is triangle, pentagonal, and hexagonal
	while (nForPentagonal(triangleForN(n)) == 0 || nForHexagonal(triangleForN(n)) == 0) {
		n++;
	}
	
	return @(triangleForN(n));
}

@end




