// 
//  Problem_89.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_89 : ProblemBase
{
}

@end





@implementation Problem_89

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	completion([self solveProblem], self.endTime);	// 743
}

- (id)solveProblem
{
	ifstream fileStream = readFile("p089_roman.txt");
	
	if (fileStream) {
		
		uint64_t preCharCount = 0;
		uint64_t postCharCount = 0;
		
		string line;
		while (getline(fileStream, line, '\n')) { // iterate each line
			
			NSString *romanNumeral = [NSString stringWithUTF8String:line.c_str()];
			
			preCharCount += romanNumeral.length;
			
			romanNumeral = [romanNumeral stringByReplacingOccurrencesOfString:@"DCCCC" withString:@"CM"];
			romanNumeral = [romanNumeral stringByReplacingOccurrencesOfString:@"LXXXX" withString:@"XC"];
			romanNumeral = [romanNumeral stringByReplacingOccurrencesOfString:@"VIIII" withString:@"IX"];
			romanNumeral = [romanNumeral stringByReplacingOccurrencesOfString:@"CCCC" withString:@"CD"];
			romanNumeral = [romanNumeral stringByReplacingOccurrencesOfString:@"XXXX" withString:@"XL"];
			romanNumeral = [romanNumeral stringByReplacingOccurrencesOfString:@"IIII" withString:@"IV"];
			
			postCharCount += romanNumeral.length;
			
		}
		
		return @(preCharCount - postCharCount);
		
	}
	
	return nil;
}

uint64_t valueForRomanNumeral(NSString *n)
{
	uint64_t value = 0;
	
	for (uint64_t i = 0; i < n.length; i += 1) {
		char digit = [n characterAtIndex:i];
		char nextDigit = 'o';
		
		if (i + 1 < n.length) {
			nextDigit = [n characterAtIndex:i + 1];
		}
		
		if (isValidRomanNumeralSubtractivePair({ digit, nextDigit })) {
			value += valueForRomanNumeralSubtractivePair({ digit, nextDigit });
			i += 1;
		} else {
			value += valueForRomanNumeralCharacter(digit);
		}
	}
	
	return value;
}

uint64_t valueForRomanNumeralCharacter(char c)
{
	switch (toupper(c)) {
			
		case 'I':
			return 1;
			break;
			
		case 'V':
			return 5;
			break;
			
		case 'X':
			return 10;
			break;
			
		case 'L':
			return 50;
			break;
			
		case 'C':
			return 100;
			break;
			
		case 'D':
			return 500;
			break;
			
		case 'M':
			return 1000;
			break;
			
		default:
			return 0;
			break;
			
	}
}

bool isValidRomanNumeralSubtractivePair(pair<char, char> p)
{
//	p.first = toupper(p.first);
//	p.second = toupper(p.second);
	
	if (valueForRomanNumeralCharacter(p.first) < valueForRomanNumeralCharacter(p.second)) {
		if (p.first == 'I' && (p.second == 'V' || p.second == 'X')) {
			return true;
		} else if (p.first == 'X' && (p.second == 'L' || p.second == 'C')) {
			return true;
		} else if (p.first == 'C' && (p.second == 'D' || p.second == 'M')) {
			return true;
		}
	}
	
	return false;
}

uint64_t valueForRomanNumeralSubtractivePair(pair<char, char> p)
{
	return valueForRomanNumeralCharacter(p.second) - valueForRomanNumeralCharacter(p.first);
}

@end





