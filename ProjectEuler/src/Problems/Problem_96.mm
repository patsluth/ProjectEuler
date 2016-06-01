// 
//  Problem_96.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"

#import <CoreGraphics/CoreGraphics.h>

typedef vector<string> sudokuPuzzle;





@interface Problem_96 : ProblemBase
{
}

@end





@implementation Problem_96

- (id)solveProblem
{
	test();
	
	ifstream fileStream = readFile("p096_sudoku.txt");
	
	if (fileStream) {
		
		sudokuPuzzle currentPuzzle;
		uint64_t solution = 0;		// Sum of 3 numbers in the top left corner of each solved puzzle
		
		string line;
		while (getline(fileStream, line, '\n')) { // iterate each line
			if (line.length() == 9 && line.substr(0, 4) != "Grid") {
				
				currentPuzzle.push_back(line);
				
				if (currentPuzzle.size() == 9) {									// Complete puzzle
					
					if (sudokuSolvePuzzle(currentPuzzle)) {
						solution += stoull(currentPuzzle[0].substr(0, 3));			// 3 digit number in top left corner of solved puzzle
					}
					
					currentPuzzle.clear();											// Start new puzzle
				}
				
			}
		}
		
		return @(solution);
		
	}
	
	return nil;
}

void test()
{
	sudokuPuzzle puzzle = {
		"003020600",
		"900305001",
		"001806400",
		"008102900",
		"700000008",
		"006708200",
		"002609500",
		"800203009",
		"005010300",
	};
	
	sudokuPuzzle puzzleSolved = { // a solved puzzle
		"483921657",
		"967345821",
		"251876493",
		"548132976",
		"729564138",
		"136798245",
		"372689514",
		"814253769",
		"695417382",
	};
	
	assert(sudokuPuzzleIsValid(puzzleSolved));
	
	sudokuSolvePuzzle(puzzle);
	assert(sudokuPuzzleIsValid(puzzle));
}

void sudokuPrint(sudokuPuzzle &puzzle)
{
	for (auto &row : puzzle) {
		for (char c : row) {
			printf("%c", c == '0' ? '_' : c);
		}
		printf("\n");
	}
	printf("\n\n");
}

bool sudokuPuzzleIsValid(sudokuPuzzle &puzzle)
{
	for (uint64_t i = 0; i < 9; i += 1) {
		if (!sudokuRowIsValid(puzzle, i)) {
			return false;
		}
		if (!sudokuColumnIsValid(puzzle, i)) {
			return false;
		}
	}
	for (uint64_t x = 0; x < 3; x += 1) {
		for (uint64_t y = 0; y < 3; y += 1) {
			if (!sudokuBlockIsValid(puzzle, x, y)) {
				return false;
			}
		}
	}
	
	return true;
}

bool sudokuRowIsValid(sudokuPuzzle &puzzle, uint64_t y)
{
	return isPandigital(stoull(puzzle[y]), 1, 9);
}

bool sudokuColumnIsValid(sudokuPuzzle &puzzle, uint64_t x)
{
	return isPandigital(stoull(sudokuGetColumn(puzzle, x)), 1, 9);
}

// 3x3 block
bool sudokuBlockIsValid(sudokuPuzzle &puzzle, uint64_t x, uint64_t y)
{
	if (x > 2 || y > 2) {
		return false;
	}
	
	return isPandigital(stoull(sudokuGetBlock(puzzle, x, y)), 1, 9);
}

string sudokuGetColumn(sudokuPuzzle &puzzle, uint64_t x)
{
	string column = "";
	
	for (auto &row : puzzle) {
		column += row[x];
	}
	
	return column;
}

// 3x3 block
string sudokuGetBlock(sudokuPuzzle &puzzle, uint64_t x, uint64_t y)
{
	string block = "";
	
	y *= 3;
	
	while (block.length() < 9) {
		
		string &row = puzzle[y];
		block += row.substr(x * 3, 3);
		
		y += 1;
	}
	
	return block;
}

bool sudokuRowContainsValue(sudokuPuzzle &puzzle, uint64_t y, char value)
{
	return (puzzle[y].find(value) != string::npos);
}

bool sudokuColumnContainsValue(sudokuPuzzle &puzzle, uint64_t x, char value)
{
	string column = sudokuGetColumn(puzzle, x);
	return (column.find(value) != string::npos);
}

bool sudokuBlockContainsValue(sudokuPuzzle &puzzle, uint64_t x, uint64_t y, char value)
{
	string block = sudokuGetBlock(puzzle, x, y);
	return (block.find(value) != string::npos);
}

/**
 *  Get (x, y) pair of next empty square starting from origin
 *
 *  @param puzzle
 *
 *  @return CGPoint
 */
CGPoint sudokuGetNextEmptySquare(sudokuPuzzle &puzzle)
{
	for (uint64_t y = 0; y < puzzle.size(); y += 1) {
		auto row = puzzle[y];
		for (uint64_t x = 0; x < row.length(); x += 1) {
			if (row[x] == '0') {
				return CGPointMake(x, y);
			}
		}
	}
	
	return CGPointZero;
}

bool sudokuSolvePuzzle(sudokuPuzzle &puzzle)
{
	if (sudokuPuzzleIsValid(puzzle)) {
		return true;
	}
	
	auto emptySquare = sudokuGetNextEmptySquare(puzzle);
	
	if (puzzle[emptySquare.y][emptySquare.x] == '0') {
		
		for (char i = '1'; i <= '9'; i += 1) {
			
			if (!sudokuRowContainsValue(puzzle, emptySquare.y, i) &&
				!sudokuColumnContainsValue(puzzle, emptySquare.x, i) &&
				!sudokuBlockContainsValue(puzzle, emptySquare.x / 3, emptySquare.y / 3, i)) {
				
				puzzle[emptySquare.y][emptySquare.x] = i;
				
				if (sudokuSolvePuzzle(puzzle)) {
					return true;
				}
				
				puzzle[emptySquare.y][emptySquare.x] = '0';

			}
			
		}
		
		return false;
		
	}
	
	return false;
}

@end





