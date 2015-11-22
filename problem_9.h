//
//  main.cpp
//  problem_9
//  Special Pythagorean triplet
//
//  Created by Pat Sluth on 2015-11-02.
//
//

#include <iostream>

#include "libProjectEuler.h"

using namespace std;





class problem_9 : public problemBase
{
    
    string desiredAnswer()
    {
        return "31875000";
    }
    
    void subrun()
    {
        for (uint64_t x = 1; x < 1000; x++){
            for (uint64_t y = x + 1; y < 1000; y++){
                
                uint64_t z = 1000 - x - y;
                
                if ( (x * x) + (y * y) == (z * z) ){
                    
                    //printf("The pythagorean triplet for [a + b + c = 1000] is [(%llu)^2 + (%llu)^2 = (%llu)^2]\n", x, y, z);
                    calculatedAnswer << (x * y * z);
                    return;
                    
                }
                
            }
        }
    }
    
};




