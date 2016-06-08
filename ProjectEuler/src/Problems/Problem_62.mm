// 
//  Problem_62.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_62 : ProblemBase
{
}

@end





@implementation Problem_62

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	set<uint64_t> cubes;
	
	uint64_t solution = 0;
	
	for (uint64_t i = 1; i < 10000; i += 1) {
		cubes.insert(i * i * i);
//		uint64_t i3 = (i * i * i);
//		printf("%llu\n", i3);
	}
	
	for (auto itr = cubes.rbegin(); itr != cubes.rend(); advance(itr, 1)) {
		
		string cube = to_string(*itr);
		
		vector<string> perms;
		perms.push_back(cube);
		
		while (next_permutation(cube.begin(), cube.end())) {
			
			if (cubes.find(stoull(cube)) != cubes.end()) {
				perms.push_back(cube);
			}
			
			if (perms.size() >= 3) {
				for (auto i : perms) {
					printf("%s\t", i.c_str());
				}
				printf("\n");
			}
			
//			printf("%s\n", cube.c_str());
		}
	}
	
	completion(@(solution), self.endTime);	// 49
}

@end





