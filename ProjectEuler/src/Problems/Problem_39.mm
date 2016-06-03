// 
//  Problem_39.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_39 : ProblemBase
{
}

@end





@implementation Problem_39

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	pair<uint64_t, uint64_t> maxSolutions = { 0, 0 }; // first = # of solutions, second = p
	
	for (uint64_t p = 1; p <= 1000; p += 1) { // try all p
		
		uint64_t numberOfSolutions = 0;
		
		for (uint64_t a = 1; a <= (p / 2); a += 1) {
			for (uint64_t b = a; b <= (p / 2); b += 1) {
				
				double c = sqrt((a * a) + (b * b));
				
				if (fmod(c, (uint64_t)c) == 0.0) { // make sure c is a whole number
					
					if ((uint64_t)(c) + a + b == p) { // make sure perimeter is correct
						
						double angle1 = atan((double)a / (double)b);
						double angle2 = atan((double)b / (double)a);
						
						if ((angle1 + angle2) == M_PI_2) { // right triangle
							numberOfSolutions += 1;
						}
						
					}
					
				}
				
			}
		}
		
		if (numberOfSolutions > maxSolutions.first) {
			maxSolutions.first = numberOfSolutions;
			maxSolutions.second = p;
		}
		
	}
	
	completion(@(maxSolutions.second), self.endTime);	// 840
}

@end




