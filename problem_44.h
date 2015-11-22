//
// main.cpp
// problem_44
// Pentagon numbers
//
// Created by Pat Sluth on 2015-11-02.
//
//

#include <iostream>

#include "libProjectEuler.h"

using namespace std;





class problem_44 : public problemBase
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
            
            uint64_t p_k = pentagonalNumberForN(k);
            
            //if the difference between the prev pentagonal and this one is greater than the minDifference
            //then all previous pentagonals will be as well
            if (pentagonalNumberForN(p_k - 1) > minDifference){
                break;
            }
            
            for (uint64_t j = k - 1; j != 0; j--){
                
                uint64_t p_j = pentagonalNumberForN(j);
                
                uint64_t sum = p_k + p_j;
                uint64_t difference = p_k - p_j;
                
                if (difference >= minDifference){
                    break;
                } else {
                    
                    if (nForPentagonalNumber(sum) != 0 && nForPentagonalNumber(difference) != 0){
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




