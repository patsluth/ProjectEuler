//
//  problem_81.h
//  Path sum: three ways
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-02.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//

using namespace std;





class problem_82 : public problem_base
{
    
    string desiredAnswer()
    {
        return "260324";
    }
    
    void subrun()
    {
        ifstream fileStream = readFile("p082_matrix.txt");
        
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
            
            calculatedAnswer << matrix[0][0];
            
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
        
        assert(matrix[0][0] == 994);
        
    }
    
};




