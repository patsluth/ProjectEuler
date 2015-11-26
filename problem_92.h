//
//  problem_92.h
//  Square digit chains
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-02.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//

#include <iostream>

#include "problem_base.h"
#include "libProjectEuler.h"

#import "numberChain.h"

using namespace std;





class problem_92 : public problem_base
{
    
    string desiredAnswer()
    {
        return "8581146";
    }
    
    void subrun()
    {
        uint64_t x = 0;
        
        numberChain_continueCalculatingFunction continueCalculating = [] (const numberChain *currentChain){
            if (currentChain->back() == 89){ // stop calculating chain at 89
                return false;
            } else {
                return true;
            }
        };
        
        for (uint64_t start = 0; start < 10000000; start++){
            if (numberChain_calculate(start, sumOfSquaresOfDigits(), continueCalculating).back() == 89){
                x++;
            }
        }
        
        calculatedAnswer << x;
    }
    
};




