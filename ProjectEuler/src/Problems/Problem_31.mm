//
//  Problem_31.m
//  projecteuler
//
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
//

#import "ProblemBase.h"





@interface Problem_31 : ProblemBase
{
}

@property (strong, nonatomic) NSArray *coins;

@end





@implementation Problem_31

- (id)solveProblem
{
	NSInteger solutions[201] = { 0 };
	solutions[0] = 1;
 
	for (id coin in self.coins) {
		for (NSInteger j = [coin intValue]; j < 201; j++) {
			solutions[j] += solutions[j - [coin intValue]];
		}
	}
	
	return @(solutions[200]);
}

- (NSArray *)coins
{
	if (!_coins) {
		_coins = @[@(1), @(2), @(5), @(10), @(20), @(50), @(100), @(200)];
	}
	
	return _coins;
}

@end




