//
//  Problem_543.m
//  ProjectEuler
//
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
//

#import "ProblemBase.h"

#import "primes.h"





@interface Problem_543 : ProblemBase
{
}

@end





@implementation Problem_543

- (id)solveProblem
{
	printf("***%llu***\n", P(10, 2));
	
	return nil;
}

uint64_t P(uint64_t n, uint64_t k)
{
//	printf("%llu %llu\n", n, k);
//	
//	if (n <= 0) {
//		
//		return 0;
//		
//	} else if (k == 1) {
//		
//		if (primes::sharedPrimes()->isPrime(n) == true) {
//			return 1;
//		} else {
//			return 0;
//		}
//		
//	} else {
//		
//		set<uint64_t> &millionPrimes = primes::sharedPrimes()->loadPrimes(1); // 1st million primes
//		auto itr = millionPrimes.begin();
//		
//		while (itr != millionPrimes.end()) {
//			
//			if (*itr < n) {
//				if (P(n - *itr, k - 1) == 1) {
//					break;
//				} else {
//					return 0;
//				}
//			} else {
//				break;
//			}
//			
//			advance(itr, 1);
//			
//		}
//		
//	}
	
	return 1;
}

@end





