//
//  problem_28.h
//  Number spiral diagonals
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-02.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//


using namespace std;





class problem_28 : public problem_base
{

    string desiredAnswer()
    {
        return "669171001";
    }

    void subrun()
    {
        uint64_t sum = 1;
        uint64_t cur = 1;
        
        for (uint64_t x = 3; x <= 1001; x += 2) {
            for (uint64_t y = 0; y < 4; y++) { //  calculate each corner
                
                //  this will give us the current corner value
                cur = cur + (x - 1);
                sum += cur;
                
            }
            cout << endl;
        }
        
        calculatedAnswer << sum;
    }

};




