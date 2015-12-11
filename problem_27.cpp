//
//  problem_27.h
//  Quadratic primes
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-02.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//

#include "problem_base.h"
#include "libProjectEuler.h"

using namespace std;





class problem_27 : public problem_base
{
    
    string desiredAnswer()
    {
        return "-59231";
    }
    
    void subrun()
    {
        //quadratic in frm n^2 + an + b
        
        pair<uint64_t, int64_t> maxContainer = {0, 0}; //first = # of primes, second = (a * b)
        
        for (int64_t a = -999; a < 1000; a++) {
            
            for (int64_t b = -999; b < 1000; b++) {
                
                uint64_t n = 0;
                
                while (true) {
                    
                    int64_t result = (n * n) + (n * a) + (b);
                    
                    if (result < 0 || !isPrimeFast(result)) {
                        break;
                    }
                    
                    n++;
                    
                }
                
                if (n > maxContainer.first) {
                    maxContainer.first = n;
                    maxContainer.second = (a * b);
                }
                
            }
            
        }
        
        calculatedAnswer << maxContainer.second;
        
    }
    
};




