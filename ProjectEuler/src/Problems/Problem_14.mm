// 
//  Problem_14.m
//  ProjectEuler
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

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	vector<uint64_t> greatestSequence;
	
	for (uint64_t x = 1; x < 1000000; x += 1) {
		
		vector<uint64_t> currentSequence;
		currentSequence.push_back(x);
		
		while (currentSequence.back() != 1) {
			currentSequence.push_back(nextCollatzInt(currentSequence.back()));
		}
		
		if (currentSequence.size() > greatestSequence.size()) {
			greatestSequence = currentSequence;
		}
		
	}
	
	completion(@(greatestSequence.front()), self.endTime);	// 837799
}

@end




