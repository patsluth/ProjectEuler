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

#include "problem_base.h"
#include "libProjectEuler.h"

#import "numberChain.h"

using namespace std;





class problem_95 : public problem_base
{
    
    string desiredAnswer()
    {
        return "14316";
    }
    
    
    
    void subrun()
    {
        numberChain_continueCalculatingFunction continueCalculating = [] (const numberChain *currentChain){
            
            if (currentChain->back() == currentChain->front() || currentChain->back() > 1000000){
                return false;
            } else {
                return true;
            }
            
        };
        
        
        numberChain longest;
        
        for (uint64_t start = 0; start < 1000000; start++){
            
            numberChain cur = numberChain_calculate(start, sumOfProperDivisors(), continueCalculating);
            
            //constraints
            if (cur.back() < 1000000 &&
                cur.back() == cur.front() &&
                cur.size() > longest.size()){
                
                longest = cur;
                
            }
            
        }
        
        calculatedAnswer << longest.back();
        
        
        
        
        
        
        
        
        
        
        
        
//        vector<uint64_t> ttt = properDivisors(12496);
//        
//        uint64_t xxx = 0;
//        for (uint64_t x : ttt){
//            xxx += x;
//        }
//        
//        cout << xxx << endl;
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




