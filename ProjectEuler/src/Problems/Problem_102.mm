// 
//  Problem_102.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"

#import <GLKit/GLKit.h>





@interface Problem_102 : ProblemBase
{
}

struct Triangle_102
{
	GLKVector3 a;
	GLKVector3 b;
	GLKVector3 c;
};

@end





@implementation Problem_102

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	NSString *file = [NSString stringWithContentsOfFile:@"p102_triangles.txt" encoding:NSUTF8StringEncoding error:nil];
	GLKVector3 pZero = GLKVector3Make(0.0, 0.0, 0.0);
	uint64_t solution = 0;
	
	if (file) {
		
		NSArray<NSString *> *triangles = [file componentsSeparatedByString:@"\n"];
		
		for (NSString *triangle in triangles) {
			
			NSArray<NSString *> *points = [triangle componentsSeparatedByString:@","];
			
			GLKVector3 a = GLKVector3Make([points[0] integerValue], [points[1] integerValue], 0.0);
			GLKVector3 b = GLKVector3Make([points[2] integerValue], [points[3] integerValue], 0.0);
			GLKVector3 c = GLKVector3Make([points[4] integerValue], [points[5] integerValue], 0.0);
			
			if ([self triangle:{ a, b, c } containsPoint:pZero]) {
				solution += 1;
			}
			
		}
		
	}
	
	completion(@(solution), self.endTime); // ???
}

- (bool)triangle:(Triangle_102)t containsPoint:(GLKVector3)p
{
	GLKVector3 ab = GLKVector3CrossProduct(GLKVector3Subtract(p, t.a), GLKVector3Subtract(t.a, t.b));
	GLKVector3 bc = GLKVector3CrossProduct(GLKVector3Subtract(p, t.b), GLKVector3Subtract(t.b, t.c));
	GLKVector3 ca = GLKVector3CrossProduct(GLKVector3Subtract(p, t.c), GLKVector3Subtract(t.c, t.a));
	
	if ((ab.z >= 0.0 && bc.z >= 0.0 && ca.z >= 0.0) ||
		(ab.z < 0.0 && bc.z < 0.0 && ca.z < 0.0)) {
		return true;
	}
	
	return false;
}

@end





