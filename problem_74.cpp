//
//  problem_74.h
//  Digit factorial chains
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-02.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//

#include <iostream>

#include "problem_base.h"

#include "numberChain.h"

using namespace std;





class problem_74 : public problem_base
{
    
    string desiredAnswer()
    {
        return "402";
    }
    
    void subrun()
    {
        uint64_t x = 0;
        
        numberChain_continueCalculatingFunction continueCalculating = [] (const numberChain *currentChain) {
            if (currentChain->size() > 60) { // stop calculating chain with 60 items
                return false;
            } else {
                return true;
            }
        };
        
        for (uint64_t start = 0; start < 1000000; start++) {
            //+1 because the last term is guaranteed to be a repeated term
            if (numberChain_calculate(start, sumOfFactorialOfDigits_Chain(), continueCalculating).size() == 60 + 1) {
                x++;
            }
        }
        
        calculatedAnswer << x;
        
    }
    
    numberChain_nextNumberFunction sumOfFactorialOfDigits_Chain()
    {
        return [] (const uint64_t *currentEndOfChain) {
            
            uint64_t nextEndOfChain = 0;
            uint64_t currentEndOfChain_Copy = *currentEndOfChain;
            
            while (currentEndOfChain_Copy != 0) {
                
                nextEndOfChain += factorial(currentEndOfChain_Copy % 10);
                currentEndOfChain_Copy /= 10;
                
            }
            
            return nextEndOfChain;
            
        };
    }
    
};




