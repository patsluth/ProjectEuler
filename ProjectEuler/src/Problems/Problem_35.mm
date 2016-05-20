//
//  Problem_35.m
//  ProjectEuler
//
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
//

#import "ProblemBase.h"





@interface Problem_35 : ProblemBase
{
}

@end





@implementation Problem_35

- (id)solveProblem
{
	uint64_t primeCount = 0;
	
	for (uint64_t x = 1; x < 1000000; x++) {
		
		vector<uint64_t> circularValueVariations = circularVariations(x);
		bool allCircularVariationsPrime = true;
		
		for (uint64_t cur : circularValueVariations) {
			if (allCircularVariationsPrime == true) {
				allCircularVariationsPrime = isPrime(cur);
			}
		}
		
		if (allCircularVariationsPrime) {
			primeCount++;
		}
		
	}
	
	return @(primeCount);
}

@end




