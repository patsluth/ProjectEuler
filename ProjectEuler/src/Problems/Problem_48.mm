//
//  Problem_48.m
//  projecteuler
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

- (id)solveProblem
{
	cpp_int selfPowerSum = 0;
	
	for (uint x = 1; x <= 1000; x++) {
		
		cpp_int nextSelfPower = x;
		
		for (uint pow = 1; pow < x; pow++) {
			nextSelfPower *= x;
		}
		
		selfPowerSum += nextSelfPower;
	}
	
	string temp = selfPowerSum.str();
	return @(temp.substr(temp.size() - 10, temp.size() - 1).c_str());
}

@end




