// 
//  Problem_96.m
//  ProjectEuler
// 
//  Created by Pat Sluth on 2016-04-21.
//  Copyright © 2016 Pat Sluth. All rights reserved.
// 

#import "ProblemBase.h"

#import "sudoku.h"





@interface Problem_96 : ProblemBase
{
}

@end





@implementation Problem_96

- (void)solveProblem:(solutionBlock)completion
{
	[super solveProblem:completion];
	
	ifstream fileStream = readFile("p096_sudoku.txt");
	
	if (fileStream) {
		
		sudokuPuzzle currentPuzzle;
		__block vector<uint64_t> solutions;				// Sum of 3 numbers in the top left corner of each solved puzzle
		
		string line;
		while (getline(fileStream, line, '\n')) {		// iterate each line
			if (line.length() == 9 && line.substr(0, 4) != "Grid") {
				
				currentPuzzle.push_back(line);
				
				if (currentPuzzle.size() == 9) {									// Full puzzle
					
					__block sudokuPuzzle _puzzle(currentPuzzle);					// Copy
					
					dispatch_queue_t queue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0ul);
					dispatch_async(queue, ^{
						
						uint64_t solution = 0;
						
						if (sudoku::solve(_puzzle)) {
							solution = stoull(_puzzle[0].substr(0, 3));				// 3 digit number in top left corner of solved puzzle
						}
						
						solutions.push_back(solution);
						
						if (solutions.size() == 50) {
							completion(@(sumOfVector(&solutions)), self.endTime);	// 24702
							return;
						}
						
					});
					
					currentPuzzle.clear();											// Start new puzzle
				}
				
			}
		}
		
	} else {
		
		completion(nil, self.endTime);
		
	}
}

- (void)tdd
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
	
	assert(sudoku::isSolved(puzzleSolved));
	
	sudoku::solve(puzzle);
	assert(sudoku::isSolved(puzzle));
}

@end





