//
//  problem_48.h
//  Self powers
//  ProjectEuler
//
//  Created by Pat Sluth on 2015-11-02.
//  Copyright (c) 2015 Pat Sluth. All rights reserved.
//

#include <iostream>
#include <string>

#include <boost/multiprecision/cpp_int.hpp>

#include "libProjectEuler.h"

using namespace std;
using namespace boost::multiprecision;





class problem_48 : public problemBase
{
    
    string desiredAnswer()
    {
        return "9110846700";
    }
    
    void subrun()
    {
        cpp_int selfPowerSum = 0;
        
        for (uint x = 1; x <= 1000; x++){
            
            cpp_int nextSelfPower = x;
            
            for (uint pow = 1; pow < x; pow++){
                nextSelfPower *= x;
            }
            
            selfPowerSum += nextSelfPower;
        }
        
        string temp = selfPowerSum.str();
        calculatedAnswer << temp.substr(temp.size() - 10, temp.size() - 1);
        
    }
    
};




