//
//  Problem_17.m
//  ProjectEuler
//
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
//

#import "ProblemBase.h"





@interface Problem_17 : ProblemBase
{
}

@end





@implementation Problem_17

- (id)solveProblem
{
	uint64_t letterCount = 0;
	
	for (uint64_t i = 1; i <= 1000; i += 1) {
		string word = englishRepresentationOfNumber(i);
		letterCount += word.length();
	}
	
	return @(letterCount);
}

@end




