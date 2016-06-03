// 
//  Problem_19.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_19 : ProblemBase
{
}

@end





@implementation Problem_19

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	uint64_t sundaysOnFirstDayOfMonth = 0;
	
	NSDateComponents *startDateComponents = [NSDateComponents new];
	startDateComponents.day = 1;
	startDateComponents.month = 1;
	startDateComponents.year = 1901;
	NSDateComponents *endDateComponents = [NSDateComponents new];
	endDateComponents.day = 1;
	endDateComponents.month = 12;
	endDateComponents.year = 2000;
	
	NSDate *startDate = [[NSCalendar currentCalendar] dateFromComponents:startDateComponents];
	NSDate *endDate = [[NSCalendar currentCalendar] dateFromComponents:endDateComponents];
	
	
	while ([startDate compare:endDate] < 1) {
		
		NSDateComponents *components = [[NSCalendar currentCalendar] components:NSCalendarUnitDay | NSCalendarUnitWeekday fromDate:startDate];
		
		if (components.day == 1 && components.weekday == 1) {
			sundaysOnFirstDayOfMonth += 1;
		}
		
		startDate = [[NSCalendar currentCalendar] dateByAddingUnit:NSCalendarUnitMonth value:1 toDate:startDate options:NSCalendarMatchNextTime];
		
	}
	
	completion(@(sundaysOnFirstDayOfMonth), self.endTime);	// 171
}

@end




