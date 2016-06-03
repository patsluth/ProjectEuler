// 
//  Problem_48.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_48 : ProblemBase
{
}

@end





@implementation Problem_48

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	cpp_int selfPowerSum = 0;
	
	for (uint x = 1; x <= 1000; x += 1) {
		
		cpp_int nextSelfPower = x;
		
		for (uint pow = 1; pow < x; pow += 1) {
			nextSelfPower *= x;
		}
		
		selfPowerSum += nextSelfPower;
	}
	
	string temp = selfPowerSum.str();
	
	completion(@(temp.substr(temp.size() - 10, temp.size() - 1).c_str()), self.endTime);	// 9110846700
}

@end




