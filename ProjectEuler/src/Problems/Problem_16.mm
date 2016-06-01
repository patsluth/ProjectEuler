// 
//  Problem_16.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_16 : ProblemBase
{
}

@end





@implementation Problem_16

- (id)solveProblem
{
	string number = "2";
	bool carryover = false;
	
	for (uint64_t x = 1; x < 1000; x++) {
		
		int64_t digit = number.length() - 1;
		
		while (digit >= 0) {
			
			int64_t digitIndex = digit;
			uint64_t digitValue = stoull(number.substr(digitIndex, 1));
			
			uint64_t product = digitValue * 2;
			
			if (carryover) {
				product++;
				carryover = false;
			}
			
			if (product >= 10) {
				carryover = true;
				product -= 10;
			}
			
			number[digitIndex] = to_string(product)[0];
			
			if (carryover && digitIndex == 0) { // insert new digit
				
				number.insert(number.begin(), '1');
				carryover = false;
				
			}
			
			digit--;
			
		}
		
	}
	
	// add up all digits
	uint64_t sum = 0;
	for (uint64_t digit = 0; digit < number.length(); digit += 1) {
		sum += stoull(number.substr(digit, 1));
	}
	
	return @(sum); // 1366
}

@end




