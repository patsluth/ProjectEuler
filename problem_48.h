//
// problem_48.h
// Self powers
//
// Created by Pat Sluth on 2015-11-02.
//
//

#include <iostream>
#include <string>

#include "InfInt.h"

#include "libProjectEuler.h"

using namespace std;





class problem_48 : public problemBase
{
    
    string desiredAnswer()
    {
        return "9110846700";
    }
    
    void subrun()
    {
        InfInt selfPowerSum = 0;
        
        for (uint x = 1; x <= 1000; x++){
            
            InfInt nextSelfPower = x;
            
            for (uint pow = 1; pow < x; pow++){
                nextSelfPower *= x;
            }
            
            selfPowerSum += nextSelfPower;
        }
        
        string temp = selfPowerSum.toString();
        calculatedAnswer << temp.substr(temp.length() - 10, temp.length() - 1);
        
    }
    
};




