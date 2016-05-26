// 
//  Problem_37.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_37 : ProblemBase
{
}

@end





@implementation Problem_37

- (id)solveProblem
{
	uint64_t sum = 0;
	uint64_t count = 0;
	
	for (uint64_t x = 11; count < 11 ; x++) { // 1 - 7 dont count
		
		if (truncatablePrimeLeft(x) && truncatablePrimeRight(x)) {
			count++;
			sum += x;
		}
		
	}
	
	return @(sum);
}

bool truncatablePrimeLeft(uint64_t i)
{
	uint64_t iCopy = i;
	uint64_t digits = numberOfDigits(i);
	
	while (digits > 0) {
		
		if (!isPrime(iCopy)) {
			return false;
		}
		
		digits--;
		iCopy = iCopy % (int)pow(10, digits);
		
	}
	
	return true;
}

bool truncatablePrimeRight(uint64_t i)
{
	uint64_t iCopy = i;
	
	while (iCopy > 0) {
		
		if (!isPrime(iCopy)) {
			return false;
		}
		
		iCopy /= 10;
		
	}
	
	return true;
}

@end




