// 
//  Problem_78.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_78 : ProblemBase
{
}

@end





@implementation Problem_78

- (id)solveProblem
{
	uint64_t n = 1;
	vector<int64_t> p;// = new vector<int64_t>;
	p.push_back(1);
	
	while (true) {
		
		uint64_t i = 0;
		uint64_t pentagonalN = 1;
		
		p.push_back(0);
		
		while (pentagonalN <= n) {
			
			uint64_t sign = (i % 4 > 1) ? -1 : 1;
			p[n] += p[n - pentagonalN] * sign;
			p[n] %= 1000000;
			i += 1;
			
			if (i % 2 == 0) {
				pentagonalN = pentagonalForN((i / 2) + 1);
			} else {
				pentagonalN = pentagonalForN(((i / 2) + 1) * -1);
			}
			
		}
		
		if (p[n] == 0) { // divisble by 1000000
			break;
		}
		
		n += 1;
	}
	
	return @(p.size());
}

@end





