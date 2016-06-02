// 
//  Problem_75.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_75 : ProblemBase
{
}

@end





@implementation Problem_75

- (id)solveProblem
{
	uint64_t maxP = 1500000;
	uint64_t count = 0;
	uint64_t *triangles = new uint64_t[maxP + 1];
	
	for (uint64_t m = 2; m < sqrt(maxP / 2); m += 1) {
		for (uint64_t n = 1; n < m; n += 1) {
			
			if ((m + n) % 2 != 0 && gcd(m, n) == 1) {
				
				uint64_t a = (m * m) - (n * n);
				uint64_t b = 2 * m * n;
				uint64_t c = (m * m) + (n * n);
				uint64_t p = a + b + c;
				
				while (p <= maxP) {
					
					triangles[p] += 1;
					
					if (triangles[p] == 1) {
						count += 1;
					}
					if (triangles[p] == 2) {
						count -= 1;
					}
					
					p += (a + b + c);
				}
				
			}
			
		}
	}
	
	delete [] triangles;
	
	return @(count);
}

uint64_t integerRightTriangleCombinationsForPerimeter(uint64_t p)
{
	uint64_t count = 0;
	
	
	
	
	
	
//	for (uint64_t c = (p / 3); c < (p / 2); c += 1) {
//		for (uint64_t a = 1; a < c; a += 1) {
//			uint64_t b = p - c - a;
//			
//			if (a > b) {
//				break;
//			} else if (sqrt((a * a) + (b * b)) == c) {
////				printf("%llu -> %llu %llu %llu\n" , p, a, b, c);
//				count += 1;
//			}
//			
//		}
//	}
	
	return count;
}

@end





