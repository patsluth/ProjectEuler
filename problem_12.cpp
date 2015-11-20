//
//  main.cpp
//  problem_12
//  Highly divisible triangular number
//
//  Created by Pat Sluth on 2015-11-02.
//
//

#include <iostream>

#include "libProjectEuler.h"

using namespace std;





class problem_12 : public problemBase
{
    
    string desiredAnswer()
    {
        return "76576500";
    }
    
    void subrun()
    {
        uint64_t triangleNumber = 1;
        uint64_t triangleValue = 1;
        
        while (true){
            
            triangleNumber++;
            triangleValue += triangleNumber;
            
            if (numberOfDivisors(triangleValue) > 500){
                calculatedAnswer << triangleValue;
                return;
            }
            
        }
    }
    
};




