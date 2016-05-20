//
//  Problem_30.m
//  ProjectEuler
//
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
//

#import "ProblemBase.h"





@interface Problem_30 : ProblemBase
{
}

@end





@implementation Problem_30

- (id)solveProblem
{
	uint64_t result = 0;
	
	for (uint64_t x = 0; x < 1000000; x++) {
		if ([self intEqualsSumItsOfDigits:x toPower:5]) {
			result += x;
		}
	}
	
	return @(result);

}

/**
 *  If the sum of each digit of i to the power supplied equals i
 *  return true
 *
 *  @param i     base
 *  @param power exponent
 *
 *  @return bool
 */
- (bool)intEqualsSumItsOfDigits:(uint64_t)i toPower:(uint64_t)power
{
	if (i == 0 || i == 1) {
		return false;
	}
	
	uint64_t iCopy = i;
	uint64_t sumOfDigitsPower = 0;
	
	while (iCopy > 0) {
		
		uint64_t digit = iCopy % 10;
		
		sumOfDigitsPower += powl(digit, power);
		
		iCopy /= 10;
		
	}
	
	return (sumOfDigitsPower == i);
}

@end




