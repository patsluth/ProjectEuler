//
//  main.cpp
//  problem_10
//  Summation of primes
//
//  Created by Pat Sluth on 2015-11-02.
//
//

#include <iostream>

#include "libProjectEuler.h"

using namespace std;





class problem_10 : public problemBase
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




