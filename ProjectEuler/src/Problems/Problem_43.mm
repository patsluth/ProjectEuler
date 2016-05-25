//
//  Problem_43.m
//  ProjectEuler
//
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
//

#import "ProblemBase.h"





@interface Problem_43 : ProblemBase
{
}

@end





@implementation Problem_43

- (id)solveProblem
{
	for (uint64_t i = 1023456789; i <= 9876543210; i += 1) {
		if (isPandigital(i, 0, 9)) {
//			printf("%llu\n", i);
		}
	}
	
	
	forward_list<uint64_t> digits = getDigits(406);
	
	return @(isPandigital(12403, 0, 4));
}

@end




