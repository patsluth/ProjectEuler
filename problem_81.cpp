//
//  problem_81.h
//  Path sum: two ways
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-02.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//

#include <fstream>


using namespace std;





class problem_81 : public problem_base
{
    
    string desiredAnswer()
    {
        return "427337";
    }
    
    void subrun()
    {
        string file = "p081_matrix.txt";
        ifstream fileStream(file);
        
        
        if (fileStream) {
            
            vector<vector<uint64_t>> matrix;
            
            string line;

            while (getline(fileStream, line, '\n')) { //iterate file line by line
                
                istringstream buf(line);
                istream_iterator<uint64_t> beg(buf), end;
                vector<uint64_t> row(beg, end);
                
                matrix.push_back(row);
                
            }
            
            for (auto row : matrix) { //make sure its a square
                assert(matrix.size() == row.size());
            }
            
            
            for (int64_t x = matrix.size() - 2; x >= 0; x--) {
                matrix[matrix.size() - 1][x] += matrix[matrix.size() - 1][x + 1];
                matrix[x][matrix.size() - 1] += matrix[x + 1][matrix.size() - 1];
            }
            
            for (int64_t x = matrix.size() - 2; x >= 0; x--) {
                for (int64_t y = matrix.size() - 2; y >= 0; y--) {
                    matrix[x][y] += min(matrix[x + 1][y], matrix[x][y + 1]);
                }
            }
            
            
            calculatedAnswer << matrix[0][0];
            
            
        } else {
            
            fprintf(stderr, "Error reading %s\n", file.c_str());
            
        }
    }
    
    
    
    
    
    void tdd()
    {
        vector<vector<uint64_t>> matrix =
        {
            {131, 673, 234, 103, 18},
            {201, 96, 342, 965, 150},
            {630, 803, 746, 422, 111},
            {537, 699, 497, 121, 956},
            {805, 732, 524, 37, 331}
        };
        
        for (int64_t x = matrix.size() - 2; x >= 0; x--) {
            matrix[matrix.size() - 1][x] += matrix[matrix.size() - 1][x + 1];
            matrix[x][matrix.size() - 1] += matrix[x + 1][matrix.size() - 1];
        }
        
        for (int64_t x = matrix.size() - 2; x >= 0; x--) {
            for (int64_t y = matrix.size() - 2; y >= 0; y--) {
                matrix[x][y] += min(matrix[x + 1][y], matrix[x][y + 1]);
            }
        }
        
        assert(matrix[0][0] == 2427);
        
    }
    
};




