// 
//  sudoku.h
//  ProjectEuler
// 
//  Created by Pat Sluth on 2015-11-20.
//  Copyright © 2015 Pat Sluth. All rights reserved.
// 

#ifndef sudoku_h
#define sudoku_h

#import <CoreGraphics/CoreGraphics.h>

#import "libProjectEuler.h"





using namespace std;

typedef vector<string> sudokuPuzzle;





class sudoku
{
	
public:
	
	static const char *toString(sudokuPuzzle &puzzle)
	{
		NSMutableString *returnVal = [NSMutableString new];
		
		for (auto &row : puzzle) {
			for (char c : row) {
				[returnVal appendString:[NSString stringWithFormat:@"%c", c == '0' ? '_' : c]];
			}
			[returnVal appendString:@"\n"];
		}
		
		[returnVal appendString:@"\n"];
		
		return returnVal.UTF8String;
	}
	
	static bool isSolved(sudokuPuzzle &puzzle)
	{
		for (uint64_t i = 0; i < 9; i += 1) {
			if (!sudoku::rowIsValid(puzzle, i)) {
				return false;
			}
			if (!sudoku::columnIsValid(puzzle, i)) {
				return false;
			}
		}
		for (uint64_t x = 0; x < 3; x += 1) {
			for (uint64_t y = 0; y < 3; y += 1) {
				if (!sudoku::blockIsValid(puzzle, x, y)) {
					return false;
				}
			}
		}
		
		return true;
	}
	
	static string *getRow(sudokuPuzzle &puzzle, uint64_t y)
	{
		return &puzzle[y];
	}
	
	static string getColumn(sudokuPuzzle &puzzle, uint64_t x)
	{
		string column = "";
		
		for (auto &row : puzzle) {
			column += row[x];
		}
		
		return column;
	}
	
	static string getBlock(sudokuPuzzle &puzzle, uint64_t x, uint64_t y)
	{
		string block = "";
		
		y *= 3;
		
		while (block.length() < 9) {
			
			string &row = *sudoku::getRow(puzzle, y);
			block += row.substr(x * 3, 3);
			
			y += 1;
			
		}
		
		return block;
	}
	
	static bool rowIsValid(sudokuPuzzle &puzzle, uint64_t y)
	{
		string &row = *sudoku::getRow(puzzle, y);
		return isPandigital(stoull(row), 1, 9);
	}
	
	static bool columnIsValid(sudokuPuzzle &puzzle, uint64_t x)
	{
		string col = sudoku::getColumn(puzzle, x);
		return isPandigital(stoull(col), 1, 9);
	}
	
	static bool blockIsValid(sudokuPuzzle &puzzle, uint64_t x, uint64_t y)
	{
		if (x > 2 || y > 2) {
			return false;
		}
		
		string block = sudoku::getBlock(puzzle, x, y);
		return isPandigital(stoull(block), 1, 9);
	}
	
	static bool rowContainsValue(sudokuPuzzle &puzzle, uint64_t y, char value)
	{
		string &row = *sudoku::getRow(puzzle, y);
		return (row.find(value) != string::npos);
	}
	
	static bool columnContainsValue(sudokuPuzzle &puzzle, uint64_t x, char value)
	{
		string column = sudoku::getColumn(puzzle, x);
		return (column.find(value) != string::npos);
	}
	
	static bool blockContainsValue(sudokuPuzzle &puzzle, uint64_t x, uint64_t y, char value)
	{
		string block = sudoku::getBlock(puzzle, x, y);
		return (block.find(value) != string::npos);
	}
	
	static CGPoint getNextAvailableSquare(sudokuPuzzle &puzzle)
	{
		for (uint64_t y = 0; y < puzzle.size(); y += 1) {
			
			string &row = *sudoku::getRow(puzzle, y);
			
			for (uint64_t x = 0; x < row.length(); x += 1) {
				if (row[x] == '0') {
					return CGPointMake(x, y);
				}
			}
			
		}
		
		return CGPointZero;
	}
	
	static bool solve(sudokuPuzzle &puzzle)
	{
		if (sudoku::isSolved(puzzle)) {
			return true;
		}
		
		auto emptySquare = sudoku::getNextAvailableSquare(puzzle);
		
		if (puzzle[emptySquare.y][emptySquare.x] == '0') {
			
			for (char i = '1'; i <= '9'; i += 1) {
				
				if (!sudoku::rowContainsValue(puzzle, emptySquare.y, i) &&
					!sudoku::columnContainsValue(puzzle, emptySquare.x, i) &&
					!sudoku::blockContainsValue(puzzle, emptySquare.x / 3, emptySquare.y / 3, i)) {
					
					puzzle[emptySquare.y][emptySquare.x] = i;
					
					if (sudoku::solve(puzzle)) {
						return true;
					}
					
					puzzle[emptySquare.y][emptySquare.x] = '0';
					
				}
				
			}
			
			return false;
			
		}
		
		return false;
	}
	
	
};





#endif /* sudoku_h */




