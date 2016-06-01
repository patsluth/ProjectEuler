// 
//  Problem_55.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_55 : ProblemBase
{
}

@end





@implementation Problem_55

- (id)solveProblem
{
	uint64_t solution = 0;
	
	for (uint64_t i = 1; i < 10000; i += 1) {
		if (isLychrel(i)) {
			solution += 1;
		}
	}
	
	return @(solution);
}

bool isLychrel(uint64_t n)
{
	cpp_int _n(n);
	
	for (uint64_t j = 0; j < 50; j += 1) {
		
		string reverseN(_n.str());
		reverse(begin(reverseN), end(reverseN));
		while (reverseN[0] == '0') {
			reverseN = reverseN.substr(1, reverseN.length() - 1);
		}
		
		_n += cpp_int(reverseN);
		
		if (isPalindrome(_n.str())) {
			return false;
		}
		
	}
	
	return true;
}

@end





