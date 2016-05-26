// 
//  Problem_99.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_99 : ProblemBase
{
}

typedef vector<uint64_t> baseExponent;

@end





@implementation Problem_99

- (id)solveProblem
{
	ifstream fileStream = readFile("p099_base_exp.txt");
	
	if (fileStream) {
		
		vector<baseExponent> exponents;
		
		string line;
		uint64_t lineNumber = 0;
		
		while (getline(fileStream, line, '\n')) { // iterate file line by line
			
			lineNumber++;
			
			istringstream buf(line);
			istream_iterator<uint64_t> beg(buf), end;
			
			baseExponent be(beg, end);
			be.insert(be.begin() + 1, lineNumber); // line number stored in center index
			exponents.push_back(be);
			
		}
		
		while (exponents.size() > 1) {
			
			baseExponent be1 = exponents.back();
			exponents.pop_back();
			baseExponent be2 = exponents.back();
			exponents.pop_back();
			
			exponents.push_back(largerExponent(be1, be2));
		}
		
		return @(exponents.front()[1]); // line number stored in center index
		
	}
	
	return nil;
}

/**
 *  Calculates and returns the larger exponent
 *  using logarithm change of base formula and comparing the exponents
 *
 *  @param be1
 *  @param be2
 *
 *  @return baseExponent
 */
baseExponent largerExponent(baseExponent be1, baseExponent be2)
{
	// The value that be2's base must be raised to (exponent) to have the same base as be1
	float be2_changeOfBaseExponent = log(be1.front()) / log(be2.front());
	be2_changeOfBaseExponent *= be1.back();
	
	if (be2.back() > be2_changeOfBaseExponent) { // If be2's original exponent is larger than the change of base, then be2 is larger
		return be2;
	} else {
		return be1;
	}
}

@end





