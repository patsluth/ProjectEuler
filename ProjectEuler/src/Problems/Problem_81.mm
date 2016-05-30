// 
//  Problem_81.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"





@interface Problem_81 : ProblemBase
{
}

@end





@implementation Problem_81

- (id)solveProblem
{
	ifstream fileStream = readFile("p081_matrix.txt");
	
	if (fileStream) {
		
		vector<vector<uint64_t>> matrix;
		
		string line;
		
		while (getline(fileStream, line, '\n')) { // iterate each line
			
			istringstream buf(line);
			istream_iterator<uint64_t> beg(buf), end;
			vector<uint64_t> row(beg, end);
			
			matrix.push_back(row);
			
		}
		
		for (auto row : matrix) { // make sure its a square
			assert(matrix.size() == row.size());
		}
		
		
		for (int64_t x = matrix.size() - 2; x >= 0; x--) {
			matrix[matrix.size() - 1][x] += matrix[matrix.size() - 1][x + 1];
			matrix[x][matrix.size() - 1] += matrix[x + 1][matrix.size() - 1];
		}
		
		for (int64_t x = matrix.size() - 2; x >= 0; x--) {
			for (int64_t y = matrix.size() - 2; y >= 0; y--) {
				matrix[x][y] += MIN(matrix[x + 1][y], matrix[x][y + 1]);
			}
		}
		
		
		return @(matrix[0][0]);
		
	}
	
	return nil;
}

@end





