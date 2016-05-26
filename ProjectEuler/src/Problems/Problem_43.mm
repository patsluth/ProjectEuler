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
	string pandigital = "0123456789";		// First Pandigital 0-9
	uint64_t sum = 0;
	
	while (nextPermutation(pandigital)) {
		if (passesSubstringDivisibilityProperty(pandigital)) {
			sum += stoull(pandigital);
		}
	}
	
	return @(sum);
}

bool passesSubstringDivisibilityProperty(string i)
{
	assert(i.length() == 10);
	
	uint64_t index = 1;
	static uint64_t primes[] = { 2, 3, 5, 7, 11, 13, 17 };
	
	while (index + 2 < i.length())
	{
		string substring = i.substr(index, 3);
		uint64_t primeDivisor = primes[index - 1];
		
		if (stoi(substring) % primeDivisor != 0) {
			return false;
		}
		
		index += 1;
	}
	
	return true;
}

@end




