// 
//  Problem_25.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_25 : ProblemBase
{
}

@end





@implementation Problem_25

- (id)solveProblem
{
	cpp_int prevF = 0;
	cpp_int curF = 1;
	uint64_t curFIndex = 1;
	
	while (curF.str().size() < 1000) {
		
		curFIndex++;
		
		cpp_int nextF = curF + prevF;
		prevF = curF;
		curF = nextF;
		
	}
	
	return @(curFIndex);
}

@end




