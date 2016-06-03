// 
//  ProblemBase.h
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import <Foundation/Foundation.h>
#import <QuartzCore/QuartzCore.h>

#import "libProjectEuler.h"





@interface ProblemBase : NSObject
{
}

typedef void (^solutionBlock)(id problemSolution, CGFloat problemDuration);

- (void)solveProblem:(solutionBlock)completion;

@property (nonatomic, readonly) CGFloat endTime;

- (void)tdd;

@end




