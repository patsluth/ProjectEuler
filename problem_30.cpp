//
//  problem_30.h
//  Digit fifth powers
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-02.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//

#include <math.h>

#include "problem_base.h"
#include "libProjectEuler.h"

using namespace std;





class problem_30 : public problem_base
{
    
    string desiredAnswer()
    {
        return "443839";
    }
    
    void subrun()
    {
        uint64_t result = 0;
        
        for (uint64_t x = 0; x < 1000000; x++) {
            if (intEqualsSumOfDigitsToPower(x, 5)) {
                result += x;
            }
        }
        
        calculatedAnswer << result;
    }
    
    /**
     *  If the sum of each digit of i to the power supplied equals i
     *  return true
     *
     *  @param i     base
     *  @param power exponent
     *
     *  @return bool
     */
    static bool intEqualsSumOfDigitsToPower(uint64_t i, uint64_t power)
    {
        if (i == 0 || i == 1) {
            return false;
        }
        
        uint64_t iCopy = i;
        uint64_t sumOfDigitsPower = 0;
        
        while (iCopy > 0) {
            
            uint64_t digit = iCopy % 10;
            
            sumOfDigitsPower += powl(digit, power);
            
            iCopy /= 10;
            
        }
        
        return (sumOfDigitsPower == i);
    }
    
};




