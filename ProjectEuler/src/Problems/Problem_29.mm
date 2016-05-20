//
//  Problem_29.m
//  ProjectEuler
//
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
//

#import "ProblemBase.h"





@interface Problem_29 : ProblemBase
{
}

@end





@implementation Problem_29

- (id)solveProblem
{
	set<cpp_int> distinctTerms;
	
	for (cpp_int a = 2; a <= 100; a++) {
		for (uint64_t b = 2; b <= 100; b++) {
			distinctTerms.insert( pow(a, b) );
		}
	}
	
	return @(distinctTerms.size());

}

@end




