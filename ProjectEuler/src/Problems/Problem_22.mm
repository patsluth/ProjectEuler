//
//  Problem_22.m
//  ProjectEuler
//
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
//

#import "ProblemBase.h"





@interface Problem_22 : ProblemBase
{
}

@end





@implementation Problem_22

- (id)solveProblem
{
	ifstream fileStream = readFile("p022_names.txt");
	uint64_t sumOfNameScores = 0; // return value
	
	if (fileStream) {
		
		set<string> *names = new set<string>(); // sort alphabetically
		
		string line;
		while (getline(fileStream, line, '\n')) { // iterate over each line
			names->insert(line);
		}
		
		uint64_t lineNumber = 0;
		
		for (string name : *names) {
			sumOfNameScores += nameScore(&name, ++lineNumber);
		}
		
		names->clear();
		delete names;
		
	}
	
	fileStream.clear();
	fileStream.close();
	
	return @(sumOfNameScores);
}

/**
 *  The sum of the integer value of each letter in the name * the lineNumber
 *  Ex
 *  COLIN 3 + 15 + 12 + 9 + 14 = 53
 *  lineNumber = 938
 *  COLIN * lineNumber = 49714
 *
 *  @param s
 *
 *  @return stringScore
 */
uint64_t nameScore(const string *name, uint64_t lineNumber)
{
	uint64_t letterSum = 0;
	
	for (char letter : *name) {
		letterSum += (toupper(letter) - 65 + 1); // ASCII consonant's start at 65. +1 since A = 0
	}
	
	return letterSum * lineNumber;
}

@end




