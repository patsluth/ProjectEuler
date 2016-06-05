// 
//  Problem_33.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_33 : ProblemBase
{
}

@end





@implementation Problem_33

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	pair<uint64_t, uint64_t> fractionProduct = { 1, 1 };
	
	for (uint64_t denomenator = 11; denomenator <= 99; denomenator += 1) {
		for (uint64_t numerator = 11; numerator < denomenator; numerator += 1) {
			if (p33Condition(numerator, denomenator)) {
				
				fractionProduct = {
					fractionProduct.first * numerator,
					fractionProduct.second * denomenator
				};
				
			}
		}
	}
	
	fractionProduct = reduceFraction2(fractionProduct.first, fractionProduct.second);
	
	completion(@(fractionProduct.second), self.endTime);	// 100
}

/**
 *  Problem 33 - create new fraction, f2 by removing similar digits from f1
 *					if f1 == f2 then f2 passes this test
 *
 *  @param numerator
 *  @param denomenator
 *
 *  @return bool
 */
bool p33Condition(uint64_t numerator, uint64_t denomenator)
{
	string nDigits = to_string(numerator);
	string dDigits = to_string(denomenator);
	
	for (auto n = nDigits.begin(); n != nDigits.end(); advance(n, 1)) {
		if (*n != '0') {
			
			auto dIndex = dDigits.find(*n);
			
			if (dIndex != string::npos) {
				
				nDigits.erase(n);
				dDigits.replace(dIndex, 1, "");
				
				reduceFraction(numerator, denomenator);
				auto f = reduceFraction2(stoull(nDigits), stoull(dDigits));
				
				if (numerator == f.first && denomenator == f.second) {
					return true;
				} else {
					return false;
				}
				
			}
			
		}
	}
	
	return false;
}

@end




