//
//  Problem_14.m
//  projecteuler
//
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
//

#import "ProblemBase.h"





@interface Problem_14 : ProblemBase
{
}

@end





@implementation Problem_14

- (id)solveProblem
{
	vector<uint64_t> greatestSequence;
	
	for (uint64_t x = 1; x < 1000000; x++) {
		
		vector<uint64_t> currentSequence;
		currentSequence.push_back(x);
		
		while (currentSequence.back() != 1) {
			currentSequence.push_back(nextCollatzInt(currentSequence.back()));
		}
		
		if (currentSequence.size() > greatestSequence.size()) {
			greatestSequence = currentSequence;
		}
		
	}
	
	return @(greatestSequence.front());
}

@end




