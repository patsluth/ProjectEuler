//
//  problem_2.h
//  Even Fibonacci Numbers
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-09-09.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//

#include <iostream>

#include "problem_base.h"
#include "libProjectEuler.h"





//TODO: move fib to lib
class problem_2 : public problem_base
{
    
    string desiredAnswer()
    {
        return "4613732";
    }
    
    void subrun()
    {
        int sum = 0;
        
        int previousFib = 1;
        int currentFib = 1;
        
        while (currentFib <= 4000000) {
            
            //process current fib
            if (currentFib % 2 == 0){ //even
                sum += currentFib;
            }
            
            int temp = previousFib;
            previousFib = currentFib;
            currentFib = currentFib + temp;
            
        }
        
        calculatedAnswer << sum;
    }
    
};




