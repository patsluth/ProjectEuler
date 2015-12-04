//
//  problem_37.h
//  Truncatable primes
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-02.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//

#include <iostream>
#include <math.h>

#include "problem_base.h"
#include "libProjectEuler.h"

using namespace std;




class problem_37 : public problem_base
{
    
    string desiredAnswer()
    {
        return "748317";
    }
    
    bool truncatablePrimeLeft(uint64_t i)
    {
        uint64_t iCopy = i;
        uint64_t numberOfDigits = 0;
        
        while (iCopy > 0) { // get number of digits so we can truncate left to right
            numberOfDigits++;
            iCopy /= 10;
        }

        iCopy = i;
        
        while (numberOfDigits > 0) {
            
            if (!isPrimeFast(iCopy)){
                return false;
            }
            
            numberOfDigits--;
            iCopy = iCopy % (int)pow(10, numberOfDigits);
            
        }
        
        return true;
    }
    
    bool truncatablePrimeRight(uint64_t i)
    {
        uint64_t iCopy = i;
        
        while (iCopy > 0) {
            
            if (!isPrimeFast(iCopy)){
                return false;
            }
            
            iCopy /= 10;
            
        }
        
        return true;
    }
    
    void subrun()
    {
        uint64_t sum = 0;
        uint64_t count = 0;
        
        for (uint64_t x = 11; count < 11 ; x++){ // 1 - 7 dont count
            
            if (truncatablePrimeLeft(x) && truncatablePrimeRight(x)){
                count++;
                sum += x;
            }
            
        }
        
        calculatedAnswer << sum;
    }
    
};




