// 
//  Problem_148.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_148 : ProblemBase
{
}

@end





@implementation Problem_148

uint64_t changeBase(uint64_t n, uint64_t base)
{
	uint64_t returnVal = 0;
	uint64_t count = 1;
	
	while (n > 0) {
		uint64_t remainder = n % base;
		n = floor(n / base);
		returnVal += remainder * count;
		count *= 10;
	}
	
	return returnVal;
}

#define SOLVE_WITH_MULTITHREADING true

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	
	uint64_t maxRow = pow(10, 9);
	uint64_t base = 7;
	
	
#if SOLVE_WITH_MULTITHREADING == true
	
	auto threads = [[NSProcessInfo processInfo] processorCount];
	maxRow /= threads;
	__block vector<uint64_t> solutions;
	
	for (uint64_t i = 0; i < threads; i += 1) {
		
		dispatch_queue_t queue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0ul);
		dispatch_async(queue, ^{
			
			uint64_t solution = 0;
			
			for (uint64_t row = i * maxRow; row < ((i + 1) * maxRow); row += 1) {
				
				uint64_t _row = row;
				uint64_t digitProduct = 1;
				
				while (_row > 0) {
					uint64_t digit = _row % base;
					digitProduct *= (digit + 1);
					_row /= base;
				}
				
				solution += digitProduct;
				
			}
			
			solutions.push_back(solution);
			
			if (solutions.size() == threads) {
				completion(@(sumOfVector(&solutions)), self.endTime);	// 2129970655314432
			}
			
		});
		
	}
	
#else
	
	uint64_t solution = 0;
	
	for (uint64_t row = 0; row < maxRow; row += 1) {
		
		uint64_t _row = row;
		uint64_t digitProduct = 1;
		
		while (_row > 0) {
			uint64_t digit = _row % base;
			digitProduct *= (digit + 1);
			_row /= base;
		}
		
		solution += digitProduct;
		
	}
	
	completion(@(solution), self.endTime);	// 2129970655314432

	
#endif
	
}

@end




