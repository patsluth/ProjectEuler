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





ProblemBase *getProblem(NSUInteger index)
{
	ProblemBase *problem = nil;
	Class problemClass = NSClassFromString([NSString stringWithFormat:@"Problem_%lu", index]);
	
	if (problemClass && [problemClass isSubclassOfClass:[ProblemBase class]]) {
		problem = [[problemClass alloc] init];
	}
	
	return problem;
}



void runProblem(ProblemBase *problem)
{
	if (problem) {
		
		CGFloat startTime = CACurrentMediaTime();
		id solution = [problem solveProblem];
		CGFloat endTime = CACurrentMediaTime() - startTime;
		
		NSString *output = [NSString stringWithFormat:@"%@:\t\t%@\t\t%.2fs\n", NSStringFromClass([problem class]), solution, endTime];
		printf("%s", output.UTF8String);
		
	}
}

int main(int argc, const char * argv[])
{
	@autoreleasepool {
		
		printf("\nProject Euler - Pat Sluth\n\n");
		
		printf("************************************\n");
		printf("[#]:\t\trun problem #\n");
		printf("[a]:\t\trun all problems\n");
		printf("[?]:\t\tlist problems\n");
		printf("[q]:\t\tquit\n");
		printf("************************************\n");
		
		while (true) {
			
			printf("\nEnter Option:");
			
			NSInteger inputInt = 0;
			char inputChar;
			
			if (scanf("%ld", &inputInt) == 1) { // Number
				
				runProblem(getProblem(inputInt));
				
			} else if (scanf("%s", &inputChar) == 1) {
				
				
				if (inputChar == 'a') {
					
					for (NSUInteger x = 1; x < 600; x++) {
						runProblem(getProblem(x));
					}
					
				} else if (inputChar == '?') {
					
					for (NSUInteger x = 1; x < 600; x++) {
						ProblemBase *problem = getProblem(x);
						if (problem) {
							printf("%s", NSStringFromClass([problem class]).UTF8String);
							printf("\n");
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
		
		printf("\nGoodbye\n");
	
	}
	
    return 0;
}
				




