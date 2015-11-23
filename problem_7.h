//
//  problem_7.h
//  Largest Prime Factor
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-02.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//

#include <iostream>
#include <vector>

#include "libProjectEuler.h"

using namespace std;





class problem_7 : public problemBase
{
    
    string desiredAnswer()
    {
        return "104743";
    }
    
    void subrun()
    {
        uint64_t number = 2;
        vector<uint64_t> primeNumbers;
        
        while (primeNumbers.size() < 10001){
            
            if (isPrime(factorInteger(number))){
                primeNumbers.push_back(number);
            }
            
            number++;
            
        }
        
        if (!primeNumbers.empty()){
            calculatedAnswer << primeNumbers.back();
        }
    }
    
    static bool isPrime(factor f)
    {
        return (f.x == 0 && f.y == 0);
    }
    
};




