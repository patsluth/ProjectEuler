//
//  problem_10.h
//  Summation of primes
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-02.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//

#include <iostream>

#include "problem_base.h"
#include "libProjectEuler.h"

using namespace std;





class problem_10 : public problem_base
{
    
    string desiredAnswer()
    {
        return "142913828922";
    }
    
    void subrun()
    {
        uint64_t primeLimit = 2000000;
        uint64_t number = 2;
        uint64_t sum = 0;
        
        while (number < primeLimit){
            
            if (isPrimeFast(number)){
                sum += number;
            }
            
            number++;
            
        }
        
        calculatedAnswer << sum;
    }
    
};




