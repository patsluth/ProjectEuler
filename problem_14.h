//
//  main.cpp
//  problem_14
//  Longest Collatz sequence
//
//  Created by Pat Sluth on 2015-11-02.
//
//

#include <iostream>
#include <vector>

#include "libProjectEuler.h"

using namespace std;





class problem_14 : public problemBase
{
    
    string desiredAnswer()
    {
        return "837799";
    }
    
    void subrun()
    {
        vector<uint64_t> greatestSequence;
        
        for (uint64_t x = 1; x < 1000000; x++){
            
            vector<uint64_t> currentSequence;
            currentSequence.push_back(x);
            
            while (currentSequence.back() != 1){
                currentSequence.push_back(nextCollatzInt(currentSequence.back()));
            }
            
            if (currentSequence.size() > greatestSequence.size()){
                greatestSequence = currentSequence;
            }
            
        }
        
        calculatedAnswer << greatestSequence.front();
    }
    
};




