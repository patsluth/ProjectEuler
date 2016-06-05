// 
//  Problem_40.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_40 : ProblemBase
{
}

@end





@implementation Problem_40

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	string champernownesConstant = "";
	uint64_t product = 1;
	
	for (uint64_t i = 1; champernownesConstant.size() < 1000000; i += 1) {
		
		champernownesConstant += to_string(i);
		
		if (i == 1 || 1 == 10 || i == 100 || i == 1000 || i == 10000 || i == 100000 || i == 1000000) {
			product *= stoull(champernownesConstant.substr(i - 1, 1));
		}
		
	}
	
	completion(@(product), self.endTime);	// 210
}

@end




