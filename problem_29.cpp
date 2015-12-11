//
//  problem_29.h
//  Distinct powers
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-02.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//

#include <set>

#include "problem_base.h"
#include "libProjectEuler.h"

using namespace std;
using namespace boost::multiprecision;





class problem_29 : public problem_base
{

    string desiredAnswer()
    {
        return "9183";
    }

    void subrun()
    {
        set<cpp_int> distinctTerms;
        
        for (cpp_int a = 2; a <= 100; a++) {
            for (uint64_t b = 2; b <= 100; b++) {
                distinctTerms.insert( pow(a, b) );
            }
        }
        
        calculatedAnswer << distinctTerms.size();
    }

};




