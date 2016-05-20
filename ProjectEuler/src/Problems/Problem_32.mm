//
//  Problem_32.m
//  ProjectEuler
//
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
//

#import "ProblemBase.h"





@interface Problem_32 : ProblemBase
{
}

@end





@implementation Problem_32

- (id)solveProblem
{
	set<uint64_t> *products = new set<uint64_t>();;
	
	for (uint64_t x = 1; x < 10000; x++) {
		for (uint64_t y = 1; y < 10000; y++) {
			
			uint64_t concat = concatanate(x, y);
			uint64_t product = x * y;
			concat = concatanate(concat, product);
			
			if (concat > 987654321) { // largest possible 9 digit pandigital number
				break;
			}
			
			if (isPandigital(concat, 9) == true){
				
				products->insert(product);
				
			}
			
		}
		
	}
	
	id returnValue = @(sumOfSet(products));
	
	products->clear();
	delete products;

	return returnValue;
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




