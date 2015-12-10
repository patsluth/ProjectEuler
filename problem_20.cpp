//
//  problem_20.h
//  Factorial digit sum
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-02.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//

#include <iostream>

#include <boost/multiprecision/cpp_int.hpp>

#include "problem_base.h"
#include "libProjectEuler.h"

using namespace std;
using namespace boost::multiprecision;





class problem_20 : public problem_base
{
    
    string desiredAnswer()
    {
        return "648";
    }
    
    void subrun()
    {
        cpp_int fact = 100;
        
        for (uint64_t x = 2; x <= 100; x++) {
            fact *= x;
        }
        
        cpp_int factDigitSum = 0;
        
        while (fact > 0){
            factDigitSum += fact % 10;
            fact /= 10;
        }

        calculatedAnswer << factDigitSum;
    }
    
};




