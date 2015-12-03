//
//  problem_5.h
//  Smallest multiple
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-09-09.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//

#include <iostream>

#include "problem_base.h"
#include "libProjectEuler.h"

using namespace std;





class problem_5 : public problem_base
{
    
    string desiredAnswer()
    {
        return "232792560";
    }
    
    void subrun()
    {
        uint64_t a = 1;
        uint64_t b = 20;
        
        calculatedAnswer << smallestMultipleOfRange(a, b);
    }
    
    static uint64_t smallestMultipleOfRange(uint64_t a, uint64_t b)
    {
        uint64_t m = b;
        
        if (a == 0 || b == 0 || a > b) { //invalid
            return 0;
        }
        
        while (true) {
            
            bool success = true;
            
            for (uint64_t x = a; x <= b; x++) {
                if (m % x != 0) {
                    success = false;
                    break;
                }
            }
            
            if (success) {
                return m;
            }
            
            m += 1;
        }
        
        return 0;
    }
    
};




