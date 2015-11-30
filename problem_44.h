//
//  problem_44.h
//  Pentagon numbers
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-02.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//

#include <iostream>

#include "problem_base.h"
#include "libProjectEuler.h"

using namespace std;





class problem_44 : public problem_base
{
    
    string desiredAnswer()
    {
        return "5482660";
    }
    
    void subrun()
    {
        uint64_t minDifference = UINT64_MAX;
        uint64_t k = 0;
        
        while (true){
            
            k++;
            
            uint64_t p_k = pentagonalForN(k);
            
            //if the difference between the prev pentagonal and this one is greater than the minDifference
            //then all previous pentagonals will be as well
            if (pentagonalForN(p_k - 1) > minDifference){
                break;
            }
            
            for (uint64_t j = k - 1; j != 0; j--){
                
                uint64_t p_j = pentagonalForN(j);
                
                uint64_t sum = p_k + p_j;
                uint64_t difference = p_k - p_j;
                
                if (difference >= minDifference){
                    break;
                } else {
                    
                    if (nForPentagonal(sum) != 0 && nForPentagonal(difference) != 0){
                        minDifference = difference;
                    }
                    
                }
                
            }
        }
        
        calculatedAnswer << minDifference;
        
    }
    
    void tdd()
    {
    }
    
};




