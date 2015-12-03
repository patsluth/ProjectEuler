//
//  problem_52.h
//  Permuted multiples
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-02.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//

#include <iostream>
#include <assert.h>

#include "problem_base.h"
#include "libProjectEuler.h"

using namespace std;





class problem_52 : public problem_base
{
    
    string desiredAnswer()
    {
        return "142857";
    }
    
    bool intsContainSameDigits(uint64_t a, uint64_t b)
    {
        vector<uint64_t> aDigits;
        vector<uint64_t> bDigits;
        
        while (a != 0) {
            aDigits.push_back(a % 10);
            a /= 10;
        }
        
        while (b != 0) {
            bDigits.push_back(b % 10);
            b /= 10;
        }
        
        
        while (aDigits.size() == bDigits.size() && !aDigits.empty()) {
            
            uint64_t aDigit = aDigits.back();
            aDigits.pop_back();
            
            for(vector<uint64_t>::iterator bItr = bDigits.begin(); bItr != bDigits.end(); ++bItr) {
                
                if (aDigit == *bItr) {
                    bDigits.erase(bItr);
                    break;
                }
                
            }
            
        }
        
        if (aDigits.empty() && bDigits.empty()) {
            return true;
        }
        
        return false;
    }
    
    void subrun()
    {
        for (uint64_t x = 1; ; x++) {
            
            //true for x*2 to x*6
            if (intsContainSameDigits(x, x * 2)) {
                if (intsContainSameDigits(x, x * 3)) {
                    if (intsContainSameDigits(x, x * 4)) {
                        if (intsContainSameDigits(x, x * 5)) {
                            if (intsContainSameDigits(x, x * 6)) {
                                calculatedAnswer << x;
                                return;
                            }
                        }
                    }
                }
            }
        }
        
    }
    
    void tdd()
    {
        assert(intsContainSameDigits(12345, 54321));
        assert(intsContainSameDigits(987654321, 654398721));
        assert(intsContainSameDigits(3, 65) == false);
    }
    
};




