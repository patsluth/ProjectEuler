// 
//  main.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import <Foundation/Foundation.h>
#import <QuartzCore/QuartzCore.h>

#import "ProblemBase.h"

static ProblemBase *currentProblem = nil;





ProblemBase *getProblem(NSUInteger index)
{
	ProblemBase *problem = nil;
	Class problemClass = NSClassFromString([NSString stringWithFormat:@"Problem_%lu", index]);
	
	if (problemClass && [problemClass isSubclassOfClass:[ProblemBase class]]) {
		problem = [[problemClass alloc] init];
	}
	
	return problem;
}

bool runProblem(ProblemBase *problem)
{
	currentProblem = problem;
	
	if (problem) {
		
		printf("\n%s ...\n", NSStringFromClass([problem class]).UTF8String);
		
		[problem solveProblem:^(id problemSolution, CGFloat problemDuration) {
			printf("%s", [NSString stringWithFormat:@"%@\n%.2fs\n\n", problemSolution, problemDuration].UTF8String);
			currentProblem = nil;
		}];
		
	}
	
	return (problem != nil);
}

int main(int argc, const char * argv[])
{
	@autoreleasepool {
		
		printf("\nProject Euler - Pat Sluth\n\n");
		
		printf("************************************\n");
		printf("[#]:\t\trun problem #\n");
		printf("[a]:\t\trun all problems\n");
		printf("[l]:\t\trun most recently ran problem #\n");
		printf("[?]:\t\tlist problems\n");
		printf("[q]:\t\tquit\n");
		printf("************************************\n\n");
		
		while (true) {
			if (!currentProblem) {
				
				printf("Enter Option:");
				
				NSInteger inputInt = 0;
				char inputChar;
				
				if (scanf("%ld", &inputInt) == 1) { // Number
					
					if (runProblem(getProblem(inputInt))) {
						[[NSUserDefaults standardUserDefaults] setInteger:inputInt forKey:@"patsluth.ProjectEuler.MostRecentlyRanProblem"];
					}
					
				} else if (scanf("%s", &inputChar) == 1) {
					
					if (inputChar == 'a') {
						
						for (NSUInteger x = 1; x < 600; x += 1) {
							runProblem(getProblem(x));
						}
						
					} else if (inputChar == 'l') {
						
						if (!runProblem(getProblem([[NSUserDefaults standardUserDefaults] integerForKey:@"patsluth.ProjectEuler.MostRecentlyRanProblem"]))) {
						}
						
					} else if (inputChar == '?') {
						
						for (NSUInteger x = 1; x < 600; x += 1) {
							ProblemBase *problem = getProblem(x);
							if (problem) {
								printf("%s\n", NSStringFromClass([problem class]).UTF8String);
							}
						}
						
					} else if (inputChar == 'q') {
						
						break;
						
					} else {
						
						printf("Invalid Input!\n");
						
					}
					
					
				} else {
					
					printf("Invalid Input!\n");
					
				}
				
			}
		}
		
		printf("\nGoodbye\n");
	
	}
	
    return 0;
}
				




