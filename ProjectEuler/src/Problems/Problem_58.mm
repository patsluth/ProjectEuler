// 
//  Problem_58.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_58 : ProblemBase
{
}

@end





@implementation Problem_58

- (id)solveProblem
{
	uint64_t primeCount = 0;
	uint64_t corner = 1;
	
	for (uint64_t x = 3; ; x += 2) {
		for (uint64_t y = 0; y < 4; y++) { //  calculate each corner
			
			corner += (x - 1);
			
			if (isPrime(corner)) {
				primeCount += 1;
			}
			
		}
		
		uint64_t cornerCount = ((x / 2) * 4) + 1;
		float primeRatio = (float)primeCount / (float)cornerCount;
		
		if (primeRatio <= 0.1) {
			return @(x);
		}
		
	}
	
	return nil;
}

@end




