//
//  problem_95.h
//  Amicable chains
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-02.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//

#include <iostream>
#include <math.h>

#include "libProjectEuler.h"

using namespace std;





class problem_95 : public problemBase
{
    
    string desiredAnswer()
    {
        return "14316";
    }
    
    void subrun()
    {
//        uint64_t x = 0;
//        
//        chain_ShouldContinueFunction shouldContinueFunction = [] (const numberChain *currentChain){
//            if (currentChain->size() > 60){ // stop calculating chain with 60 items
//                return false;
//            } else {
//                return true;
//            }
//        };
//        
//        for (uint64_t start = 0; start < 1000000; start++){
//            //+1 because the last term is guaranteed to be a repeated term
//            if (chain_digitFactorial(start, shouldContinueFunction).size() == 60 + 1){
//                x++;
//            }
//        }
//        
//        calculatedAnswer << x;
        
    }
    
};




