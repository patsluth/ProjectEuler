//
//  problem_23.h
//  Non-abundant sums
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-02.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//

#include <set>

#include "problem_base.h"
#include "libProjectEuler.h"





using namespace std;





class problem_23 : public problem_base
{
    
    string desiredAnswer()
    {
        return "4179871";
    }
    
    void subrun()
    {
        set<uint64_t> abundantNumberCache;
        
        for (uint64_t aN = 1; aN < 28123; aN++) {
            if (getNumberType(aN) == NumberType_Abundant) {
                abundantNumberCache.insert(aN);
            }
        }
        
        uint64_t sum = 0;
        
        for (uint64_t x = 1; x < 28123; x++) { //check all integers less than 28123 (it is proven all ints > 28123 can be written as sum of 2 abundants)
            
            bool isSumOfTwoAbundantNumbers = false;
            
            for (uint64_t aN : abundantNumberCache) { //check all abundant numbers less than the current int
                
                if (aN >= x) {
                    break;
                }
                
                uint64_t difference = x - aN;
                
                // if the difference of the current number and the current abundant number is an abuntant number, we passed the test
                if (abundantNumberCache.count(difference) != 0) {
                    isSumOfTwoAbundantNumbers = true;
                    break;
                }
                
            }
            
            if (!isSumOfTwoAbundantNumbers) {
                sum += x;
            }
            
        }
        
        calculatedAnswer << sum;
    }
    
};

