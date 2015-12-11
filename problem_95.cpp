//
//  problem_95.h
//  Amicable chains
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-02.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//

#include <math.h>

#include "problem_base.h"
#include "libProjectEuler.h"

#include "numberChain.h"

using namespace std;





class problem_95 : public problem_base
{
    
    string desiredAnswer()
    {
        return "14316";
    }
    
    void subrun()
    {
        numberChain_continueCalculatingFunction continueCalculating = [] (const numberChain *currentChain) {
            
            if (currentChain->back() == currentChain->front() || currentChain->back() > 1000000) {
                return false;
            } else {
                return true;
            }
            
        };
        
        
        numberChain longest;
        
        for (uint64_t start = 0; start < 1000000; start++) {
            
            numberChain cur = numberChain_calculate(start, sumOfProperDivisors_Chain(), continueCalculating);
            
            //constraints
            if (cur.back() < 1000000 &&
                cur.back() == cur.front() &&
                cur.size() > longest.size()) {
                
                longest = cur;
                
            }
            
        }
        
        calculatedAnswer << longest.back();
        
    }
    
    numberChain_nextNumberFunction sumOfProperDivisors_Chain()
    {
        return [] (const uint64_t *currentEndOfChain) {
            
            uint64_t currentEndOfChain_Copy = *currentEndOfChain;
            return sumOfVector(calculateProperDivisors(currentEndOfChain_Copy));
            
        };
    }
    
};




