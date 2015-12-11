//
//  problem_46.h
//  Goldbach's other conjecture
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-02.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//

#include <math.h>

#include "problem_base.h"
#include "libProjectEuler.h"

using namespace std;





class problem_46 : public problem_base
{
    
    string desiredAnswer()
    {
        return "5777";
    }
    
    void subrun()
    {
        uint64_t n = 3;
        
        while (true) {
            
            if (!isPrimeFast(n)) {
                
                bool success = false;
                
                for (uint64_t x = 1; x < n; x++) {
                    if (isPrimeFast(x)) {
                        
                        uint64_t difference = n - x;
                        
                        if (difference % 2 == 0) {
                            
                            uint64_t possibleSquare = difference / 2;
                            float squareRoot = sqrt(possibleSquare);
                            
                            if ( fmod(squareRoot, (uint64_t)squareRoot) == 0) { // is a square
                                success = true;
                            }
                            
                        }
                        
                    }
                }
                
                if (!success) { //this odd composite is not the sum of a prime and 2 * a square
                    calculatedAnswer << n;
                    return;
                }
                
            }
            
            n += 2; //odd
        }
        
    }
    
    void tdd()
    {
        
    }
    
};




