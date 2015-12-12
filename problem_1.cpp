//
//  problem_1.h
//  Multiples of 3 and 5
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-09-09.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//


using namespace std;





class problem_1 : public problem_base
{
    
    string desiredAnswer()
    {
        return "233168";
    }
    
    void subrun()
    {
        int sum = 0;
        
        for (int x = 0; x < 1000; x++) {
            if (x % 3 == 0 || x % 5 == 0) {
                sum += x;
            }
        }
        
        calculatedAnswer << sum;
    }
    
};




