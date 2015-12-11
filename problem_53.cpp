//
//  problem_53.h
//  Combinatoric selections
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-02.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//

#include "problem_base.h"
#include "libProjectEuler.h"

using namespace std;
using namespace boost::multiprecision;





class problem_53 : public problem_base
{

    string desiredAnswer()
    {
        return "4075";
    }
    
    void subrun()
    {
        uint64_t nCrCount = 0; //number of nCr combos over 1 million
        
        for (uint64_t n = 23; n <= 100; n++) { // we are given the first one doesnt occur until n = 23
            for (uint64_t r = 1; r <= n; r++) {
                
                cpp_int nFact = cppint_factorial(n);
                cpp_int rFact = cppint_factorial(r);
                
                cpp_int n_minus_rFact = cppint_factorial(n - r);
                
                cpp_int result = nFact / ( rFact * n_minus_rFact );
                
                if (result > 1000000){
                    nCrCount++;
                }
                
            }
        }
        
        calculatedAnswer << nCrCount;
    }
    
};




