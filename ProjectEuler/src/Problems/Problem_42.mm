// 
//  Problem_42.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_42 : ProblemBase
{
}

@end





@implementation Problem_42

- (id)solveProblem
{
	ifstream fileStream = readFile("p042_words.txt");
	
	if (fileStream) {
		
		string word;
		uint64_t triangleWordCount = 0;
		
		while (getline(fileStream, word, ',')) {
			
			if (nForTriangle(wordToNumber(word)) != 0) { // word number is a triangle word
				triangleWordCount++;
			}
			
		}
		
		return @(triangleWordCount);
		
	}
	
	return nil;
}

uint64_t wordToNumber(string w)
{
	uint64_t returnValue = 0;
	
	for (char c : w) {
		
		uint64_t cIndex = toupper(c); // upper case letters 65-90 inclusive
		
		if (cIndex > 64 && cIndex < 91) {
			returnValue += cIndex - 64;
		}
	}
	
	return returnValue;
}

@end




