//
//  main.cpp
//  problem_6
//  Sum square difference
//
//  Created by Pat Sluth on 2015-09-09.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//

#include <iostream>

#include "libProjectEuler.h"

using namespace std;





class problem_6 : public problemBase
{
    
    string desiredAnswer()
    {
        return "25164150";
    }
    
    void subrun()
    {
        uint64_t sumOfSquares = 0;
        uint64_t sum = 0;
        
        for (uint x = 1; x <= 100; x++){
            sumOfSquares += (x * x);
            sum += x;
        }
        
        uint64_t sumSquared = (sum * sum);
        
        calculatedAnswer << (sumSquared - sumOfSquares);
    }
    
};




